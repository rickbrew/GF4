using System;

namespace GoldenFluteIV.Engine;

/// <summary>
/// 100×100 world map, procedurally generated to match FUN_1000_76f9
/// (InitializeWorldMap in the original Pascal binary).
///
/// Coordinate convention: both X (column) and Y (row) are 1-based (1..100),
/// matching the original game's playerX / playerY globals.
///
/// On-disk layout (30,000 bytes per save slot, row-major):
///   cell(row, col) terrain  = buf[row*300 + col*3 + 0]
///   cell(row, col) encounter = buf[row*300 + col*3 + 1]  (little-endian word)
/// </summary>
public sealed class WorldMap
{
    public const int Width  = 100;
    public const int Height = 100;

    // Stored [row, col], both 0-based internally.
    private readonly MapCell[,] _cells = new MapCell[Height, Width];

    // ── Public accessors (1-based X/Y) ───────────────────────────────────────

    public ref MapCell Cell(int x, int y)  => ref _cells[y - 1, x - 1];

    public bool IsWall(int x, int y)
    {
        if (x < 1 || x > Width || y < 1 || y > Height) return true;
        return _cells[y - 1, x - 1].IsWall;
    }

    // ── Procedural generation ─────────────────────────────────────────────────

    /// <summary>
    /// Generate the map from scratch. Mirrors the logic of FUN_1000_76f9.
    /// </summary>
    public static WorldMap Generate(Random rng)
    {
        var map = new WorldMap();
        map.FillDefaults();
        map.BuildBorderWalls();
        map.ScatterTerrainPatches(rng);
        map.PlaceTypeFourClusters(rng);
        map.PlaceAllEncounters(rng);
        return map;
    }

    // ── Serialisation ─────────────────────────────────────────────────────────

    /// <summary>
    /// Serialise to the 30,000-byte format used in SAVEGAME.DAT slot files.
    /// </summary>
    public byte[] ToSaveBytes()
    {
        var buf = new byte[Height * Width * 3];
        for (int y = 0; y < Height; y++)
        for (int x = 0; x < Width; x++)
        {
            int off = y * 300 + x * 3;
            ref var c = ref _cells[y, x];
            buf[off    ] = c.Terrain;
            buf[off + 1] = (byte)( c.Encounter        & 0xff);
            buf[off + 2] = (byte)((c.Encounter >> 8)  & 0xff);
        }
        return buf;
    }

    /// <summary>Load from the 30,000-byte format.</summary>
    public static WorldMap FromSaveBytes(byte[] buf)
    {
        if (buf.Length < Height * Width * 3)
            throw new ArgumentException("Buffer too short for world map");
        var map = new WorldMap();
        for (int y = 0; y < Height; y++)
        for (int x = 0; x < Width; x++)
        {
            int off = y * 300 + x * 3;
            map._cells[y, x] = new MapCell
            {
                Terrain   = buf[off],
                Encounter = (short)(buf[off + 1] | (buf[off + 2] << 8))
            };
        }
        return map;
    }

    // ── Private generation steps ──────────────────────────────────────────────

    private void FillDefaults()
    {
        for (int y = 0; y < Height; y++)
        for (int x = 0; x < Width; x++)
            _cells[y, x] = new MapCell { Terrain = 3, Encounter = 0 };
    }

    /// <summary>
    /// Border layout (0-based indices):
    ///   Row 0, row 99          → terrain 8 (all columns)
    ///   Cols 0-8, cols 91-99   → terrain 8 (all rows)
    /// This matches the original: rows 1 and last, cols 1-9 and 91-99 (1-based).
    /// </summary>
    private void BuildBorderWalls()
    {
        for (int x = 0; x < Width; x++)
        {
            _cells[0,          x].Terrain = 8;
            _cells[Height - 1, x].Terrain = 8;
        }
        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < 9; x++)         _cells[y, x].Terrain = 8;
            for (int x = 91; x < Width; x++)    _cells[y, x].Terrain = 8;
        }
    }

    private void ScatterTerrainPatches(Random rng)
    {
        // Random patches of terrain types 1, 2, 4 in the interior
        Scatter(rng, 1, 80);
        Scatter(rng, 2, 80);
        Scatter(rng, 4, 80);
    }

    private void Scatter(Random rng, byte terrain, int count)
    {
        for (int i = 0; i < count; i++)
        {
            int x = rng.Next(9, 91);
            int y = rng.Next(1, 99);
            if (!_cells[y, x].IsWall)
                _cells[y, x].Terrain = terrain;
        }
    }

    /// <summary>
    /// 25 random 7×7 clusters of terrain type 4 (open clearings / plains).
    /// Original places these with a ±3 radius around a random centre.
    /// </summary>
    private void PlaceTypeFourClusters(Random rng)
    {
        for (int c = 0; c < 25; c++)
        {
            int cx = rng.Next(13, 88);
            int cy = rng.Next(4,  96);
            for (int dy = -3; dy <= 3; dy++)
            for (int dx = -3; dx <= 3; dx++)
            {
                int x = cx + dx;
                int y = cy + dy;
                if (x >= 9 && x < 91 && y >= 1 && y < 99 && !_cells[y, x].IsWall)
                    _cells[y, x].Terrain = 4;
            }
        }
    }

    /// <summary>
    /// Encounter placement order from game_state_machine.md (higher-priority
    /// encounters placed first so they're not overwritten).
    /// Total = 736 encounters across 10,000 cells (~7% density).
    /// </summary>
    private static readonly (short Code, int Count)[] EncounterTable =
    [
        (8,   1),   // final boss  — exactly one
        (9,  15),   // shop entrance
        (10, 10),   // gold pickup
        (7,  50),   // strong monster
        (6, 100),   // mid-tier
        (5, 100),   // mid-tier
        (4, 100),   // mid-tier
        (3,  75),   // weak
        (2, 110),   // weakest
        (1, 175),   // weakest
    ];

    private void PlaceAllEncounters(Random rng)
    {
        foreach (var (code, count) in EncounterTable)
        {
            int placed = 0, attempts = 0, maxAttempts = count * 30;
            while (placed < count && attempts < maxAttempts)
            {
                attempts++;
                int x = rng.Next(10, 90);
                int y = rng.Next(2, 98);
                ref var cell = ref _cells[y, x];
                if (!cell.IsWall && cell.Encounter == 0)
                {
                    cell.Encounter = code;
                    placed++;
                }
            }
        }
    }
}

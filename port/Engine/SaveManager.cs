using System;
using System.IO;
using System.Security;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Reads and writes save-game slot files.
///
/// File layout (30,046 bytes per slot):
///   bytes    0..29999  — WorldMap  (100×100 × 3 bytes, row-major)
///   bytes 30000..30045 — PlayerState (46 bytes)
///
/// Files are stored next to the executable as SAVE1.DAT, SAVE2.DAT, SAVE3.DAT,
/// mirroring the original DOS game's convention of saving in the game directory.
/// </summary>
public static class SaveManager
{
    public const int SlotCount = 3;

    private const int MapBytes    = WorldMap.Height * WorldMap.Width * 3;  // 30,000
    private const int PlayerBytes = 46;
    private const int TotalBytes  = MapBytes + PlayerBytes;                 // 30,046

    private static string SlotPath(int slot) =>
        Path.Combine(AppContext.BaseDirectory, $"SAVE{slot}.DAT");

    /// <summary>Returns true if a save file exists for the given slot (1–3).</summary>
    public static bool SlotExists(int slot) =>
        slot is >= 1 and <= SlotCount && File.Exists(SlotPath(slot));

    /// <summary>
    /// Save the current game state to a slot (1–3).
    /// Returns false if the write fails (e.g. disk full or permission denied).
    ///
    /// Writes are atomic: data is staged into SAVE{n}.DAT.tmp first, then renamed
    /// over the real slot file, so an interrupted save never leaves a torn slot
    /// half-written on disk.
    /// </summary>
    public static bool Save(int slot, PlayerState player, WorldMap map)
    {
        if (slot is < 1 or > SlotCount) return false;

        string finalPath = SlotPath(slot);
        string tmpPath   = finalPath + ".tmp";

        try
        {
            var buf = new byte[TotalBytes];
            map.ToSaveBytes().CopyTo(buf, 0);
            player.ToSaveBytes().CopyTo(buf, MapBytes);

            File.WriteAllBytes(tmpPath, buf);
            File.Move(tmpPath, finalPath, overwrite: true);
            return true;
        }
        catch (Exception ex) when (ex is IOException
                                      or UnauthorizedAccessException
                                      or SecurityException
                                      or NotSupportedException)
        {
            // Clean up the temp file if the rename failed — leaving it would
            // confuse the next save attempt and waste disk.
            try { if (File.Exists(tmpPath)) File.Delete(tmpPath); }
            catch (Exception cleanup) when (cleanup is IOException
                                              or UnauthorizedAccessException
                                              or SecurityException) { /* swallow */ }
            return false;
        }
    }

    /// <summary>
    /// Load from a slot (1–3).
    /// Returns null if the slot is empty, the file is truncated, or deserialization fails.
    /// </summary>
    public static (PlayerState Player, WorldMap Map)? Load(int slot)
    {
        if (slot is < 1 or > SlotCount) return null;

        string path = SlotPath(slot);
        if (!File.Exists(path)) return null;

        byte[] buf;
        try   { buf = File.ReadAllBytes(path); }
        catch (Exception ex) when (ex is IOException
                                      or UnauthorizedAccessException
                                      or SecurityException) { return null; }

        if (buf.Length < TotalBytes) return null;

        try
        {
            var map    = WorldMap.FromSaveBytes(buf[..MapBytes]);
            var player = PlayerState.FromSaveBytes(buf.AsSpan(MapBytes, PlayerBytes));
            return (player, map);
        }
        catch (Exception ex) when (ex is ArgumentException
                                      or InvalidDataException
                                      or IndexOutOfRangeException) { return null; }
    }

    /// <summary>
    /// Read only the <see cref="PlayerState"/> header from a slot without loading
    /// the full 30 KB map — used to populate the save/load slot list cheaply.
    /// Returns null if the slot is empty or unreadable.
    /// </summary>
    public static PlayerState? PeekPlayer(int slot)
    {
        if (slot is < 1 or > SlotCount) return null;

        string path = SlotPath(slot);
        if (!File.Exists(path)) return null;

        try
        {
            using var f = File.OpenRead(path);
            if (f.Length < TotalBytes) return null;
            f.Seek(MapBytes, SeekOrigin.Begin);

            Span<byte> buf = stackalloc byte[PlayerBytes];
            if (f.Read(buf) < PlayerBytes) return null;

            return PlayerState.FromSaveBytes(buf);
        }
        catch (Exception ex) when (ex is IOException
                                      or UnauthorizedAccessException
                                      or SecurityException
                                      or ArgumentException) { return null; }
    }
}

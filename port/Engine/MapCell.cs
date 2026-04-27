namespace GoldenFluteIV.Engine;

/// <summary>
/// One cell in the 100×100 world map.  Matches the original 3-byte on-disk format:
///   byte 0  = Terrain  (at DGROUP base + row*300 + col*3 + 0x10cd)
///   word 1  = Encounter (at                            + 0x10ce)
///
/// Terrain codes
///   Passable : 2, 3, 4
///   Wall     : 1, 5, 6, 7, 8
///   (terrain 1 is treated as a wall in the 687f collision code; it is NOT passable
///    despite what an earlier reading of the map doc suggested.)
///
/// Encounter codes
///   0        = empty
///   1-2      = weakest monsters (175 + 110 placed)
///   3        = weak monster (75)
///   4-6      = mid-tier monsters (100 each)
///   7        = strong monster (50)
///   8        = FINAL BOSS (exactly 1)
///   9        = special / shop entrance (15)
///   10       = gold pickup (+50 gold, clears itself on pickup) (10)
/// </summary>
public struct MapCell
{
    public byte  Terrain;    // 1-8
    public short Encounter;  // 0-10

    public readonly bool IsWall        => Terrain == 1 || Terrain >= 5;
    public readonly bool IsPassable    => !IsWall;
    public readonly bool HasEncounter  => Encounter != 0;
    public readonly bool IsMonster     => Encounter is >= 1 and <= 7;
    public readonly bool IsBoss        => Encounter == 8;
    public readonly bool IsShop        => Encounter == 9;
    public readonly bool IsGold        => Encounter == 10;
}

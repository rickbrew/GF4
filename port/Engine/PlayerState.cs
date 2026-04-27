using System;

namespace GoldenFluteIV.Engine;

/// <summary>
/// The 40-byte player stat record that lives at DGROUP:0x11d4..0x11fb in the
/// original Pascal binary, plus the position/class globals that surround it.
/// All initial values are taken verbatim from FUN_1000_1ec9 (InitClassStats).
/// </summary>
public sealed class PlayerState
{
    // ── Combat stats (0x11d4..0x11eb) ────────────────────────────────────────
    public int HP           { get; set; }  // 0x11d4  current hit points (max 24 = 0x18)
    public int AttackLevel  { get; set; }  // 0x11d6
    public int AttackDie    { get; set; }  // 0x11d8
    public int DefendLevel  { get; set; }  // 0x11da
    public int DefendDie    { get; set; }  // 0x11dc
    public int Stat6        { get; set; }  // 0x11de  (Strength?)
    public int Stat7        { get; set; }  // 0x11e0  (Dexterity?)
    public int Gold         { get; set; }  // 0x11e2
    public int MP           { get; set; }  // 0x11e4  magic points (max 24 = 0x18)
    public int MagicXP      { get; set; }  // 0x11e6
    public int Stat10       { get; set; }  // 0x11e8
    public int Stat11       { get; set; }  // 0x11ea

    // ── Inventory flags (0x11ec..0x11f7, 12 bytes) ───────────────────────────
    public bool Inv0  { get; set; }  // 0x11ec  Fighter starts with this (Sword?)
    public bool Inv1  { get; set; }  // 0x11ed
    public bool Inv2  { get; set; }  // 0x11ee  Knife (Mage & Thief start with it)
    public bool Inv3  { get; set; }  // 0x11ef
    public bool Inv4  { get; set; }  // 0x11f0
    public bool Inv5  { get; set; }  // 0x11f1  Fighter starts with this (Shield?)
    public bool Inv6  { get; set; }  // 0x11f2
    public bool Inv7  { get; set; }  // 0x11f3
    public bool Inv8  { get; set; }  // 0x11f4
    public bool Inv9  { get; set; }  // 0x11f5
    public bool Inv10 { get; set; }  // 0x11f6  Mage starts with this (Spell book?)
    public bool Inv11 { get; set; }  // 0x11f7

    // ── Consumables (0x11f8..0x11fb) ─────────────────────────────────────────
    public int HealingPotions { get; set; }  // 0x11f8
    public int MagicPotions   { get; set; }  // 0x11fa

    // ── Position / class (globals adjacent to the stat block) ────────────────
    public int Class  { get; set; }  // 0x11d3  1=Fighter, 2=Mage, 3=Thief
    public int X      { get; set; }  // 0x11cb  1-100 (column)
    public int Y      { get; set; }  // 0x11cd  1-100 (row)
    public int Facing { get; set; }  // 0x445   1=Left, 2=Right, 3=Up, 4=Down

    // ── Derived helpers ───────────────────────────────────────────────────────
    public string ClassName => Class switch { 1 => "Fighter", 2 => "Mage", 3 => "Thief", _ => "?" };

    public const int MaxHP = 24;  // 0x18 — cap enforced by original game
    public const int MaxMP = 24;

    // ── Per-class constructors (values from FUN_1000_1ec9 decomp) ─────────────

    public static PlayerState CreateFighter() => new()
    {
        Class = 1,
        HP = 8, AttackLevel = 5, AttackDie = 3, DefendLevel = 2, DefendDie = 4,
        Stat6 = 3, Stat7 = 2,
        Gold = 50,      // 0x32
        MP = 0, MagicXP = 0, Stat10 = 6, Stat11 = 4,
        Inv0 = true, Inv5 = true,           // Sword + Shield
        HealingPotions = 1, MagicPotions = 0,
        X = 50, Y = 50, Facing = 4          // centre of map, facing down
    };

    public static PlayerState CreateMage() => new()
    {
        Class = 2,
        HP = 5, AttackLevel = 3, AttackDie = 1, DefendLevel = 4, DefendDie = 2,
        Stat6 = 1, Stat7 = 4,
        Gold = 50,      // 0x32
        MP = 10, MagicXP = 1, Stat10 = 2, Stat11 = 8,
        Inv2 = true, Inv10 = true,           // Knife + Spell book
        HealingPotions = 1, MagicPotions = 1,
        X = 50, Y = 50, Facing = 4
    };

    public static PlayerState CreateThief() => new()
    {
        Class = 3,
        HP = 6, AttackLevel = 6, AttackDie = 2, DefendLevel = 2, DefendDie = 4,
        Stat6 = 2, Stat7 = 2,
        Gold = 75,      // 0x4b
        MP = 0, MagicXP = 0, Stat10 = 4, Stat11 = 12,  // 0xc
        Inv2 = true,                         // Knife
        HealingPotions = 1, MagicPotions = 0,
        X = 50, Y = 50, Facing = 4
    };

    // ── Serialisation helpers (for save/load stubs) ───────────────────────────

    /// <summary>
    /// Serialise the 40-byte stat block in the same field order as SAVEGAME.DAT
    /// (see DGROUP:0x11d4..0x11fb + 0x11d3 + 0x11cb + 0x11cd + 0x445).
    /// Total in-file payload (excluding map) = 40 + 1 + 2 + 2 + 1 = 46 bytes.
    /// The full per-slot save is 30,046 bytes (30,000 map + 46 player).
    /// </summary>
    public byte[] ToSaveBytes()
    {
        var b = new byte[46];
        int i = 0;
        WriteWord(b, ref i, HP);          WriteWord(b, ref i, AttackLevel);
        WriteWord(b, ref i, AttackDie);   WriteWord(b, ref i, DefendLevel);
        WriteWord(b, ref i, DefendDie);   WriteWord(b, ref i, Stat6);
        WriteWord(b, ref i, Stat7);       WriteWord(b, ref i, Gold);
        WriteWord(b, ref i, MP);          WriteWord(b, ref i, MagicXP);
        WriteWord(b, ref i, Stat10);      WriteWord(b, ref i, Stat11);
        b[i++] = Inv0  ? (byte)1 : (byte)0;
        b[i++] = Inv1  ? (byte)1 : (byte)0;
        b[i++] = Inv2  ? (byte)1 : (byte)0;
        b[i++] = Inv3  ? (byte)1 : (byte)0;
        b[i++] = Inv4  ? (byte)1 : (byte)0;
        b[i++] = Inv5  ? (byte)1 : (byte)0;
        b[i++] = Inv6  ? (byte)1 : (byte)0;
        b[i++] = Inv7  ? (byte)1 : (byte)0;
        b[i++] = Inv8  ? (byte)1 : (byte)0;
        b[i++] = Inv9  ? (byte)1 : (byte)0;
        b[i++] = Inv10 ? (byte)1 : (byte)0;
        b[i++] = Inv11 ? (byte)1 : (byte)0;
        WriteWord(b, ref i, HealingPotions);
        WriteWord(b, ref i, MagicPotions);
        b[i++] = (byte)Class;
        WriteWord(b, ref i, X);
        WriteWord(b, ref i, Y);
        b[i++] = (byte)Facing;
        return b;
    }

    private static void WriteWord(byte[] b, ref int i, int v)
    {
        b[i++] = (byte)(v & 0xff);
        b[i++] = (byte)((v >> 8) & 0xff);
    }

    /// <summary>
    /// Deserialise the 46-byte block written by <see cref="ToSaveBytes"/>.
    /// Accepts a <see cref="ReadOnlySpan{T}"/> so callers can pass a slice of a
    /// larger buffer without an extra allocation.
    /// </summary>
    public static PlayerState FromSaveBytes(ReadOnlySpan<byte> b)
    {
        if (b.Length < 46)
            throw new ArgumentException("Buffer too short for player state", nameof(b));

        int i = 0;
        return new PlayerState
        {
            HP             = ReadWord(b, ref i),
            AttackLevel    = ReadWord(b, ref i),
            AttackDie      = ReadWord(b, ref i),
            DefendLevel    = ReadWord(b, ref i),
            DefendDie      = ReadWord(b, ref i),
            Stat6          = ReadWord(b, ref i),
            Stat7          = ReadWord(b, ref i),
            Gold           = ReadWord(b, ref i),
            MP             = ReadWord(b, ref i),
            MagicXP        = ReadWord(b, ref i),
            Stat10         = ReadWord(b, ref i),
            Stat11         = ReadWord(b, ref i),
            Inv0           = b[i++] != 0,
            Inv1           = b[i++] != 0,
            Inv2           = b[i++] != 0,
            Inv3           = b[i++] != 0,
            Inv4           = b[i++] != 0,
            Inv5           = b[i++] != 0,
            Inv6           = b[i++] != 0,
            Inv7           = b[i++] != 0,
            Inv8           = b[i++] != 0,
            Inv9           = b[i++] != 0,
            Inv10          = b[i++] != 0,
            Inv11          = b[i++] != 0,
            HealingPotions = ReadWord(b, ref i),
            MagicPotions   = ReadWord(b, ref i),
            // Class / Facing / X / Y are clamped because PlayerTile() and the world
            // renderer index arrays by these values; a corrupt or partially-written
            // save file with garbage here would otherwise crash via OOB tile lookup.
            Class          = Math.Clamp((int)b[i++], 1, 3),
            X              = Math.Clamp(ReadWord(b, ref i), 1, WorldMap.Width),
            Y              = Math.Clamp(ReadWord(b, ref i), 1, WorldMap.Height),
            Facing         = Math.Clamp((int)b[i], 1, 4),   // last field — no increment needed
        };
    }

    private static int ReadWord(ReadOnlySpan<byte> b, ref int i)
    {
        int v = b[i] | (b[i + 1] << 8);
        i += 2;
        return v;
    }
}

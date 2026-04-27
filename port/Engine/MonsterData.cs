using System;
using System.IO;
using System.Text;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Loads MONSTERS.DAT — 8 records of 52 bytes each (416 bytes total).
/// Record layout (confirmed by stride analysis):
///   [0..25]  name     Turbo Pascal string[25]: byte 0 = length, bytes 1-25 = chars
///   [26..27] word 0   unknown
///   [28..29] word 1   PIC selector (high byte = monster index 1-8, low byte = 0)
///   [30..31] word 2   stat/dice field
///   [32..33] word 3   stat/dice field
///   [34..35] word 4   stat/dice field
///   [36..37] word 5   stat/dice field
///   [38..39] word 6   stat/dice field
///   [40..41] word 7   stat/dice field
///   [42..43] word 8   stat/dice field
///   [44..45] word 9   stat/dice field
///   [46..47] word 10  stat/dice field
///   [48..49] word 11  stat/dice field
///   [50..51] word 12  stat/dice field
/// Fields 2-12 semantics to be confirmed via Ghidra disassembly.
/// </summary>
public sealed class MonsterRecord
{
    public string Name    { get; init; } = string.Empty;
    public ushort[] Words { get; init; } = new ushort[13];
}

public static class MonsterData
{
    public const int RecordSize  = 52;
    public const int RecordCount = 8;
    public const int NameOffset  = 0;
    public const int NameMaxLen  = 25;   // Pascal string[25]

    public static MonsterRecord[] Load(string path)
    {
        var raw = File.ReadAllBytes(path);
        int expected = RecordCount * RecordSize;
        if (raw.Length != expected)
            throw new InvalidDataException(
                $"MONSTERS.DAT: expected {expected} bytes, got {raw.Length}");

        var records = new MonsterRecord[RecordCount];
        for (int i = 0; i < RecordCount; i++)
        {
            int off  = i * RecordSize;
            byte len = raw[off];                              // Pascal length byte
            if (len > NameMaxLen) len = NameMaxLen;
            string name = Encoding.ASCII.GetString(raw, off + 1, len);

            var words = new ushort[13];
            for (int w = 0; w < 13; w++)
                words[w] = (ushort)(raw[off + 26 + w * 2] | (raw[off + 27 + w * 2] << 8));

            records[i] = new MonsterRecord { Name = name, Words = words };
        }
        return records;
    }
}

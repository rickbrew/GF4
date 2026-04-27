using System;
using System.IO;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Loads FADEORDR.DAT — two disjoint tables of 8 192 CGA byte addresses each
/// (16 384 bytes total, as little-endian uint16 values).
/// Together the two tables form a complete, non-overlapping partition of all
/// 16 384 CGA framebuffer byte offsets (0x0000–0x3FFF).
///
/// Used for pixel-by-pixel screen dissolve/wipe transitions:
///   table[0] clears/sets even-numbered pixels in dissolve order
///   table[1] clears/sets odd-numbered  pixels in dissolve order
///
/// Each ushort encodes a raw CGA video-memory byte offset.
/// To convert to a pixel (x, y):
///   if addr &lt; 0x2000:  y = (addr / 80) * 2,     x = (addr % 80) * 4
///   else:              y = ((addr-0x2000)/80)*2+1, x = ((addr-0x2000)%80)*4
/// </summary>
public sealed class FadeTable
{
    public const int AddressCount = 8_192;   // per table
    public const int FileSize     = AddressCount * 2 * 2;  // two tables × 2 bytes/addr = 32 768

    /// <summary>Table 0 — "even" pixel addresses (8 192 entries).</summary>
    public ushort[] Table0 { get; }
    /// <summary>Table 1 — "odd" pixel addresses (8 192 entries).</summary>
    public ushort[] Table1 { get; }

    public FadeTable(string path)
    {
        var raw = File.ReadAllBytes(path);
        if (raw.Length != FileSize)
            throw new InvalidDataException(
                $"FADEORDR.DAT: expected {FileSize} bytes, got {raw.Length}");

        Table0 = new ushort[AddressCount];
        Table1 = new ushort[AddressCount];

        for (int i = 0; i < AddressCount; i++)
        {
            Table0[i] = (ushort)(raw[i * 2    ] | (raw[i * 2     + 1] << 8));
            Table1[i] = (ushort)(raw[i * 2 + AddressCount * 2] |
                                 (raw[i * 2 + AddressCount * 2 + 1] << 8));
        }
    }
}

using System;
using System.IO;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Loads the 24 sprite tiles from GF4.TAB.
/// Confirmed block layout (128 bytes each):
///   [0..3]    header  = 09 00 05 00
///   [4..123]  data    = 120 bytes of CGA 2bpp pixel data
///   [124..127] trailer = 00 00 00 00
///
/// Geometry: BPR=6 → 24 px wide, 20 rows tall.
/// Scanline interleaving (same as CGA framebuffer):
///   bytes  0..59  = even rows (0, 2, 4, …, 18)
///   bytes 60..119 = odd  rows (1, 3, 5, …, 19)
///
/// Known tile assignments:
///   0-2   map background fill tiles
///   3     column/pillar decorative element
///   4     solid cyan fill (floor/water)
///   5-7   dithered fill patterns (light/medium/heavy)
///   8     building/structure icon (inn or dungeon entrance)
///   9     hooded final boss sprite
///   10-19 (all zeros — unused)
///   20    player facing left
///   21    player facing right
///   22    player facing up
///   23    player facing down
/// </summary>
public sealed class TileSet
{
    public const int TileCount  = 24;
    public const int BlockSize  = 128;
    public const int HeaderSize = 4;
    public const int DataBytes  = 120;
    public const int TileWidth  = 24;   // BPR * 4 = 6 * 4
    public const int TileHeight = 20;
    public const int BytesPerRow = 6;   // BPR

    // Each tile is TileWidth * TileHeight palette indices (0-3)
    private readonly byte[][] _tiles = new byte[TileCount][];

    public TileSet(string path)
    {
        var raw = File.ReadAllBytes(path);
        int expected = TileCount * BlockSize;
        if (raw.Length < expected)
            throw new InvalidDataException(
                $"GF4.TAB: expected >= {expected} bytes, got {raw.Length}");

        for (int t = 0; t < TileCount; t++)
            _tiles[t] = DecodeTile(raw, t);
    }

    /// <summary>
    /// Return the palette-index pixel array for tile <paramref name="index"/> (0-23).
    /// Array is TileWidth*TileHeight bytes, row-major.
    /// </summary>
    public byte[] this[int index] => _tiles[index];

    private static byte[] DecodeTile(ReadOnlySpan<byte> raw, int index)
    {
        const int HalfBytes = DataBytes / 2;   // = 60
        const int W = TileWidth;
        const int H = TileHeight;
        const int BPR = BytesPerRow;

        int dataOffset = index * BlockSize + HeaderSize;
        var data = raw.Slice(dataOffset, DataBytes);

        var pixels = new byte[W * H];

        // Even rows: first 60 bytes, 10 rows of BPR bytes each
        // Odd  rows: next  60 bytes, 10 rows of BPR bytes each
        for (int parity = 0; parity < 2; parity++)
        {
            int halfRows  = H / 2;  // = 10
            for (int ri = 0; ri < halfRows; ri++)
            {
                int srcByte = parity * HalfBytes + ri * BPR;
                int dstRow  = ri * 2 + parity;     // interleave back to sequential
                int dstBase = dstRow * W;
                int col = 0;
                for (int bi = 0; bi < BPR; bi++)
                {
                    byte b = data[srcByte + bi];
                    pixels[dstBase + col    ] = (byte)((b >> 6) & 3);
                    pixels[dstBase + col + 1] = (byte)((b >> 4) & 3);
                    pixels[dstBase + col + 2] = (byte)((b >> 2) & 3);
                    pixels[dstBase + col + 3] = (byte)( b        & 3);
                    col += 4;
                }
            }
        }
        return pixels;
    }
}

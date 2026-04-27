using System;
using System.IO;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Decodes a raw CGA .PIC file (16 384 bytes) into a flat array of palette indices.
/// CGA 320×200 format, 2 bits-per-pixel, scanlines interleaved:
///   even scanlines (y=0,2,4,…,198) → byte offset 0x0000 + (y/2)*80
///   odd  scanlines (y=1,3,5,…,199) → byte offset 0x2000 + (y/2)*80
/// Four pixels per byte, MSB-first: bits [7:6] = pixel 0, [5:4] = pixel 1,
///                                               [3:2] = pixel 2, [1:0] = pixel 3.
/// </summary>
public static class PicLoader
{
    public const int FileSize      = 16_384;
    public const int BytesPerRow   = 80;
    public const int EvenBase      = 0x0000;
    public const int OddBase       = 0x2000;

    /// <summary>
    /// Load and decode a .PIC file.
    /// Returns a 320×200 array of palette indices (0–3), row-major.
    /// </summary>
    public static byte[] Load(string path)
    {
        var raw = File.ReadAllBytes(path);
        if (raw.Length != FileSize)
            throw new InvalidDataException(
                $"{Path.GetFileName(path)}: expected {FileSize} bytes, got {raw.Length}");
        return Decode(raw);
    }

    /// <summary>Decode raw bytes already in memory.</summary>
    public static byte[] Decode(ReadOnlySpan<byte> raw)
    {
        const int W = CgaRenderer.Width;
        const int H = CgaRenderer.Height;
        var pixels = new byte[W * H];

        for (int y = 0; y < H; y++)
        {
            int rowBase   = (y % 2 == 0 ? EvenBase : OddBase) + (y / 2) * BytesPerRow;
            int pixelBase = y * W;
            for (int bx = 0; bx < BytesPerRow; bx++)
            {
                byte b = raw[rowBase + bx];
                int px = pixelBase + bx * 4;
                pixels[px    ] = (byte)((b >> 6) & 3);
                pixels[px + 1] = (byte)((b >> 4) & 3);
                pixels[px + 2] = (byte)((b >> 2) & 3);
                pixels[px + 3] = (byte)( b        & 3);
            }
        }
        return pixels;
    }
}

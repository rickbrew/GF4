using System;
using System.Runtime.InteropServices;
using SkiaSharp;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Owns the 320×200 CGA framebuffer as a pinned SKBitmap (BGRA8888).
/// All drawing goes through this class; the canvas reads Bitmap for display.
/// CGA Palette 1, high-intensity: black / cyan / magenta / white.
/// </summary>
public sealed class CgaRenderer : IDisposable
{
    public const int Width  = 320;
    public const int Height = 200;

    // Palette in BGRA8888 uint order (little-endian: B=byte0, G=byte1, R=byte2, A=byte3)
    // uint value = (A << 24) | (R << 16) | (G << 8) | B
    public static readonly uint[] PaletteArgb =
    [
        0xFF000000,  // 0 = black   (R=  0, G=  0, B=  0)
        0xFF55FFFF,  // 1 = cyan    (R= 85, G=255, B=255)
        0xFFFF55FF,  // 2 = magenta (R=255, G= 85, B=255)
        0xFFFFFFFF,  // 3 = white   (R=255, G=255, B=255)
    ];

    // Human-readable SKColors for Skia drawing calls (e.g. text)
    public static readonly SKColor[] Palette =
    [
        new(  0,   0,   0),
        new( 85, 255, 255),
        new(255,  85, 255),
        new(255, 255, 255),
    ];

    public readonly SKBitmap Bitmap;

    public CgaRenderer()
    {
        var info = new SKImageInfo(Width, Height, SKColorType.Bgra8888, SKAlphaType.Opaque);
        Bitmap = new SKBitmap(info);
    }

    /// <summary>
    /// Read-only view of the pixel buffer (BGRA8888, 320×200 uints, row-major).
    /// Used by GameCanvas to blit into a WriteableBitmap without extra allocation.
    /// </summary>
    public ReadOnlySpan<uint> Pixels =>
        MemoryMarshal.Cast<byte, uint>(Bitmap.GetPixelSpan());

    // Writable view used internally by the drawing methods.
    private Span<uint> WritablePixels =>
        MemoryMarshal.Cast<byte, uint>(Bitmap.GetPixelSpan());

    /// <summary>Fill the entire framebuffer with palette index <paramref name="colorIndex"/>.</summary>
    public void Clear(int colorIndex = 0) =>
        WritablePixels.Fill(PaletteArgb[colorIndex & 3]);

    /// <summary>
    /// Set a single pixel. The underlying span is bounds-checked so an out-of-range
    /// (x, y) will either wrap into a different row (when 0 ≤ y*Width+x &lt; total)
    /// or throw IndexOutOfRangeException. Callers are expected to clip beforehand.
    /// </summary>
    public void SetPixel(int x, int y, int colorIndex) =>
        WritablePixels[y * Width + x] = PaletteArgb[colorIndex & 3];

    /// <summary>
    /// Blit a decoded screen image onto the framebuffer.
    /// <paramref name="indices"/> must be Width*Height palette indices, row-major.
    /// </summary>
    public void BlitIndexed(byte[] indices)
    {
        var px = WritablePixels;
        for (int i = 0; i < indices.Length; i++)
            px[i] = PaletteArgb[indices[i] & 3];
    }

    /// <summary>
    /// Copy a decoded tile (24×20 pixels, palette indices) onto the framebuffer at (x,y).
    /// Clips to screen boundaries.
    /// </summary>
    public void BlitTile(byte[] tilePixels, int x, int y)
    {
        var px = WritablePixels;
        const int TW = TileSet.TileWidth;
        const int TH = TileSet.TileHeight;
        for (int row = 0; row < TH; row++)
        {
            int dy = y + row;
            if (dy < 0 || dy >= Height) continue;
            for (int col = 0; col < TW; col++)
            {
                int dx = x + col;
                if (dx < 0 || dx >= Width) continue;
                px[dy * Width + dx] = PaletteArgb[tilePixels[row * TW + col] & 3];
            }
        }
    }

    public void Dispose() => Bitmap.Dispose();
}

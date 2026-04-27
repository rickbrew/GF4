using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Main menu: renders GF4TITLE.PIC as the background and waits for a selection.
///
/// Keys            Action
/// ────────────────────────────────────────────────────────────
///   1 / I         Watch intro slideshow (INTRO1..19.PIC)
///   2 / L         Load saved game  (stub — not yet implemented)
///   3 / N         New game → character select
///   4 / Q / Esc   Quit (closes application)
///
/// Original: entry function (1000:a657) main menu loop with animated BGI sprites.
/// We replicate the structure faithfully but use the pre-rendered title image
/// instead of the dynamic BGI sprite animation.
/// </summary>
public sealed class MainMenuScreen : IGameScreen
{
    private readonly GameData _data;
    private byte[]? _titlePixels;

    // ── Menu overlay geometry (CGA 320×200) ───────────────────────────────────
    private const int BarY  = 168;
    private const int BarH  =  32;
    private const int TextY = 183;   // baseline for SkiaSharp text

    public MainMenuScreen(GameData data)
    {
        _data = data;
    }

    public void OnEnter()
    {
        _titlePixels = _data.LoadPic("GF4TITLE.PIC");
        // TODO(audio): play title music here (FUNKY.CMF was the original BGM)
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        if (input.LastKey is not { } k) return null;

        return k switch
        {
            Key.D1 or Key.I                       => new IntroScreen(_data, this),
            Key.D2 or Key.L                       => null,   // TODO: load-game screen
            Key.D3 or Key.N                       => new CharacterSelectScreen(_data),
            Key.D4 or Key.Q or Key.Escape         => ExitApp(),
            _                                     => null
        };
    }

    public void Render(CgaRenderer renderer)
    {
        if (_titlePixels is not null)
            renderer.BlitIndexed(_titlePixels);
        else
            renderer.Clear(0);

        DrawMenuBar(renderer);
    }

    public void OnExit()
    {
        _titlePixels = null;
    }

    // ── Private helpers ───────────────────────────────────────────────────────

    private static void DrawMenuBar(CgaRenderer renderer)
    {
        // Draw a solid black bar over the bottom of the title image
        for (int y = BarY; y < BarY + BarH; y++)
        for (int x = 0;  x < CgaRenderer.Width; x++)
            renderer.SetPixel(x, y, 0);   // black

        // Cyan top border line
        for (int x = 0; x < CgaRenderer.Width; x++)
            renderer.SetPixel(x, BarY, 1);  // cyan

        // White text labels via SkiaSharp (drawn directly onto the renderer bitmap)
        using var canvas = new SKCanvas(renderer.Bitmap);
        using var font   = new SKFont(
            SKTypeface.FromFamilyName("Courier New", SKFontStyle.Normal) ?? SKTypeface.Default,
            11f);
        using var paint  = new SKPaint { IsAntialias = false, Color = CgaRenderer.Palette[3] };
        canvas.DrawText("1-Intro   2-Load   3-New Game   4-Quit", 12f, TextY, font, paint);
    }

    private static IGameScreen? ExitApp()
    {
        // Request application shutdown via Avalonia's lifetime
        if (Avalonia.Application.Current?.ApplicationLifetime is
            Avalonia.Controls.ApplicationLifetimes.IClassicDesktopStyleApplicationLifetime life)
        {
            life.Shutdown();
        }
        return null;
    }
}

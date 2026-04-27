using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Shows the in-game help screen (F10 in the world loop).
/// Displays control keys and basic gameplay tips on successive pages, each
/// dismissed with a keypress.
///
/// Original: FUN_1000_6165 (ShowHelpScreen, 1,682 bytes).
/// The original uses BGI to draw monster sprite tiles alongside text on
/// multiple pages.  We render plain text using SkiaSharp, matching content
/// as closely as possible.
/// </summary>
public sealed class HelpScreen : IGameScreen
{
    private readonly IGameScreen _returnTo;
    private int  _page;
    private bool _entered;

    private const int PageCount = 3;

    public HelpScreen(IGameScreen returnTo)
    {
        _returnTo = returnTo;
    }

    public void OnEnter()
    {
        _page    = 0;
        _entered = false;
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        if (!_entered) { _entered = true; return null; }

        if (input.LastKey.HasValue || input.Confirm || input.Cancel || input.MouseLeft)
        {
            _page++;
            if (_page >= PageCount || input.Cancel)
                return _returnTo;
        }
        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        renderer.Clear(0);
        using var canvas = new SKCanvas(renderer.Bitmap);

        switch (_page)
        {
            case 0: DrawPage0(canvas); break;
            case 1: DrawPage1(canvas); break;
            case 2: DrawPage2(canvas); break;
        }

        DrawFooter(canvas);
    }

    public void OnExit() { }

    // ── Page content ──────────────────────────────────────────────────────────

    private static void DrawPage0(SKCanvas canvas)
    {
        T(canvas, "THE GOLDEN FLUTE IV  —  Controls", 1, 8, 14, bold: true);
        T(canvas, "Movement:", 3, 8, 32);
        T(canvas, "  Arrow keys  — move (Up/Down/Left/Right)", 3, 8, 44);
        T(canvas, "Actions:", 3, 8, 60);
        T(canvas, "  S           — show Stats screen", 3, 8, 72);
        T(canvas, "  H           — drink Healing Potion (+HP, max 24)", 3, 8, 84);
        T(canvas, "  M           — drink Magic Potion  (+MP, Mage only)", 3, 8, 96);
        T(canvas, "  F10         — show this Help screen", 3, 8, 108);
        T(canvas, "  Q           — Quit to main menu", 3, 8, 120);
        T(canvas, "Cheats (original game):", 2, 8, 136);
        T(canvas, "  * or /      — set HP to typed value", 2, 8, 148);
        T(canvas, "  +           — set Gold to typed value", 2, 8, 160);
        T(canvas, "  -           — set MP to typed value", 2, 8, 172);
    }

    private static void DrawPage1(SKCanvas canvas)
    {
        T(canvas, "THE GOLDEN FLUTE IV  —  Encounters", 1, 8, 14, bold: true);
        T(canvas, "Walk onto a cell to trigger its encounter.", 3, 8, 32);
        T(canvas, "Encounter codes on the map:", 3, 8, 48);
        T(canvas, "  1-2  Weakest monsters (lots of them)", 3, 8, 62);
        T(canvas, "  3    Weak monster", 3, 8, 74);
        T(canvas, "  4-6  Mid-tier monsters", 3, 8, 86);
        T(canvas, "  7    Strong monster", 3, 8, 98);
        T(canvas, "  8    FINAL BOSS  (only one in the world!)", 2, 8, 110);
        T(canvas, "  9    Shop entrance", 1, 8, 122);
        T(canvas, "  10   Gold pickup (+50 gold)", 1, 8, 134);
        T(canvas, "Monsters are hidden until you step on them.", 3, 8, 154);
        T(canvas, "Gold and shops show special graphics.", 1, 8, 166);
    }

    private static void DrawPage2(SKCanvas canvas)
    {
        T(canvas, "THE GOLDEN FLUTE IV  —  Characters", 1, 8, 14, bold: true);
        T(canvas, "Fighter  —  highest HP, strong attacks, has Sword+Shield", 3, 8, 34);
        T(canvas, "  HP:8  Atk:5  Def:2  Gold:50  No magic", 3, 16, 46);
        T(canvas, "Mage     —  low HP but high defence, casts spells", 3, 8, 64);
        T(canvas, "  HP:5  Atk:3  Def:4  Gold:50  MP:10  Magic potions", 3, 16, 76);
        T(canvas, "Thief    —  fast attacker, starts with extra gold", 3, 8, 94);
        T(canvas, "  HP:6  Atk:6  Def:2  Gold:75  Has Knife", 3, 16, 106);
        T(canvas, "Healing Potion  →  H key  (all classes get one to start)", 3, 8, 126);
        T(canvas, "Magic Potion    →  M key  (Mage only)", 3, 8, 138);
        T(canvas, "Save format: 30 KB map + 40-byte stat block per slot.", 2, 8, 158);
        T(canvas, "(Save/load not yet implemented in this port.)", 2, 8, 170);
    }

    private static void DrawFooter(SKCanvas canvas)
    {
        for (float x = 0; x < 320; x++) { /* blank — already black background */ }
        T(canvas, "[Any key = next page    Esc = close]", 1, 30, 198);
    }

    // ── Text helper ───────────────────────────────────────────────────────────

    private static readonly SKFont SmFont = new(SKTypeface.FromFamilyName(
        "Courier New", SKFontStyle.Normal) ?? SKTypeface.Default, 10f);
    private static readonly SKFont BdFont = new(SKTypeface.FromFamilyName(
        "Courier New", SKFontStyle.Bold)   ?? SKTypeface.Default, 11f);

    private static void T(SKCanvas canvas, string text, int colorIdx,
                           float x, float y, bool bold = false)
    {
        using var paint = new SKPaint { Color = CgaRenderer.Palette[colorIdx], IsAntialias = false };
        canvas.DrawText(text, x, y, bold ? BdFont : SmFont, paint);
    }
}

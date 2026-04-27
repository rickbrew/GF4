using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Shows CHOOSE.PIC and lets the player pick Fighter (F), Mage (M), or Thief (T).
/// Also accepts left-click in the approximate portrait zones.
///
/// Original: FUN_1000_915b (CharacterSelect, 4,435 bytes).
/// The original uses BGI mouse hit-test (FUN_1000_90dc) with click zones in
/// BGI/mouse coordinates; we use CGA pixel coords as a faithful approximation.
/// The original also animates a blinking highlight on the selected class while
/// waiting (FUN_1000_90b3 / AnimateBlinkFrame).  We reproduce that with a simple
/// phase-toggle on a 500 ms timer.
/// </summary>
public sealed class CharacterSelectScreen : IGameScreen
{
    private readonly GameData _data;
    private byte[]? _picPixels;

    // Blink state — toggles the highlight overlay on the "most recently hovered" zone
    private TimeSpan _blinkTimer;
    private bool     _blinkOn;
    private int      _hoveredClass;   // 0=none, 1/2/3

    // Approximate portrait click zones in CGA pixel coordinates (x: 0-319, y: 0-199).
    // The originals are at (x1=60,y1=??  x2=140,y2=??) in a BGI/mouse coord system;
    // we divide the screen into thirds as the best available approximation until we
    // can run the DOS binary side-by-side and measure precisely.
    private static bool InFighterZone(double x, double y) => x is >= 50 and <= 250 && y is >= 10 and <= 75;
    private static bool InMageZone   (double x, double y) => x is >= 50 and <= 250 && y is >= 75 and <= 135;
    private static bool InThiefZone  (double x, double y) => x is >= 50 and <= 250 && y is >= 135 and <= 195;

    public CharacterSelectScreen(GameData data)
    {
        _data = data;
    }

    public void OnEnter()
    {
        _picPixels    = _data.LoadPic("CHOOSE.PIC");
        _blinkTimer   = TimeSpan.Zero;
        _blinkOn      = true;
        _hoveredClass = 0;
        // TODO(audio): play character-select music here
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        // ── Keyboard shortcuts ────────────────────────────────────────────────
        if (input.LastKey is { } k)
        {
            switch (k)
            {
                case Key.F: return StartGame(PlayerState.CreateFighter());
                case Key.M: return StartGame(PlayerState.CreateMage());
                case Key.T: return StartGame(PlayerState.CreateThief());
                case Key.Escape: return new MainMenuScreen(_data);
            }
        }

        // ── Mouse hover (for blink highlight) ─────────────────────────────────
        _hoveredClass = 0;
        if (InFighterZone(input.MouseX, input.MouseY)) _hoveredClass = 1;
        else if (InMageZone(input.MouseX, input.MouseY)) _hoveredClass = 2;
        else if (InThiefZone(input.MouseX, input.MouseY)) _hoveredClass = 3;

        // ── Mouse click ───────────────────────────────────────────────────────
        if (input.MouseLeft)
        {
            double mx = input.MouseX, my = input.MouseY;
            if (InFighterZone(mx, my)) return StartGame(PlayerState.CreateFighter());
            if (InMageZone   (mx, my)) return StartGame(PlayerState.CreateMage());
            if (InThiefZone  (mx, my)) return StartGame(PlayerState.CreateThief());
        }

        // ── Blink animation ───────────────────────────────────────────────────
        _blinkTimer += dt;
        if (_blinkTimer.TotalMilliseconds >= 500)
        {
            _blinkOn    = !_blinkOn;
            _blinkTimer = TimeSpan.Zero;
        }

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        if (_picPixels is not null)
            renderer.BlitIndexed(_picPixels);
        else
            renderer.Clear(0);

        // Draw a blinking highlight over the hovered class zone
        if (_hoveredClass != 0 && _blinkOn)
            DrawHighlight(renderer, _hoveredClass);

        // Draw keyboard hint text at the bottom
        DrawHint(renderer);
    }

    public void OnExit()
    {
        _picPixels = null;
        // TODO(audio): stop character-select music here
    }

    // ── Private helpers ───────────────────────────────────────────────────────

    private IGameScreen StartGame(PlayerState player)
    {
        // TODO(audio): play FIGHTER.VOC / MAGIC.VOC / THIEF.VOC here
        var map = WorldMap.Generate(new Random());
        return new WorldScreen(_data, player, map);
    }

    /// <summary>Draw a thin cyan outline around the hovered class zone.</summary>
    private static void DrawHighlight(CgaRenderer renderer, int cls)
    {
        int y1 = cls switch { 1 => 10, 2 => 75, _ => 135 };
        int y2 = cls switch { 1 => 75, 2 => 135, _ => 195 };
        const int x1 = 50, x2 = 250;

        for (int x = x1; x <= x2; x++) { renderer.SetPixel(x, y1, 1); renderer.SetPixel(x, y2, 1); }
        for (int y = y1; y <= y2; y++) { renderer.SetPixel(x1, y, 1); renderer.SetPixel(x2, y, 1); }
    }

    private static void DrawHint(CgaRenderer renderer)
    {
        // Black bar at very bottom
        for (int x = 0; x < CgaRenderer.Width; x++)
        {
            renderer.SetPixel(x, 196, 0);
            renderer.SetPixel(x, 197, 0);
            renderer.SetPixel(x, 198, 0);
            renderer.SetPixel(x, 199, 0);
        }

        using var canvas = new SKCanvas(renderer.Bitmap);
        using var font   = new SKFont(SKTypeface.Default, 10f);
        using var paint  = new SKPaint { IsAntialias = false, Color = CgaRenderer.Palette[1] };
        canvas.DrawText("F - Fighter    M - Mage    T - Thief", 18f, 198f, font, paint);
    }
}

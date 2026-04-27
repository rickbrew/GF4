using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// In-game save-slot picker, reached by pressing F5 in the world.
/// Overlays the current world view behind a centred dialog box.
/// Returns to <paramref name="_returnTo"/> (WorldScreen) on save or cancel.
///
/// Layout: three slots displayed with a '>' cursor; 1-3 / arrows select;
/// Enter saves; Escape cancels; failed saves stay on-screen with an error line.
/// </summary>
public sealed class SaveScreen : IGameScreen
{
    private readonly PlayerState  _player;
    private readonly WorldMap     _map;
    private readonly IGameScreen  _returnTo;

    private int     _selected = 1;          // 1–SlotCount
    private string? _statusMsg;             // shown in magenta on failure

    // Slot summaries loaded once in OnEnter (index 0 unused; 1-based for clarity).
    private readonly PlayerState?[] _peeks = new PlayerState?[SaveManager.SlotCount + 1];

    // ── Fonts (static: allocated once, shared across all frames) ─────────────
    private static readonly SKFont NormalFont = new(
        SKTypeface.FromFamilyName("Courier New", SKFontStyle.Normal) ?? SKTypeface.Default, 10f);
    private static readonly SKFont BoldFont = new(
        SKTypeface.FromFamilyName("Courier New", SKFontStyle.Bold) ?? SKTypeface.Default, 10f);

    public SaveScreen(PlayerState player, WorldMap map, IGameScreen returnTo)
    {
        _player   = player;
        _map      = map;
        _returnTo = returnTo;
    }

    public void OnEnter()
    {
        for (int s = 1; s <= SaveManager.SlotCount; s++)
            _peeks[s] = SaveManager.PeekPlayer(s);
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        // Direct slot selection
        if (input.LastKey is Key.D1) _selected = 1;
        else if (input.LastKey is Key.D2) _selected = 2;
        else if (input.LastKey is Key.D3) _selected = 3;

        // Arrow navigation
        if (input.Up   && _selected > 1)                      _selected--;
        if (input.Down && _selected < SaveManager.SlotCount)  _selected++;

        // Save
        if (input.Confirm)
        {
            if (SaveManager.Save(_selected, _player, _map))
                return _returnTo;
            _statusMsg = "Save failed — check disk space / permissions.";
            return null;
        }

        // Cancel
        if (input.Cancel)
            return _returnTo;

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        _returnTo.Render(renderer);   // draw world view behind the dialog
        DrawDialog(renderer);
    }

    public void OnExit() { }

    // ── Dialog rendering ──────────────────────────────────────────────────────

    private const int X1 = 50, Y1 = 38, X2 = 270, Y2 = 162;

    private void DrawDialog(CgaRenderer renderer)
    {
        // Fill box with black
        for (int y = Y1 + 1; y < Y2; y++)
        for (int x = X1 + 1; x < X2; x++)
            renderer.SetPixel(x, y, 0);

        // Cyan border
        for (int x = X1; x <= X2; x++) { renderer.SetPixel(x, Y1, 1); renderer.SetPixel(x, Y2, 1); }
        for (int y = Y1; y <= Y2; y++) { renderer.SetPixel(X1, y, 1); renderer.SetPixel(X2, y, 1); }

        // Cyan divider above hints
        for (int x = X1 + 1; x < X2; x++)
            renderer.SetPixel(x, 130, 1);

        using var canvas = new SKCanvas(renderer.Bitmap);

        // Title
        using (var p = new SKPaint { Color = CgaRenderer.Palette[1], IsAntialias = false })
            canvas.DrawText("SAVE GAME", 118f, 54f, BoldFont, p);

        // Slot rows
        for (int s = 1; s <= SaveManager.SlotCount; s++)
        {
            bool   sel   = s == _selected;
            float  y     = 72f + (s - 1) * 20f;
            var    color = sel ? CgaRenderer.Palette[1] : CgaRenderer.Palette[3];
            using var p  = new SKPaint { Color = color, IsAntialias = false };

            string prefix  = sel ? ">" : " ";
            canvas.DrawText($"{prefix} [{s}] {SlotSummary(s)}", 62f, y, NormalFont, p);
        }

        // Hints
        using (var p = new SKPaint { Color = CgaRenderer.Palette[3], IsAntialias = false })
        {
            canvas.DrawText("1-3 / arrows: select slot", 68f, 144f, NormalFont, p);
            canvas.DrawText("Enter = Save      Esc = Cancel", 62f, 156f, NormalFont, p);
        }

        // Error message (if any)
        if (_statusMsg is not null)
        {
            using var p = new SKPaint { Color = CgaRenderer.Palette[2], IsAntialias = false };
            canvas.DrawText(_statusMsg, 62f, 168f, NormalFont, p);
        }
    }

    private string SlotSummary(int slot)
    {
        var p = _peeks[slot];
        return p is null
            ? "(empty)"
            : $"{p.ClassName,-7}   X:{p.X,3} Y:{p.Y,3}";
    }
}

using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Save-slot picker shown from the main menu (key 2 / L).
/// Draws a standalone black-background dialog; no world view behind it.
///
/// Layout: three slots displayed with a '>' cursor; 1-3 / arrows select;
/// Enter loads the highlighted slot (if it exists); Escape returns to the caller.
/// Empty and unreadable slots cannot be loaded — a status line explains why.
/// </summary>
public sealed class LoadScreen : IGameScreen
{
    private readonly GameData    _data;
    private readonly IGameScreen _returnTo;   // MainMenuScreen

    private int     _selected = 1;
    private string? _statusMsg;

    // Slot summaries loaded once in OnEnter (index 0 unused).
    private readonly PlayerState?[] _peeks = new PlayerState?[SaveManager.SlotCount + 1];

    // ── Fonts ─────────────────────────────────────────────────────────────────
    private static readonly SKFont NormalFont = new(
        SKTypeface.FromFamilyName("Courier New", SKFontStyle.Normal) ?? SKTypeface.Default, 10f);
    private static readonly SKFont BoldFont = new(
        SKTypeface.FromFamilyName("Courier New", SKFontStyle.Bold) ?? SKTypeface.Default, 10f);

    public LoadScreen(GameData data, IGameScreen returnTo)
    {
        _data     = data;
        _returnTo = returnTo;
    }

    public void OnEnter()
    {
        for (int s = 1; s <= SaveManager.SlotCount; s++)
            _peeks[s] = SaveManager.PeekPlayer(s);

        // Auto-advance to the first occupied slot if all are empty, leave at 1.
        for (int s = 1; s <= SaveManager.SlotCount; s++)
        {
            if (_peeks[s] is not null) { _selected = s; break; }
        }
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

        // Load
        if (input.Confirm)
        {
            if (_peeks[_selected] is null)
            {
                _statusMsg = "No save in that slot.";
                return null;
            }

            var save = SaveManager.Load(_selected);
            if (save is null)
            {
                _statusMsg = "Save file is corrupt or unreadable.";
                return null;
            }

            return new WorldScreen(_data, save.Value.Player, save.Value.Map);
        }

        // Cancel
        if (input.Cancel)
            return _returnTo;

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        renderer.Clear(0);
        DrawDialog(renderer);
    }

    public void OnExit() { }

    // ── Dialog rendering ──────────────────────────────────────────────────────

    private const int X1 = 50, Y1 = 38, X2 = 270, Y2 = 162;

    private void DrawDialog(CgaRenderer renderer)
    {
        // Cyan border (background is already black from renderer.Clear)
        for (int x = X1; x <= X2; x++) { renderer.SetPixel(x, Y1, 1); renderer.SetPixel(x, Y2, 1); }
        for (int y = Y1; y <= Y2; y++) { renderer.SetPixel(X1, y, 1); renderer.SetPixel(X2, y, 1); }

        // Divider above hints
        for (int x = X1 + 1; x < X2; x++)
            renderer.SetPixel(x, 130, 1);

        using var canvas = new SKCanvas(renderer.Bitmap);

        // Title
        using (var p = new SKPaint { Color = CgaRenderer.Palette[1], IsAntialias = false })
            canvas.DrawText("LOAD GAME", 118f, 54f, BoldFont, p);

        // Slot rows
        for (int s = 1; s <= SaveManager.SlotCount; s++)
        {
            bool   sel    = s == _selected;
            bool   exists = _peeks[s] is not null;
            float  y      = 72f + (s - 1) * 20f;

            // Colour: cyan = selected, white = has data, magenta = empty
            var color = sel    ? CgaRenderer.Palette[1]
                      : exists ? CgaRenderer.Palette[3]
                               : CgaRenderer.Palette[2];

            using var p = new SKPaint { Color = color, IsAntialias = false };

            string prefix = sel ? ">" : " ";
            canvas.DrawText($"{prefix} [{s}] {SlotSummary(s)}", 62f, y, NormalFont, p);
        }

        // Hints
        using (var p = new SKPaint { Color = CgaRenderer.Palette[3], IsAntialias = false })
        {
            canvas.DrawText("1-3 / arrows: select slot", 68f, 144f, NormalFont, p);
            canvas.DrawText("Enter = Load      Esc = Cancel", 62f, 156f, NormalFont, p);
        }

        // Status / error message
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

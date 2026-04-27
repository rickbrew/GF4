using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Displays the player stats screen (triggered by pressing S in the world loop).
/// Shows all fields from the PlayerState struct in a BGI-style text layout.
/// Any key or mouse click returns to the world screen.
///
/// Original: FUN_1000_172b (ShowStatsScreen, 1,942 bytes).
/// The original uses BGI OutTextXY calls with Str() conversions; we replicate
/// the same information using SkiaSharp text rendered directly onto the CGA bitmap.
/// The original does NOT load a PIC — it draws everything via BGI into a text
/// mode screen.  We match that by painting directly onto the renderer.
/// </summary>
public sealed class StatsScreen : IGameScreen
{
    private readonly PlayerState _player;
    private readonly IGameScreen _returnTo;
    private          bool        _entered;   // suppress the key that opened us

    public StatsScreen(PlayerState player, IGameScreen returnTo)
    {
        _player   = player;
        _returnTo = returnTo;
    }

    public void OnEnter()
    {
        _entered = false;
        // TODO(audio): play STATS.VOC here (if such a file exists)
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        // Eat the first frame so the 'S' key press that opened us doesn't also close us.
        if (!_entered) { _entered = true; return null; }

        if (input.LastKey.HasValue || input.Confirm || input.Cancel || input.MouseLeft)
            return _returnTo;

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        // Black background — original uses BGI ClearDevice + SetBkColor
        renderer.Clear(0);

        using var canvas = new SKCanvas(renderer.Bitmap);

        // Title
        DrawText(canvas, _player.ClassName + " Statistics", 1, 8,  10, bold: true);

        // Stats
        int col1x = 8, col2x = 168, y = 26;
        DrawLabel(canvas, "HP",             _player.HP,             col1x, y);
        DrawLabel(canvas, "Gold",           _player.Gold,           col2x, y); y += 14;

        DrawLabel(canvas, "Attack Level",   _player.AttackLevel,    col1x, y);
        DrawLabel(canvas, "Attack Die",     _player.AttackDie,      col2x, y); y += 14;

        DrawLabel(canvas, "Defend Level",   _player.DefendLevel,    col1x, y);
        DrawLabel(canvas, "Defend Die",     _player.DefendDie,      col2x, y); y += 14;

        DrawLabel(canvas, "Strength",       _player.Stat6,          col1x, y);
        DrawLabel(canvas, "Dexterity",      _player.Stat7,          col2x, y); y += 14;

        DrawLabel(canvas, "XP",             _player.Stat10,         col1x, y);
        DrawLabel(canvas, "Stat11",         _player.Stat11,         col2x, y); y += 14;

        DrawLabel(canvas, "Heal Potions",   _player.HealingPotions, col1x, y);
        y += 14;

        if (_player.Class == 2)   // Mage only
        {
            DrawLabel(canvas, "Magic Points",  _player.MP,            col1x, y);
            DrawLabel(canvas, "Magic XP",      _player.MagicXP,       col2x, y); y += 14;
            DrawLabel(canvas, "Magic Potions", _player.MagicPotions,  col1x, y); y += 14;
        }

        y += 4;
        // Inventory flags — show names for flags that are set
        int invY = y;
        DrawText(canvas, "Inventory:", 1, col1x, invY);  invY += 12;
        if (_player.Inv0)  { DrawText(canvas, "Sword",      3, col1x, invY); invY += 12; }
        if (_player.Inv1)  { DrawText(canvas, "Item 2",     3, col1x, invY); invY += 12; }
        if (_player.Inv2)  { DrawText(canvas, "Knife",      3, col1x, invY); invY += 12; }
        if (_player.Inv3)  { DrawText(canvas, "Item 4",     3, col1x, invY); invY += 12; }
        if (_player.Inv4)  { DrawText(canvas, "Item 5",     3, col1x, invY); invY += 12; }
        if (_player.Inv5)  { DrawText(canvas, "Shield",     3, col1x, invY); invY += 12; }
        if (_player.Inv6)  { DrawText(canvas, "Item 7",     3, col2x, invY); invY += 12; }
        if (_player.Inv7)  { DrawText(canvas, "Item 8",     3, col2x, invY); invY += 12; }
        if (_player.Inv8)  { DrawText(canvas, "Item 9",     3, col2x, invY); invY += 12; }
        if (_player.Inv9)  { DrawText(canvas, "Item 10",    3, col2x, invY); invY += 12; }
        if (_player.Inv10) { DrawText(canvas, "Spell Book", 3, col2x, invY); invY += 12; }
        if (_player.Inv11) { DrawText(canvas, "Item 12",    3, col2x, invY); invY += 12; }

        // Position
        DrawText(canvas, $"Position: ({_player.X}, {_player.Y})", 2, col1x, 180);

        // Prompt
        DrawText(canvas, "[Press any key to continue]", 1, 40, 194);
    }

    public void OnExit() { }

    // ── Drawing helpers ───────────────────────────────────────────────────────

    private static readonly SKFont SmallFont = new(SKTypeface.FromFamilyName(
        "Courier New", SKFontStyle.Normal) ?? SKTypeface.Default, 10f);

    private static readonly SKFont BoldFont = new(SKTypeface.FromFamilyName(
        "Courier New", SKFontStyle.Bold) ?? SKTypeface.Default, 11f);

    private static void DrawText(SKCanvas canvas, string text, int colorIdx, float x, float y,
                                  bool bold = false)
    {
        using var paint = new SKPaint { Color = CgaRenderer.Palette[colorIdx], IsAntialias = false };
        canvas.DrawText(text, x, y, bold ? BoldFont : SmallFont, paint);
    }

    private static void DrawLabel(SKCanvas canvas, string label, int value, float x, float y)
    {
        DrawText(canvas, $"{label}: {value}", 3, x, y);
    }
}

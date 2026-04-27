using System;
using Avalonia.Input;
using GoldenFluteIV.Engine;
using SkiaSharp;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Main world / game loop — the heart of the game.
///
/// Handles: tile-based top-down movement, wall collision, all encounter types,
/// potion use, stats screen, help screen, and quit.
///
/// Original: FUN_1000_687f (WorldGameLoop, 2,289 bytes).
///
/// Wall collision (mirroring the 687f logic exactly):
///   terrain codes 1, 5, 6, 7, 8 → impassable; movement reverted.
///   terrain codes 2, 3, 4       → passable.
///
/// Encounter resolution after a valid step (mirroring 687f):
///   1-7  → monster combat   (TODO — stub: clear cell, show message)
///   8    → final boss       (TODO — stub: same)
///   9    → special / shop   (TODO — stub: clear cell, show message)
///   10   → gold pickup      (+50 gold, clear cell, show message 2 s)
/// </summary>
public sealed class WorldScreen : IGameScreen
{
    // ── Dependencies ──────────────────────────────────────────────────────────
    private readonly GameData   _data;
    private readonly PlayerState _player;
    private readonly WorldMap   _map;
    private readonly Random     _rng = new();

    // ── Notification message (shown for a brief duration) ────────────────────
    private string?  _message;
    private TimeSpan _msgTimer;
    private const double MsgDurationSecs = 2.0;

    // ── Death / game-over flag ────────────────────────────────────────────────
    // Initialized to false; set to true by combat system once implemented (TODO).
    private bool _gameOver = false;

    public WorldScreen(GameData data, PlayerState player, WorldMap map)
    {
        _data   = data;
        _player = player;
        _map    = map;
    }

    // ── IGameScreen ───────────────────────────────────────────────────────────

    public void OnEnter()
    {
        // TODO(audio): play FUNKY.CMF here (main world music)
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        // Clear old notification
        if (_message is not null)
        {
            _msgTimer -= dt;
            if (_msgTimer <= TimeSpan.Zero) _message = null;
        }

        if (_gameOver)
        {
            // Game over — any key returns to main menu (Confirm also sets LastKey).
            if (input.LastKey.HasValue || input.MouseLeft)
                return new MainMenuScreen(_data);
            return null;
        }

        // ── Special keys (checked before movement) ────────────────────────────
        if (input.LastKey is { } k)
        {
            switch (k)
            {
                case Key.Q or Key.Escape:
                    // TODO(audio): stop music here (FUN_20e5_015a)
                    return new MainMenuScreen(_data);

                case Key.S:
                    return new StatsScreen(_player, this);

                case Key.F5:
                    return new SaveScreen(_player, _map, this);

                case Key.F10:
                    return new HelpScreen(this);

                case Key.H:
                    UseHealingPotion();
                    return null;

                case Key.M:
                    UseMagicPotion();
                    return null;

                // Developer cheat keys (original: * / + -)
                // Kept as no-ops in the port; real cheat support is deferred.
                // TODO: implement cheat console
            }
        }

        // ── Movement (arrow keys only — faithful to original; no WASD) ────────
        bool moved = false;
        int  newX  = _player.X, newY = _player.Y;
        int  facing = _player.Facing;

        if (input.Up)    { newY--; facing = 3; moved = true; }
        else if (input.Down)  { newY++; facing = 4; moved = true; }
        else if (input.Left)  { newX--; facing = 1; moved = true; }
        else if (input.Right) { newX++; facing = 2; moved = true; }

        if (moved)
        {
            _player.Facing = facing;

            // Clamp to map bounds (1..100)
            newX = Math.Clamp(newX, 1, WorldMap.Width);
            newY = Math.Clamp(newY, 1, WorldMap.Height);

            // Wall collision — mirror of the 687f goto LAB_1000_6e2b block
            if (_map.IsWall(newX, newY))
            {
                // Revert: keep old X/Y, just update facing
                // TODO(audio): play wall-bump beep (FUN_2110_0311(440) + Delay(25))
            }
            else
            {
                _player.X = newX;
                _player.Y = newY;

                // ── Encounter check ───────────────────────────────────────────
                ref var cell = ref _map.Cell(_player.X, _player.Y);
                if (cell.HasEncounter)
                    HandleEncounter(ref cell);
            }
        }

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        DrawWorldView(renderer);
        DrawHud(renderer);
        if (_message is not null)      DrawMessage(renderer, _message);
        if (_gameOver)                 DrawGameOver(renderer);
    }

    public void OnExit()
    {
        // TODO(audio): stop music here
    }

    // ── Movement helpers ──────────────────────────────────────────────────────

    private void UseHealingPotion()
    {
        if (_player.HealingPotions < 1)
        {
            ShowMessage("No healing potions left!");
            // TODO(audio): play error beep
            return;
        }
        _player.HealingPotions--;
        // Original restores HP by a computed amount; we use a fixed +6 ±rand(3)
        // capped at MaxHP (24 = 0x18).  This is faithful to the "restore some HP"
        // intent of the original without knowing the exact formula.
        int heal = 6 + _rng.Next(3);
        _player.HP = Math.Min(_player.HP + heal, PlayerState.MaxHP);
        ShowMessage($"Drank healing potion (+{heal} HP)");
        // TODO(audio): play healing sound (FUN_20e5_01e1 → HEAL.VOC)
    }

    private void UseMagicPotion()
    {
        // Original: class must be 2 (Mage) and MagicPotions > 0
        if (_player.Class != 2)
        {
            ShowMessage("Only Mages can drink magic potions!");
            // TODO(audio): play error beep
            return;
        }
        if (_player.MagicPotions < 1)
        {
            ShowMessage("No magic potions left!");
            // TODO(audio): play error beep
            return;
        }
        _player.MagicPotions--;
        int restore = 6 + _rng.Next(3);
        _player.MP = Math.Min(_player.MP + restore, PlayerState.MaxMP);
        ShowMessage($"Drank magic potion (+{restore} MP)");
        // TODO(audio): play magic potion sound (FUN_20e5_01e1 → MAGIC.VOC)
    }

    // ── Encounter resolution ──────────────────────────────────────────────────

    private void HandleEncounter(ref MapCell cell)
    {
        // TODO(audio): play BUZZER.VOC before encounter (FUN_1f6f_02b7 or FUN_20e5_01e1)

        if (cell.IsGold)
        {
            // Encounter 10: gold pickup.  Original: gold += 50, clear cell, 2-second display
            _player.Gold += 50;
            cell.Encounter = 0;
            ShowMessage("You found gold! (+50)");
            // TODO(audio): play gold fanfare
        }
        else if (cell.IsShop)
        {
            // Encounter 9: shop entrance.  Original calls FUN_1000_5be6 (SpecialEncounter9)
            // and restarts music afterward.
            ShowMessage("You found a shop! (coming soon)");
            // TODO(shop): implement FUN_1000_5be6 (ShopPotionsSpells / ShopWeaponsArmour)
            // TODO(audio): play shop jingle (three-note beep in original)
        }
        else if (cell.IsMonster || cell.IsBoss)
        {
            // Encounters 1-8: combat.  Original calls FUN_1000_43f7 (CombatManager).
            // Return value 1 or 3 = game ends; anything else = continue.
            int code = cell.Encounter;
            cell.Encounter = 0;   // clear so we don't fight repeatedly if we stub out

            // TODO(combat): implement FUN_1000_43f7 — monster lookup, attack/defend dice,
            //               DRAGON1/2.PIC, ORC1/2.PIC etc.
            if (code == 8)
                ShowMessage("THE FINAL BOSS! (combat coming soon)");
            else
                ShowMessage($"Monster encounter! (code {code}) — combat coming soon");

            // TODO(audio): resume FUNKY.CMF after combat
        }
    }

    // ── Rendering ─────────────────────────────────────────────────────────────

    // Tile-to-terrain mapping table (terrain byte → tile index in GF4.TAB).
    // The original uses a far-pointer lookup table at DS:0x874c; these indices
    // are our best approximation based on the confirmed tile descriptions in TileSet.cs.
    //
    // Known tiles:
    //   0-2   map background fill tiles
    //   3     column / pillar decorative element
    //   4     solid fill (floor)
    //   5-7   dithered fill patterns (light / medium / heavy — used for walls)
    //   8     building / structure icon (shop)
    //   9     hooded final boss sprite
    //   20-23 player sprites (left / right / up / down)
    private static readonly byte[] TerrainToTile =
    [
        //  idx  terrain   description
        0,   //  [0]  terrain 0   (unused — maps to default ground)
        3,   //  [1]  terrain 1   wall (column/pillar)
        1,   //  [2]  terrain 2   passable ground variant
        0,   //  [3]  terrain 3   default ground (most common)
        2,   //  [4]  terrain 4   open clearing / plains tile
        7,   //  [5]  terrain 5   wall (heavy dither)
        6,   //  [6]  terrain 6   wall (medium dither)
        5,   //  [7]  terrain 7   wall (light dither)
        4,   //  [8]  terrain 8   solid wall (border)
    ];

    private int TerrainTile(int x, int y)
    {
        if (x < 1 || x > WorldMap.Width || y < 1 || y > WorldMap.Height)
            return TerrainToTile[8];   // border wall outside map

        byte t = _map.Cell(x, y).Terrain;
        if (t < TerrainToTile.Length) return TerrainToTile[t];
        return TerrainToTile[8];
    }

    private int EncounterTile(int x, int y)
    {
        if (x < 1 || x > WorldMap.Width || y < 1 || y > WorldMap.Height) return -1;
        ref var cell = ref _map.Cell(x, y);
        if (cell.IsShop) return 8;   // building icon (inn / shop)
        return -1;                   // no override (monsters are hidden until stepped on)
    }

    private int PlayerTile()
    {
        // Tiles 20-23: player sprite for each facing direction
        // Facing: 1=Left → tile 20, 2=Right → tile 21, 3=Up → tile 22, 4=Down → tile 23
        return 20 + (_player.Facing - 1);
    }

    private void DrawWorldView(CgaRenderer renderer)
    {
        const int TW = TileSet.TileWidth;   // 24 px
        const int TH = TileSet.TileHeight;  // 20 px
        const int VW = CgaRenderer.Width  / TW;  // 13 tiles across (320/24 = 13.33)
        const int VH = CgaRenderer.Height / TH;  // 10 tiles down   (200/20 = 10.0)

        int startX = _player.X - VW / 2;
        int startY = _player.Y - VH / 2;

        for (int ty = 0; ty < VH; ty++)
        for (int tx = 0; tx < VW; tx++)
        {
            int mapX = startX + tx;
            int mapY = startY + ty;

            // Terrain tile base layer
            int tileIdx = TerrainTile(mapX, mapY);
            renderer.BlitTile(_data.Tiles[tileIdx], tx * TW, ty * TH);

            // Encounter overlay (shop icon) — monsters remain hidden
            int encIdx = EncounterTile(mapX, mapY);
            if (encIdx >= 0)
                renderer.BlitTile(_data.Tiles[encIdx], tx * TW, ty * TH);
        }

        // Player sprite — always at viewport centre
        int playerTx = _player.X - startX;
        int playerTy = _player.Y - startY;
        renderer.BlitTile(_data.Tiles[PlayerTile()], playerTx * TW, playerTy * TH);
    }

    private void DrawHud(CgaRenderer renderer)
    {
        // One-pixel cyan top bar as a health-indicator line
        // Original renders HP/MP/Gold via BGI text in the world view;
        // we overlay a thin SkiaSharp status line at the top.
        using var canvas = new SKCanvas(renderer.Bitmap);

        // Transparent black strip
        using (var bg = new SKPaint { Color = new SKColor(0, 0, 0, 180) })
            canvas.DrawRect(0, 0, 320, 12, bg);

        using var paint = new SKPaint { Color = CgaRenderer.Palette[3], IsAntialias = false };
        using var font  = new SKFont(SKTypeface.FromFamilyName("Courier New",
                              SKFontStyle.Normal) ?? SKTypeface.Default, 10f);

        string hud = _player.Class == 2
            ? $"HP:{_player.HP}/{PlayerState.MaxHP}  MP:{_player.MP}/{PlayerState.MaxMP}  Gold:{_player.Gold}  HPot:{_player.HealingPotions}  MPot:{_player.MagicPotions}"
            : $"HP:{_player.HP}/{PlayerState.MaxHP}  Gold:{_player.Gold}  HealPot:{_player.HealingPotions}";

        canvas.DrawText(hud, 4f, 10f, font, paint);
    }

    private static void DrawMessage(CgaRenderer renderer, string msg)
    {
        using var canvas = new SKCanvas(renderer.Bitmap);
        using var bg     = new SKPaint { Color = new SKColor(0, 0, 0, 200) };
        canvas.DrawRect(0, 90, 320, 20, bg);

        using var paint = new SKPaint { Color = CgaRenderer.Palette[2], IsAntialias = false };
        using var font  = new SKFont(SKTypeface.FromFamilyName("Courier New",
                              SKFontStyle.Normal) ?? SKTypeface.Default, 11f);
        canvas.DrawText(msg, 8f, 104f, font, paint);
    }

    private static void DrawGameOver(CgaRenderer renderer)
    {
        using var canvas = new SKCanvas(renderer.Bitmap);
        using var bg     = new SKPaint { Color = new SKColor(0, 0, 0, 210) };
        canvas.DrawRect(60, 80, 200, 40, bg);

        using var paint = new SKPaint { Color = CgaRenderer.Palette[2], IsAntialias = false };
        using var font  = new SKFont(SKTypeface.FromFamilyName("Courier New",
                              SKFontStyle.Bold) ?? SKTypeface.Default, 14f);
        canvas.DrawText("GAME OVER", 90f, 106f, font, paint);

        using var hint  = new SKPaint { Color = CgaRenderer.Palette[3], IsAntialias = false };
        using var hfont = new SKFont(SKTypeface.FromFamilyName("Courier New",
                              SKFontStyle.Normal) ?? SKTypeface.Default, 10f);
        canvas.DrawText("[Any key to continue]", 70f, 118f, hfont, hint);
    }

    // ── Utility ───────────────────────────────────────────────────────────────

    private void ShowMessage(string text)
    {
        _message  = text;
        _msgTimer = TimeSpan.FromSeconds(MsgDurationSecs);
    }
}

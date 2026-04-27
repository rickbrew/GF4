# Phase 1 Summary — Golden Flute IV Port

## Tools Installed (all portable, in `tools/`, gitignored)

| Tool | Version | Key path |
|------|---------|----------|
| Ghidra | 12.0.4 | `tools/ghidra/ghidra_12.0.4_PUBLIC/ghidraRun.bat` |
| JDK | 21.0.10+7 (Temurin) | `tools/jdk/jdk-21.0.10+7/bin/java.exe` |
| DOSBox-X | 2026.03.29 | `tools/dosbox-x/bin/x64/Release/dosbox-x.exe` |
| ffmpeg | master/win64-gpl | `tools/ffmpeg/ffmpeg-master-latest-win64-gpl/bin/ffmpeg.exe` |

---

## Asset Inventory (`1994/`)

### Graphics — all 63 .PIC files decoded to PNG in `docs/asset-dumps/`

Format: **raw 16 KB CGA video buffer**, 320×200, 2 bits/pixel, interleaved scanlines  
(even lines at 0x0000, odd lines at 0x2000, 80 bytes/line)

Palette confirmed (CGA mode 4, palette 1, high intensity):
- 0 = Black       `#000000`
- 1 = Cyan        `#55FFFF`
- 2 = Magenta     `#FF55FF`
- 3 = White       `#FFFFFF`

Decoder: `tools/decode_pics.py`

**PIC catalogue:**

| File | Purpose |
|------|---------|
| `GF4TITLE.PIC` | Main title screen |
| `TITLE1.PIC`, `TITLE2.PIC` | Additional title frames |
| `MENU.PIC` | Main menu background |
| `CHOOSE.PIC` | Character-select screen |
| `HELP.PIC` | In-game help overlay |
| `INTRO1–19.PIC` | Introduction slideshow (19 frames) |
| `CREDITS1–4.PIC` | Credits slides (4 frames) |
| `ENDING1–8.PIC` | Ending sequence (8 frames) |
| `GOBLIN1/2.PIC` | Goblin (2 combat frames — idle/hit?) |
| `ORC1/2.PIC` | Orc |
| `TROLL1/2.PIC` | Troll |
| `DRAGON1/2.PIC` | Dragon |
| `GIANT1/2.PIC` | Giant |
| `GARGOYL1/2.PIC` | Gargoyle |
| `MINOTAU1/2.PIC` | Minotaur |
| `ROBED1/2.PIC` | Robed Figure (boss?) |
| `SHOP1.PIC`, `SHOP2.PIC` | Shop screens (page 1 and page 2) |
| `HIT.PIC` | "POW!" hit animation overlay |
| `RIP.PIC` | Death/game-over screen |
| `LITENING.PIC` | Lightning spell effect |
| `ELECTRIC.PIC` | Electric spell effect |
| `FIERY.PIC` | Fire spell effect |
| `KNIFE.PIC`, `MACE.PIC`, `SWORD.PIC` | Weapon images |
| `GF4TITLE.PIC` | Title card |

### Audio (not being ported)

- `*.VOC` — Creative Voice digitized SFX (Rick's own work, can be ported later)
- `*.CMF` — Creative Music Format FM music (**do not use** — sourced from Jill of the Jungle)

### Fonts

- `GOTH.CHR`, `LITT.CHR`, `SANS.CHR`, `TRIP.CHR` — BGI stroke fonts  
  Used to render in-game text over .PIC backgrounds. Will need decoding or substitution.

### Data files

| File | Size | Notes |
|------|------|-------|
| `MONSTERS.DAT` | 416 bytes | Likely a Pascal typed array of monster records |
| `GF4.TAB` | 3 072 bytes | Map tile data or lookup table |
| `FADEORDR.DAT` | 32 768 bytes | Two 16 KB tables — pixel reveal order for screen transitions |

---

## Gameplay — Observed from Twitch VOD (5:18:31–5:27:48)

Frames extracted to `docs/video-frames/coarse/` (1 per 5s) and `docs/video-frames/dense/` (1–2 per sec, targeted).

### Screen flow

```
Rick Brewster Production splash (circular wipe in)
  → Intro slideshow (INTRO1-19.PIC, narrated story text)
  → Main Menu (MENU.PIC)
      I.  View Introduction
      II. Continue Quest
      III. Start New Quest
      IV. Quit
  → [III] Choose Your Hero (CHOOSE.PIC)
      Fighter (F) | Magic User (M) | Thief (T)
      Selectable by keyboard or mouse click
  → Map (tile-based top-down world)
      ↔ Combat (triggered by map encounter)
      ↔ Shop (entered via map building)
      ↔ Stats screen (S key)
```

### Map screen
- Top-down tile grid, cyan ground with speckled/dithered terrain variation
- Magenta-bordered regions for different areas
- Buildings shown as small icons (castle, house, shop)
- Player character = small dark figure
- Movement: arrow keys, one tile per keypress
- No diagonal movement (confirmed by docs)
- At least 2 distinct map regions visible (open field + denser structured area)

### Combat screen
- Monster .PIC image fills most of screen
- Top bar: `Your Health: N   [MonsterName]'s Health: N`
- Combat menu (bottom):
  ```
  1. Use Weapon
  2. Retreat
  3. [Use Magic — Magic User only?]
  4. Drink Potion
  Enter choice:
  ```
- Hit animation: `HIT.PIC` ("POW!") overlaid briefly
- Monsters confirmed in video: Giant Teddy Bear, Minotaur

### Shop screen (SHOP1.PIC / SHOP2.PIC)
- Gold shown top-left
- Page 1:
  ```
  1. Sword     20g  350HP
  2. Mace      30g  100HP
  3. Knife     20g   20HP (approx)
  4. Plate Armor    30g  400HP
  5. Chainmail      30g  250HP
  6. Leather Armor  20g  100HP (approx)
  7. Health Potion   3HP  50g
  8. Magic Potion    3MP  50g
  9. Page 2
  ```
- Page 2 exists (not fully captured)

### Stats screen (S key)
Partially readable from video (b_0030.png):
```
Fighter Statistics Sheet

[stat]:        4        Inventory:
Atk Level:     2          170 Gold (approx)
Luck Dice:   208          A Sword
[?] Level:     1          Leather Armor
[?] Dice:    100          1 Healing Potion(s)

Length:        6 (?)
Maturity:      1

Press any key or mouse button to continue
```
Note: "Length" and "Maturity" may be stat names unique to this game.

### Screen transitions
- Circular wipe (uses `FADEORDR.DAT` pixel-order table) on title splash
- Fade/dissolve between screens
- `FADEORDR.DAT` = 32768 bytes = two 16384-byte tables, likely two directions of reveal

---

## Key Unknowns Remaining

1. **Map format** — `GF4.TAB` (3 KB) is the likely map data. Is it a flat tile array? Is there more than one map?
2. **BGI font rendering** — Game uses `GOTH.CHR` etc. for in-game text. We need to either decode the stroke font format or substitute a similar free font.
3. **Full stats structure** — Exact field names and formulas not readable from video.
4. **Magic system** — Magic User class presumably has option 3 (Use Magic) in combat. Spell types unknown.
5. **Complete monster roster** — `MONSTERS.DAT` (416 bytes) will reveal all.
6. **Combat math** — Attack/damage formulae, luck dice usage, retreat probability, etc.
7. **Secret codes** — Doc hints at undocumented key combos. May surface in disassembly.
8. **GF4GAME.EXE structure** — Main analysis target for Phase 2.

---

## Phase 2 Plan

1. **Binary data decoding** (Sonnet-tier)
   - Reverse `MONSTERS.DAT` by inspection (416 bytes ÷ likely 8–13 monsters = ~32–52 bytes/record)
   - Reverse `GF4.TAB` (map tile table)
   - Reverse `FADEORDR.DAT` (confirm two 16 KB pixel-order tables)

2. **Ghidra analysis of GF4GAME.EXE** (Opus-tier) — needs heavy reasoning
   - Load as 16-bit x86, apply Turbo Pascal RTL FLIRT signatures
   - Isolate user code from RTL
   - Recover main loop, state machine, combat logic, map engine
   - Document all findings in `docs/disasm-notes.md`

3. **Scaffold C# port** (Sonnet-tier once spec is clear)
   - `dotnet new avalonia` project in `port/`
   - PIC loader (port `decode_pics.py` logic to C#/SkiaSharp)
   - 320×200 render surface with 4× integer scaling (configurable)
   - Title screen + main menu working end-to-end

4. **Iterative game logic port** (mixed Sonnet/Opus)
   - Fill in game states one by one, cross-checking against video frames

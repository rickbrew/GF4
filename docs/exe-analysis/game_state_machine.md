# GF4GAME.EXE — Game State Machine (decoded)

This is the actual game architecture as recovered from disassembly. All
addresses are `segment:offset` in Ghidra's memory map; for the file offset
subtract the header (10,224 bytes) and add the segment-paragraph value.

## Top-level call graph

```
entry (1000:a657)              Pascal program body — the absolute root
├── RTL inits (1b5b, 1b9f, 1bfc, 1c14, 1f51, 2110, 2176, 219e)
├── 1c14:1134                  Graph (BGI) init — registers all .CHR fonts
├── 1c14:0928                  Set graphics mode (CGA 320×200)
├── 0447                       (early credits / startup screen?)
├── 72cf                       INTRO sequence (INTRO1.PIC … INTRO19.PIC)
├── 7697                       Load-game path: dispatcher
│   ├── 1138                   load_game (reads SAVEGAME.DAT)
│   └── 687f                   ★ MAIN GAME / WORLD LOOP ★
├── 915b                       CHARACTER SELECT (CHOOSE.PIC + 3 click zones)
│   ├── 8fbf                   class=1 Fighter   → 1ec9 → 76f9 → 687f
│   ├── 8ffd                   class=2 Mage      → 1ec9 → 76f9 → 687f
│   └── 903b                   class=3 Thief     → 1ec9 → 76f9 → 687f
└── a2e3                       Exit farewell ("Thank you for playing…")
```

The main game loop is **`FUN_1000_687f`**, called from both new-game and
load-game paths.

## Class roster — confirmed three classes

| Class      | Hotkey | Init wrapper | Voice file   |
|------------|--------|--------------|--------------|
| Fighter    | F      | 1000:8fbf    | FIGHTER.VOC  |
| Mage       | M      | 1000:8ffd    | MAGIC.VOC    |
| Thief      | T      | 1000:903b    | THIEF.VOC    |

Earlier guess was Fighter+Thief only — the strings dump only contained
the literal `Fighter` and `Thief` words, but the click-zone code at
`1000:915b` and the class-stat block at `1000:1ec9` confirm three.

## Player record (40 bytes at DGROUP:0x11d4 .. 0x11fb)

The stat block lives in the data segment at offset `0x11d4`. After class
selection, `FUN_1000_1ec9` writes the entire block based on `class_id`:

| Offset  | Size | Field                | Fighter | Mage | Thief |
|---------|------|----------------------|---------|------|-------|
| `11d4`  | word | **HP / Health**      |    8    |   5  |   6   |
| `11d6`  | word | **Attack Level**     |    5    |   3  |   6   |
| `11d8`  | word | **Attack Die**       |    3    |   1  |   2   |
| `11da`  | word | **Defend Level**     |    2    |   4  |   2   |
| `11dc`  | word | **Defend Die**       |    4    |   2  |   4   |
| `11de`  | word | (Strength?)          |    3    |   1  |   2   |
| `11e0`  | word | (Dexterity?)         |    2    |   4  |   2   |
| `11e2`  | word | **Gold**             |   50    |  50  |  75   |
| `11e4`  | word | **Magic Points**     |    0    |  10  |   0   |
| `11e6`  | word | Magic Experience     |    0    |   1  |   0   |
| `11e8`  | word | (XP?)                |    6    |   2  |   4   |
| `11ea`  | word | (some stat)          |    4    |   8  |  12   |
| `11ec`  | byte | inv flag             |    1    |   0  |   0   |
| `11ed`  | byte | inv flag             |    0    |   0  |   0   |
| `11ee`  | byte | inv flag (Knife?)    |    0    |   1  |   1   |
| `11ef`  | byte | inv flag             |    0    |   0  |   0   |
| `11f0`  | byte | inv flag             |    0    |   0  |   0   |
| `11f1`  | byte | inv flag             |    1    |   0  |   0   |
| `11f2`-`11f7` | bytes | misc inventory | varies  |      |       |
| `11f8`  | word | **Healing Potions**  |    1    |   1  |   1   |
| `11fa`  | word | **Magic Potions**    |    0    |   1  |   0   |

Total = 40 bytes (= 0x28), matching the load-game read of 40 bytes.

## World map — 100×100 grid, 3 bytes per cell

Stored at DGROUP:`0x10cd`. Layout per cell:

| Byte | Field                | Range                        |
|------|----------------------|------------------------------|
| 0    | Terrain type         | 1, 2, 3, 4 (passable); 5, 6, 7, 8 (walls) |
| 1-2  | Encounter code (word)| 0 = none; 1-7 = monsters; 8 = final boss; 9 = special; 10 = gold |

**Tile-type → graphic-index mapping:** the renderer uses a far-pointer
lookup table at `DS:0x874c`. Each entry is 4 bytes (far ptr).
Type codes 8, 9 are referenced via `*(undefined4 *)0x8760` / `0x8764` in
`graphics_init` (1000:4cbe), so these are special-case overrides.

**Procedural map gen (`FUN_1000_76f9`):**

| Encounter | Count | Meaning                                             |
|-----------|-------|-----------------------------------------------------|
| 9         |   15  | "Special" — likely shop entrances                   |
| 10        |   10  | Gold pickup (clears self when stepped on)           |
| 8         |    1  | **The final boss** (one and only one)               |
| 7         |   50  | Strong monster                                      |
| 6         |  100  | Mid-tier monster                                    |
| 5         |  100  | Mid-tier monster                                    |
| 4         |  100  | Mid-tier monster                                    |
| 3         |   75  | Weak monster                                        |
| 2         |  110  | Weakest monster                                     |
| 1         |  175  | Weakest monster                                     |

Total = 736 encounters scattered across 10,000 tiles (~7% density).

Terrain map is also generated procedurally:
- Borders (rows 1, last row, cols 1-9 and 91-99) are walls (codes 5-8)
- Inner grid is filled with 3 (default ground)
- Some random patches of types 1, 2, 4 are scattered
- 25 random clusters of "type 4" 7×7 squares are placed (with centre point)

## Game-loop key bindings (from `FUN_1000_687f`)

| Key           | Scan code | Action                                      |
|---------------|-----------|---------------------------------------------|
| ↑ Up          | `0x48`    | Move up (set facing=3, `playerY--`)         |
| ↓ Down        | `0x50`    | Move down (set facing=4, `playerY++`)       |
| ← Left        | `0x4b`    | Move left (set facing=1, `playerX--`)       |
| → Right       | `0x4d`    | Move right (set facing=2, `playerX++`)      |
| Q             | `0x10`    | **Quit to title** (StopMusic; return)       |
| F5            | `0x1f`    | Reload/restart music                        |
| F1            | `0x3b`    | (calls `FUN_1000_5c46` — small dispatcher)  |
| F10           | `0x68`    | Show help screen (`FUN_1000_6165`)          |
| S / s         |  —        | Show **Stats screen** (`FUN_1000_172b`)     |
| H / h         |  —        | **Drink Healing Potion** (HP +N, max 24)    |
| M / m         |  —        | **Drink Magic Potion** (MP +N, Mage only)   |
| `*` / `/`     |  —        | **CHEAT**: set HP to typed value            |
| `+`           |  —        | **CHEAT**: set Gold to typed value          |
| `-`           |  —        | **CHEAT**: set Magic Points to typed value  |

The `Alt+2+5+5` numpad cheat from the easter-egg string is *not* in this
loop — it must be handled at a different level (probably the CHOOSE screen
or directly by the BIOS keyboard interrupt, since Alt+digit on the numpad
generates a literal char). Worth searching for `0xff` immediate compares
as we trace deeper.

## Player position globals

| Addr     | Size | Field                                    |
|----------|------|------------------------------------------|
| `0x445`  | byte | **Facing direction** (1=L, 2=R, 3=U, 4=D)|
| `0x446`  | byte | **isLoadedFromSave** (0=new game, 1=loaded) |
| `0x42d`  | byte | **soundBlasterPresent** (set at boot)    |
| `0x42e`  | word | (set by `FUN_219e_0285` at startup)      |
| `0x430`  | byte | (init flag, set to 0)                    |
| `0xef34` | byte | **isMonochrome** (0=color, 1=mono)       |
| `0xef1c`-`0xef20` | bytes | **text colors** (palette indices) |
| `0x11cb` | word | **playerX** (1-100)                      |
| `0x11cd` | word | **playerY** (1-100)                      |
| `0x11d3` | byte | **playerClass** (1=Fighter, 2=Mage, 3=Thief) |

On new-game start, `687f` initialises position to `(50, 50)` (centre of map),
facing 4 (down). Loaded saves restore from file.

## SAVEGAME.DAT format

Sequential read order from `FUN_1000_1138`:

```
Header (saved-name list?):
  9 × 30 bytes   = 270 bytes — slot directory (player names? not yet confirmed)

[user picks slot 1-9, then opens a slot file constructed at 0x1047]

Per-slot file:
  30000 bytes  → 0x11fc  — full 100×100×3 map snapshot
     40 bytes  → 0x11d4  — player stat block (above table)
      1 byte   → 0x11d3  — player class
      2 bytes  → 0x11cb  — playerX
      2 bytes  → 0x11cd  — playerY
      1 byte   → 0x445   — facing direction
```

Total per-slot payload: **30,046 bytes**.

The 30 KB map snapshot in saves means the game saves the *generated* map,
not a seed — every save is a unique world.

## Combat flow (encounter 1-8 → `FUN_1000_43f7`)

When the player steps on a non-zero encounter cell with code < 9:
1. `687f` calls `4cbe` to redraw the screen
2. Stops music, plays BUZZER.VOC (or speaker beep)
3. Calls `FUN_1000_43f7(playerY, playerX, encounterCode)` — combat dispatch
4. Return value:
   - `1` or `3` → game ends (player won? or died?). Returns from main loop.
   - other → resume game-loop, restart FUNKY.CMF

`FUN_1000_43f7` (2,215 bytes) is the **combat manager**. It references
`SCREAM.VOC` and `FUNKY.CMF`. Internally it dispatches to specific monster
fight screens (DRAGON1/2.PIC, ORC1/2.PIC, etc.) — TBD which encounter code
maps to which monster.

## Pascal-unit identification (refined)

| Seg      | Confirmed identity                                     |
|----------|--------------------------------------------------------|
| `1b24`   | Custom **Mouse** unit (referenced from CHOOSE click zones) |
| `1b5b`   | Pascal RTL — **System** core                           |
| `1b9f`   | (small util unit)                                      |
| `1bfc`   | **Mouse polling** unit (`FUN_1bfc_0050(1)` = button-down test) |
| `1c14`   | **Graph (BGI)** unit — `OutTextXY`, `SetColor`, etc.   |
| `1f6f`   | PC speaker / sound unit (`FUN_1f6f_02b7(20)` = beep)   |
| `20e5`   | **CMF / VOC playback** unit (PLAY-CMF.COM helper)      |
| `2110`   | Math + delay unit (`FUN_2110_02e9(N)` = Delay(N) ms)   |
| `2176`   | SETSPEED.EXE launcher unit                             |
| `218e`   | (tiny unit)                                            |
| `219e`   | Pascal RTL — DOS unit (file I/O, `Random`, `Halt`)     |
| `22f5`   | Day-of-week table unit                                 |

## Function name proposal (for renaming in Ghidra)

If we re-run Ghidra with these names applied, decompilation will be much
more readable:

```
1000:0015  → InitGameVars
1000:0447  → ShowCreditsScreen
1000:080a  → PlayCMFFile
1000:1138  → LoadSavedGame
1000:172b  → ShowStatsScreen
1000:1ec9  → InitClassStats
1000:21a4  → PlayCMF_Starfm
1000:2313  → PlayBuzzerSound1
1000:2625  → CastSpellFiery
1000:3316  → DrawHealthBar
1000:34fa  → CombatHelper1
1000:3749  → CombatHelper2
1000:3a11  → PlayBuzzerSound2
1000:3cb4  → CombatMenuPrompt
1000:43f7  → CombatManager
1000:4cbe  → DrawWorldMap
1000:50a6  → ShopWeaponsArmour
1000:5674  → ShopPotionsSpells
1000:5be6  → SpecialEncounter9   (encounter code 9 - shop entrance)
1000:5c46  → F1HelperDispatch
1000:6165  → ShowHelpScreen
1000:687f  → WorldGameLoop
1000:72cf  → PlayIntroSequence
1000:7697  → LoadGameDispatch
1000:76f9  → InitializeWorldMap
1000:8fbf  → InitClassFighter
1000:8ffd  → InitClassMage
1000:903b  → InitClassThief
1000:9077  → DelayMs (52-byte helper)
1000:90b3  → AnimateBlinkFrame
1000:90dc  → MouseInRect (mouse hit test)
1000:915b  → CharacterSelect
1000:a2e3  → ExitFarewell
1000:a657  → entry / pascal_main
```

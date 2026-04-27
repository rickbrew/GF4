# GF4GAME.EXE function map (Ghidra-derived, hand-annotated)

Pascal main-program body lives at `1000:a657` (3033 bytes).
All addresses below are `segment:offset` as Ghidra reports them.

## Memory layout

| Block | Range | Size | Purpose |
|-------|-------|------|---------|
| HEADER | 0..27EF | 10 KB | MZ header + reloc table |
| CODE_0 | 1000:0000-b23f | 45 KB | **Main program** code + inline data |
| CODE_1..15 | 1b24..22f5 | ~32 KB | **Pascal units** (one per CODE_n segment) |
| DATA | 22f5:0260+ | ~1.9 KB initialized + BSS | Globals, day-of-week tables, etc. |

The BGI font reference table (`BOLD.CHR`, `TRIP.CHR`, …) lives at `1c14:2e66` —
that segment is the **Graph unit**.

## Game-procedure identification

Functions are listed in CODE_0 order (top-down through the program).
Distinctive string anchors are listed; confidence is **high** when the function
references a unique string, **medium** when inferred from neighboring functions.

| Addr | Bytes | Refs in | Anchor strings | Likely role |
|------|-------|---------|----------------|-------------|
| `1000:0015` | 131 | 1 | (none distinct) | Probably a small init helper or constant table |
| `1000:0447` | 860 | 1 | `Credits: ` | **Credits / stats line print** |
| `1000:07a7` | 99 | 1 | (RTL only) | Helper |
| `1000:080a` | 2257 | 1 | `PLAY-CMF.COM`, `SETSPEED.EXE` | **CMF music play / startup helper** |
| `1000:1138` | 955 | 1 | `Loading...` | **LoadGame** body |
| `1000:172b` | 1942 | 2 | `DOS Erorr #` (sic) | **DOS error reporter** |
| `1000:1ec9` | 496 | 3 | (RTL only) | Inner helper |
| `1000:21a4` | 231 | 1 | `STARFM.CMF` | Music-cue helper for one screen |
| `1000:2313` | 662 | 1 | `BUZZER.VOC` | Combat hit-sound wrapper |
| `1000:2625` | 2517 | 1 | `FIERY.PIC` | **Spell: Fiery (fire spell)** |
| `1000:3316` | 377 | 7 | `Your Health: ` | **Health bar / status renderer** |
| `1000:34fa` | 492 | 1 | (RTL only) | Helper |
| `1000:3749` | 618 | 1 | (RTL only) | Combat-sub helper |
| `1000:3a11` | 531 | 1 | `BUZZER.VOC` | Another combat-hit wrapper |
| `1000:3cb4` | 768 | 1 | (combat-jump pattern) | **Combat dispatch** (option chooser) |
| `1000:3fe8` | 338 | 1 | (RTL only) | Helper |
| `1000:4189` | 417 | 1 | (RTL only) | Helper |
| `1000:43f7` | 2215 | 1 | `SCREAM.VOC`, `FUNKY.CMF` | **Boss encounter or hidden screen** |
| `1000:4cbe` | 884 | 2 | `EGAVGA` | **Graphics-driver init** (BGI EGAVGA.BGI) |
| `1000:503d` | 56 | 14 | `BUZZER.VOC` | Generic small helper called 14× |
| `1000:50a6` | 1437 | 1 | `SHOP1.PIC` + 8 sub-options | **Shop 1 (weapons/armour)** |
| `1000:5674` | 1373 | 1 | `SHOP2.PIC` + 6 sub-options | **Shop 2 (potions/spells)** |
| `1000:5be6` | 79 | 1 | (RTL only) | Helper |
| `1000:5d15` | 537 | 1 | (RTL only) | Helper |
| `1000:6165` | 1682 | 1 | `This is a beach, or a clump of sand.` | **Help screen / map legend** |
| `1000:687f` | 2289 | 2 | `BUZZER.VOC`, `GLASS.VOC` | **Combat encounter** (mid-tier monster) |
| `1000:72cf` | 959 | 2 | `INTRO3.PIC INTRO4.PIC INTRO5.PIC INTRO6.PIC` | **Intro story sequence** |
| `1000:7697` | 49 | 2 | (RTL only) | Helper |
| `1000:76f9` | **6330** | 3 | `SAVEGAME.DAT`, `Initializing Map, Please wait...` | **★ Main game / world loop ★** |
| `1000:8fbf` | 52 | 36 | (RTL only) | RTL helper, very common |
| `1000:8ffd` | 52 | 36 | `MAGIC.VOC` | Spell-cast sound stub |
| `1000:903b` | 52 | 36 | `THIEF.VOC` | Thief-class sound stub |
| `1000:9077` | 52 | 20 | (RTL only) | RTL helper |
| `1000:90b3` | 41 | 8 | (RTL only) | Helper |
| `1000:90dc` | 85 | 54 | (RTL only) | **Hot RTL helper** (used 54×) |
| `1000:915b` | **4435** | 2 | `CHOOSE.PIC` | **★ Character selection screen ★** |
| `1000:a2e3` | 102 | 2 | `Thank you for playing The Golden Flute IV. SEEYA.VOC` | **Exit / farewell** |
| `1000:a351` | 117 | 23 | (RTL only) | Hot RTL helper |
| `1000:a657` | **3033** | 1 | `SPEED.DAT`, `Press a key or mouse button to play`, `SANS.CHR` | **★ Pascal program body — game's true entry ★** |

## Key observations

- **The "main game loop" is `1000:76f9`** at 6,330 bytes (the largest function).
  It references `SAVEGAME.DAT` and `Initializing Map, Please wait...`, so it
  contains both the world-map navigation AND save handling. Combat probably
  branches off as a sub-call.
- **Character select is `1000:915b`** at 4,435 bytes — large because each class
  (Fighter / Thief) has its own initialisation logic.
- **The Pascal program body is `1000:a657`** — entry point. It does:
  - SPEED.DAT bootstrap
  - Calls SANS.CHR font registration
  - Plays title sequence
  - Shows "Press a key or mouse button to play" prompt
  - Calls the menu, char select, and main loop in sequence

## Pascal-unit segment guide

| Seg | Function count | Likely unit |
|-----|----------------|-------------|
| `1b24` | 2 | (small unit — possibly a custom Mouse unit) |
| `1b5b` | 6 | **Pascal RTL System** core |
| `1b9f` | 5 | Small unit (string/util) |
| `1bfc` | 7 | Helper unit |
| `1c14` | 24 | **Graph (BGI) unit** — confirmed by .CHR refs |
| `1f14` | 3 | Small unit |
| `1f51` | 3 | Small unit |
| `1f6f` | 2 | Small unit |
| `1fab` | 1 | Tiny unit |
| `20e5` | 4 | **CMF/sound helper unit** (PLAY-CMF.COM, GF4.CFG, SETUP.EXE refs) |
| `2110` | 8 | Math unit (`SQR` reference) |
| `2176` | 2 | **SETSPEED-launcher unit** |
| `218e` | 1 | Tiny unit |
| `219e` | ~30 | **Pascal RTL System** (large, has "Runtime error " string) |
| `22f5` | 1 | Day-of-week table data + tiny init |

The two largest unit segments (`1c14` Graph and `219e` System) carry the bulk
of the RTL. Custom game-logic units, if any, are in the smaller segments.

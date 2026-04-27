using System;
using System.IO;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Root asset loader.  Finds the 1994/ game data directory relative to the
/// executable (dev layout: repo-root/1994/) and exposes all loaded assets.
/// </summary>
public sealed class GameData
{
    public string AssetDir { get; }

    // Pre-loaded binary assets
    public TileSet       Tiles     { get; }
    public MonsterRecord[] Monsters { get; }
    public FadeTable     Fade      { get; }

    public GameData(string? assetDir = null)
    {
        AssetDir = assetDir ?? LocateAssetDir();

        Tiles    = new TileSet(Asset("GF4.TAB"));
        Monsters = MonsterData.Load(Asset("MONSTERS.DAT"));
        Fade     = new FadeTable(Asset("FADEORDR.DAT"));
    }

    /// <summary>
    /// Return the full path of <paramref name="filename"/> inside the asset directory.
    /// Filename is uppercased to match the original DOS-era 8.3 naming convention,
    /// which keeps things working on case-sensitive filesystems too.
    /// </summary>
    public string Asset(string filename) =>
        Path.Combine(AssetDir, filename.ToUpperInvariant());

    /// <summary>
    /// Decode and return a .PIC file as a flat palette-index array (320×200).
    /// </summary>
    public byte[] LoadPic(string filename) =>
        PicLoader.Load(Asset(filename));

    // ── private ───────────────────────────────────────────────────────────────

    private static string LocateAssetDir()
    {
        // Walk up from the executable location looking for "1994/"
        var dir = new DirectoryInfo(AppContext.BaseDirectory);
        while (dir != null)
        {
            string candidate = Path.Combine(dir.FullName, "1994");
            if (Directory.Exists(candidate))
                return candidate;
            dir = dir.Parent;
        }
        throw new DirectoryNotFoundException(
            "Cannot find '1994/' asset directory. Run from repo root or set assetDir.");
    }
}

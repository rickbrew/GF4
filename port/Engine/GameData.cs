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

        Tiles    = new TileSet(Pic("GF4.TAB"));
        Monsters = MonsterData.Load(Pic("MONSTERS.DAT"));
        Fade     = new FadeTable(Pic("FADEORDR.DAT"));
    }

    /// <summary>Return full path for a file in the asset directory.</summary>
    public string Pic(string filename) =>
        Path.Combine(AssetDir, filename.ToUpperInvariant());

    /// <summary>
    /// Decode and return a .PIC file as a flat palette-index array (320×200).
    /// </summary>
    public byte[] LoadPic(string filename) =>
        PicLoader.Load(Pic(filename));

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

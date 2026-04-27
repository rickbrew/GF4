using System;
using GoldenFluteIV.Engine;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Shows GF4TITLE.PIC and waits for any key (or left-click) before advancing.
/// Original game likely fades in from black; we display it directly for now.
/// TODO: implement FADEORDR.DAT fade-in once the game engine is further along.
/// </summary>
public sealed class TitleScreen : IGameScreen
{
    private readonly GameData _data;
    private byte[]?  _picPixels;
    private TimeSpan _elapsed;

    public TitleScreen(GameData data)
    {
        _data = data;
    }

    public void OnEnter()
    {
        _picPixels = _data.LoadPic("GF4TITLE.PIC");
        _elapsed   = TimeSpan.Zero;
        // TODO(audio): play TITLE.VOC here
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        _elapsed += dt;

        // Wait at least one rendered frame before accepting input so a held-down
        // key from a previous screen doesn't skip through instantly.
        if (_elapsed < TimeSpan.FromMilliseconds(100))
            return null;

        if (input.Confirm || input.LastKey.HasValue || input.MouseLeft)
            return new MainMenuScreen(_data);

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        if (_picPixels is not null)
            renderer.BlitIndexed(_picPixels);
        else
            renderer.Clear(0);
    }

    public void OnExit()
    {
        _picPixels = null;
    }
}

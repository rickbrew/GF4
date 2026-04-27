using System;
using GoldenFluteIV.Engine;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Shows INTRO1.PIC … INTRO19.PIC as a slideshow, one frame at a time.
/// Any key or left-click advances to the next frame; Escape aborts the whole
/// sequence.  After the last frame, control returns to <paramref name="returnTo"/>.
///
/// Original: FUN_1000_72cf (PlayIntroSequence) and FUN_1000_5d15.
/// The originals also play CMF music and BGI-rendered text between slides;
/// we just show the raw PIC files since sound is deferred.
/// </summary>
public sealed class IntroScreen : IGameScreen
{
    private readonly GameData   _data;
    private readonly IGameScreen _returnTo;

    private int      _frame;     // 1-based, 1..FrameCount
    private byte[]?  _pixels;
    private TimeSpan _elapsed;

    private const int    FrameCount      = 19;
    private const double SecsPerFrame    = 2.5;   // auto-advance if player doesn't skip

    public IntroScreen(GameData data, IGameScreen returnTo)
    {
        _data     = data;
        _returnTo = returnTo;
    }

    public void OnEnter()
    {
        _frame   = 1;
        _elapsed = TimeSpan.Zero;
        LoadFrame();
        // TODO(audio): play intro music / INTRO.VOC here
    }

    public IGameScreen? Update(TimeSpan dt, InputState input)
    {
        _elapsed += dt;

        bool abort   = input.Cancel;
        bool advance = input.Confirm || input.LastKey.HasValue || input.MouseLeft;

        if (abort)
            return _returnTo;

        if (advance || _elapsed.TotalSeconds >= SecsPerFrame)
        {
            _frame++;
            if (_frame > FrameCount)
                return _returnTo;

            _elapsed = TimeSpan.Zero;
            LoadFrame();
        }

        return null;
    }

    public void Render(CgaRenderer renderer)
    {
        if (_pixels is not null)
            renderer.BlitIndexed(_pixels);
        else
            renderer.Clear(0);
    }

    public void OnExit()
    {
        _pixels = null;
        // TODO(audio): stop intro music here
    }

    private void LoadFrame()
    {
        try   { _pixels = _data.LoadPic($"INTRO{_frame}.PIC"); }
        catch { _pixels = null; }
    }
}

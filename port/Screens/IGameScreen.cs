using System;
using GoldenFluteIV.Engine;

namespace GoldenFluteIV.Screens;

/// <summary>
/// Contract for a full-screen game state (title, world map, combat, shop, etc.)
/// </summary>
public interface IGameScreen
{
    /// <summary>
    /// Called once when the screen is made active.
    /// Load per-screen assets, reset state.
    /// </summary>
    void OnEnter();

    /// <summary>
    /// Advance game logic by <paramref name="dt"/>.
    /// Return a non-null screen to transition to that screen next frame,
    /// or null to stay on this screen.
    /// </summary>
    IGameScreen? Update(TimeSpan dt, InputState input);

    /// <summary>
    /// Draw the current frame into <paramref name="renderer"/>.
    /// </summary>
    void Render(CgaRenderer renderer);

    /// <summary>
    /// Called when the screen is being replaced.
    /// Release any per-screen resources.
    /// </summary>
    void OnExit() { }
}

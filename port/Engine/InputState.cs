using Avalonia.Input;

namespace GoldenFluteIV.Engine;

/// <summary>
/// Snapshot of keyboard/mouse input for one game frame.
/// Populated by GameCanvas before calling IGameScreen.Update().
/// </summary>
public sealed class InputState
{
    // --- Keyboard ---
    public bool Up      { get; set; }
    public bool Down    { get; set; }
    public bool Left    { get; set; }
    public bool Right   { get; set; }
    public bool Confirm { get; set; }   // Enter / Space
    public bool Cancel  { get; set; }   // Escape
    public Key? LastKey { get; set; }   // any key pressed this frame

    // --- Mouse ---
    public double MouseX     { get; set; }  // logical CGA coordinates (0-319, 0-199)
    public double MouseY     { get; set; }
    public bool   MouseLeft  { get; set; }
    public bool   MouseRight { get; set; }

    public void Reset()
    {
        Up = Down = Left = Right = Confirm = Cancel = false;
        MouseLeft = MouseRight = false;
        LastKey = null;
    }
}

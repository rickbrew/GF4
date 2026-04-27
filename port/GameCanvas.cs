using System;
using System.Runtime.InteropServices;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Input;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Platform;
using Avalonia.Threading;
using GoldenFluteIV.Engine;
using GoldenFluteIV.Screens;

namespace GoldenFluteIV;

/// <summary>
/// Custom Avalonia control that hosts the entire game.
/// Owns the CGA framebuffer (CgaRenderer), the game-loop timer, and the
/// screen state machine.  Renders each frame by copying the CGA pixel buffer
/// into an Avalonia WriteableBitmap, then drawing that bitmap scaled up to
/// the control's actual pixel size.
///
/// Scale is controlled by the Viewbox in MainWindow.axaml; the control itself
/// always measures at exactly 1280×800 (320×200 × 4).
/// </summary>
public sealed class GameCanvas : Control
{
    // ── Constants ─────────────────────────────────────────────────────────────
    public  const int DefaultScale = 4;
    private const int LogicalW     = CgaRenderer.Width  * DefaultScale;   // 1280
    private const int LogicalH     = CgaRenderer.Height * DefaultScale;   // 800

    // ── Game state ────────────────────────────────────────────────────────────
    private readonly CgaRenderer    _renderer;
    private readonly GameData       _data;
    private          IGameScreen    _screen;
    private readonly InputState     _input   = new();
    private          DispatcherTimer? _timer;
    private          DateTime       _lastTick;

    // ── Display bitmap ────────────────────────────────────────────────────────
    // WriteableBitmap is the stable Avalonia public API for pixel-level writes.
    // Each frame we MemoryMarshal.AsBytes the CgaRenderer pixel span and copy it
    // into this bitmap; no pinning, no extra allocation.
    private readonly WriteableBitmap _display;

    public GameCanvas()
    {
        _renderer = new CgaRenderer();
        _data     = new GameData();
        _screen   = new MainMenuScreen(_data);

        _display  = new WriteableBitmap(
            new PixelSize(CgaRenderer.Width, CgaRenderer.Height),
            new Vector(96, 96),
            PixelFormat.Bgra8888,
            AlphaFormat.Opaque);

        Focusable = true;
    }

    // ── Avalonia lifecycle ────────────────────────────────────────────────────

    protected override void OnAttachedToVisualTree(VisualTreeAttachmentEventArgs e)
    {
        base.OnAttachedToVisualTree(e);
        _screen.OnEnter();
        _lastTick = DateTime.UtcNow;

        _timer = new DispatcherTimer(DispatcherPriority.Render)
        {
            Interval = TimeSpan.FromMilliseconds(16)   // ~60 fps
        };
        _timer.Tick += OnTick;
        _timer.Start();
        Focus();
    }

    protected override void OnDetachedFromVisualTree(VisualTreeAttachmentEventArgs e)
    {
        _timer?.Stop();
        _timer = null;
        _screen.OnExit();
        _renderer.Dispose();
        _display.Dispose();
        base.OnDetachedFromVisualTree(e);
    }

    // ── Game loop ─────────────────────────────────────────────────────────────

    private void OnTick(object? sender, EventArgs e)
    {
        var now = DateTime.UtcNow;
        var dt  = now - _lastTick;
        _lastTick = now;

        // Clamp: don't let a long pause produce a huge dt jump
        if (dt > TimeSpan.FromMilliseconds(200))
            dt = TimeSpan.FromMilliseconds(200);

        var next = _screen.Update(dt, _input);
        _input.Reset();

        if (next is not null)
        {
            _screen.OnExit();
            _screen = next;
            _screen.OnEnter();
        }

        _screen.Render(_renderer);
        InvalidateVisual();
    }

    // ── Rendering ─────────────────────────────────────────────────────────────

    public override void Render(DrawingContext context)
    {
        // Copy the CGA pixel buffer (BGRA8888) into the WriteableBitmap.
        // The source is a ReadOnlySpan<uint> over the pinned pixel array.
        // The destination is Avalonia's locked bitmap address (IntPtr), so
        // we still need one unsafe cast for the destination Span — unavoidable.
        using (var fb = _display.Lock())
        {
            var src = MemoryMarshal.AsBytes(_renderer.Pixels);
            unsafe
            {
                var dst = new Span<byte>(fb.Address.ToPointer(), src.Length);
                src.CopyTo(dst);
            }
        }

        // Draw scaled to fill our control bounds (Viewbox handles overall scaling)
        var destRect = new Rect(0, 0, Bounds.Width, Bounds.Height);
        var srcRect  = new Rect(0, 0, CgaRenderer.Width, CgaRenderer.Height);
        context.DrawImage(_display, srcRect, destRect);
    }

    protected override Size MeasureOverride(Size availableSize) =>
        new(LogicalW, LogicalH);

    // ── Input ─────────────────────────────────────────────────────────────────

    protected override void OnKeyDown(KeyEventArgs e)
    {
        base.OnKeyDown(e);
        _input.LastKey = e.Key;
        // NOTE: Only arrow keys are mapped to movement booleans so that letter keys
        // (S=stats, H=heal, M=magic, Q=quit) can be read from input.LastKey by the
        // active screen without conflict.  This is faithful to the original game which
        // used arrow keys exclusively for world movement.
        switch (e.Key)
        {
            case Key.Up:                  _input.Up      = true; break;
            case Key.Down:                _input.Down    = true; break;
            case Key.Left:                _input.Left    = true; break;
            case Key.Right:               _input.Right   = true; break;
            case Key.Return or Key.Space: _input.Confirm = true; break;
            case Key.Escape:              _input.Cancel  = true; break;
        }
        e.Handled = true;
    }

    protected override void OnPointerMoved(PointerEventArgs e)
    {
        base.OnPointerMoved(e);
        // Guard against pointer events arriving before the first layout pass —
        // Bounds is (0, 0) at that point and division would produce NaN/Infinity.
        if (Bounds.Width <= 0 || Bounds.Height <= 0) return;

        var pos = e.GetPosition(this);
        // Map from display pixels back to CGA logical coordinates
        _input.MouseX = pos.X * CgaRenderer.Width  / Bounds.Width;
        _input.MouseY = pos.Y * CgaRenderer.Height / Bounds.Height;
    }

    protected override void OnPointerPressed(PointerPressedEventArgs e)
    {
        base.OnPointerPressed(e);
        var props = e.GetCurrentPoint(this).Properties;
        if (props.IsLeftButtonPressed)  _input.MouseLeft  = true;
        if (props.IsRightButtonPressed) _input.MouseRight = true;
    }
}

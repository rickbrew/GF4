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
    // We pin the CgaRenderer pixel buffer and MemoryCopy into it each frame.
    private readonly WriteableBitmap _display;

    public GameCanvas()
    {
        _renderer = new CgaRenderer();
        _data     = new GameData();
        _screen   = new TitleScreen(_data);

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
        // CgaRenderer keeps its uint[] pinned so we can grab the raw pointer.
        using (var fb = _display.Lock())
        {
            unsafe
            {
                Buffer.MemoryCopy(
                    source:              _renderer.PinnedPtr.ToPointer(),
                    destination:         fb.Address.ToPointer(),
                    destinationSizeInBytes: (long)fb.RowBytes * CgaRenderer.Height,
                    sourceBytesToCopy:   (long)CgaRenderer.Width * CgaRenderer.Height * 4);
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
        switch (e.Key)
        {
            case Key.Up    or Key.W: _input.Up      = true; break;
            case Key.Down  or Key.S: _input.Down    = true; break;
            case Key.Left  or Key.A: _input.Left    = true; break;
            case Key.Right or Key.D: _input.Right   = true; break;
            case Key.Return or Key.Space: _input.Confirm = true; break;
            case Key.Escape:         _input.Cancel  = true; break;
        }
        e.Handled = true;
    }

    protected override void OnPointerMoved(PointerEventArgs e)
    {
        base.OnPointerMoved(e);
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

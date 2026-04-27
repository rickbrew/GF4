using Avalonia.Controls;

namespace GoldenFluteIV;

/// <summary>
/// Shell window. All game logic lives in <see cref="GameCanvas"/>;
/// this file is intentionally thin.
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }
}

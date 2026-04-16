#pragma once
#include <string>
#include <vector>


// ConsoleUI
// ----------
// A reusable console-based UI system responsible for rendering text-based layouts.
// Provides functions for:
// - Centered text rendering
// - Boxed UI elements
// - Menu display
// - Screen formatting (borders, separators)
//
// This separates presentation logic from game logic (GameManager),
// making the UI consistent and reusable across the project.


class ConsoleUI
{
public:
    ConsoleUI(int width = 50);

    void ClearScreen() const;

    void DrawTitle(const std::string& title) const;
    void DrawSeparator() const;

    void DrawText(const std::string& text) const;
    void DrawCentered(const std::string& text) const;
    void DrawBoxed(const std::string& text) const;

    void DrawMenu(const std::vector<std::string>& options) const;

    void PlayerActionAnimation(const std::string& Action);

private:
    int Width;

    std::string CenterText(const std::string& text) const;
};
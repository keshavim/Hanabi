//
// Created by overlord on 9/18/25.
//

#ifndef HANABITETRISAI_GRAPHICS_H
#define HANABITETRISAI_GRAPHICS_H

#include <string>
#include <memory>

namespace hanabi {

// Simple color enum for terminal and future graphical backends
enum class Color {
    Default,
    Red,
    Green,
    Blue,
    Yellow,
    Magenta,
    Cyan,
    White
};

// 2D position
struct Vec2i {
    int x, y;
};

// Interface for any graphics backend
class IGraphics {
public:
    virtual ~IGraphics() = default;

    // Initialize graphics backend
    virtual void init() = 0;

    // Clear screen (fill with default background)
    virtual void clear() = 0;

    // Draw a single character at position with optional color
    virtual void drawChar(int x, int y, char c, Color fg = Color::Default, Color bg = Color::Default) = 0;

    // Draw a string starting at position with optional color
    virtual void drawText(int x, int y, const std::string& text, Color fg = Color::Default, Color bg = Color::Default) = 0;

    // Draw a filled rectangle (useful for Tetris blocks)
    virtual void drawRect(int x, int y, int width, int height, Color fg = Color::Default, Color bg = Color::Default) = 0;

    // Refresh/present the current frame to the screen
    virtual void present() = 0;

    // Get screen size in characters
    virtual Vec2i getScreenSize() const = 0;

    // delay or wait for frame (FPS limiter)
    virtual void waitFrame(float seconds) = 0;

    // flush input buffer or handle terminal-specific updates
    virtual void flush() {}
};

using IGraphicsPtr = std::unique_ptr<IGraphics>;

} // namespace hanabi


#endif //HANABITETRISAI_GRAPHICS_H
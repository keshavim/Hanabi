//
// Created by overlord on 9/18/25.
//

#ifndef HANABITETRISAI_TERM_GRAPHICS_H
#define HANABITETRISAI_TERM_GRAPHICS_H


#pragma once
#include "IGraphics.h"
#include <cpp-terminal/terminal.h>
#include <iostream>

namespace hanabi {

class TerminalGraphics : public IGraphics {
public:
    TerminalGraphics() = default;
    ~TerminalGraphics() override {
        terminal_.set_cursor_visible(true); // restore cursor
    }

    void init() override {
        terminal_.clear();
        terminal_.set_cursor_visible(false);
        screenSize_ = {terminal_.width(), terminal_.height()};
    }

    void clear() override {
        terminal_.clear();
    }

    void drawChar(int x, int y, char c, Color fg = Color::Default, Color bg = Color::Default) override {
        // TODO: map hanabi::Color to cpp-terminal colors
        terminal_.move_cursor({y, x});
        terminal_.set_foreground_color(mapColor(fg));
        terminal_.set_background_color(mapColor(bg));
        std::cout << c;
    }

    void drawText(int x, int y, const std::string& text, Color fg = Color::Default, Color bg = Color::Default) override {
        terminal_.move_cursor({y, x});
        terminal_.set_foreground_color(mapColor(fg));
        terminal_.set_background_color(mapColor(bg));
        std::cout << text;
    }

    void drawRect(int x, int y, int width, int height, Color fg = Color::Default, Color bg = Color::Default) override {
        for (int j = 0; j < height; ++j) {
            terminal_.move_cursor({y + j, x});
            for (int i = 0; i < width; ++i) {
                terminal_.set_foreground_color(mapColor(fg));
                terminal_.set_background_color(mapColor(bg));
                std::cout << " ";
            }
        }
    }

    void present() override {
        std::cout.flush();
    }

    Vec2i getScreenSize() const override {
        return screenSize_;
    }

    void waitFrame(float seconds) override {
        std::this_thread::sleep_for(std::chrono::duration<float>(seconds));
    }

private:
    Terminal terminal_;
    Vec2i screenSize_;

    // Simple color mapper
    Terminal::Color mapColor(Color c) const {
        switch (c) {
            case Color::Red: return Terminal::Color::Red;
            case Color::Green: return Terminal::Color::Green;
            case Color::Blue: return Terminal::Color::Blue;
            case Color::Yellow: return Terminal::Color::Yellow;
            case Color::Magenta: return Terminal::Color::Magenta;
            case Color::Cyan: return Terminal::Color::Cyan;
            case Color::White: return Terminal::Color::White;
            default: return Terminal::Color::Default;
        }
    }
};

} // namespace hanabi


#endif //HANABITETRISAI_TERM_GRAPHICS_H
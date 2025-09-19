//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_NCURSESWINDOW_H
#define HANABITETRISAI_NCURSESWINDOW_H


#pragma once
#include "core/Window.h"
#include <string>
#include <ncurses.h>

namespace hanabi {
struct WindowData {
    std::string title {"Hanabi Tetris"};
    int width {800};
    int height {600};
    bool fullscreen {false};
    bool vsync {true};
    bool resizable {true};
};

class NcursesWindow : public Window {
public:
    NcursesWindow();
    ~NcursesWindow() override;

    bool create(const WindowConfig& config) override;
    void destroy() override;

    bool isOpen() const override;
    void close() override;

    void clear() override;
    void display() override;

    int getWidth() const override { return data.width; }
    int getHeight() const override { return data.height; }
    const std::string& getTitle() const override { return data.title; }

    void setTitle(const std::string& title) override;
    void setSize(int width, int height) override;
    void setFullscreen(bool enabled) override;
    void setVSync(bool enabled) override;

private:
    WindowData data;
    bool open {false};
};
}

#endif //HANABITETRISAI_NCURSESWINDOW_H
//
// Created by overlord on 9/19/25.
//
#include "hanabi_pch.h"
#include "API/NcursesWindow.h"
#include "core/logging.h"

namespace hanabi {
NcursesWindow::NcursesWindow() = default;

NcursesWindow::~NcursesWindow() {
    NcursesWindow::destroy();
}

bool NcursesWindow::create(const WindowConfig& config) {
    // Copy config into our data storage
    data.title      = config.title;
    data.width      = config.width;
    data.height     = config.height;

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // hide cursor

    // Optional: resize terminal if supported
    resizeterm(data.height, data.width);

    open = true;
    return true;
}

void NcursesWindow::destroy() {
    if (open) {
        endwin();
        open = false;
    }
}

bool NcursesWindow::isOpen() const {
    return open;
}

void NcursesWindow::close() {
    destroy();
}

void NcursesWindow::clear() {
    ::clear(); // ncurses clear
}

void NcursesWindow::display() {
    refresh(); // ncurses refresh
}

void NcursesWindow::setTitle(const std::string& title) {

}

void NcursesWindow::setSize(int width, int height) {
    data.width  = width;
    data.height = height;
    resizeterm(height, width);
}

void NcursesWindow::setFullscreen(bool enabled) {
    data.fullscreen = enabled;
    // Not really supported in ncurses; could be a no-op.
}

void NcursesWindow::setVSync(bool enabled) {

    data.vsync = enabled;
    // Not applicable in ncurses; no-op.
}
}
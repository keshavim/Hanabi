//
// Created by overlord on 9/18/25.
//

#ifndef HANABITETRISAI__CPP_TERMINAL_H
#define HANABITETRISAI__CPP_TERMINAL_H


#pragma once
#include <cpp-terminal/terminal.hpp>
#include <iostream>

class TerminalGraphics {
public:
    TerminalGraphics() {
        Term::enable_raw_mode();
        Term::clear();
    }

    ~TerminalGraphics() {
        Term::disable_raw_mode();
        Term::clear();
    }

    void clear() { Term::clear(); }

    void present() { std::cout << std::flush; }

    void processEvents() {
        // minimal example: handle key presses
        // you can expand later with Term::read_key()
    }

    // Provide methods for objects to draw themselves
    void drawText(int x, int y, const std::string& text) {
        std::cout << "\033[" << y << ";" << x << "H" << text;
    }

    void drawPixel(int x, int y, char c = '#') {
        std::cout << "\033[" << y << ";" << x << "H" << c;
    }
};



#endif //HANABITETRISAI__CPP_TERMINAL_H
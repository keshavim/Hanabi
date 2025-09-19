//
// Created by overlord on 9/18/25.
//
#include "hanabi_pch.h"
#include "core/test.h"
#include "core/logging.h"
#include <ncurses.h>

Game::Game() = default;

void Game::print()
{

    initscr();            // Start ncurses
    cbreak();             // Disable line buffering
    noecho();             // Don't print typed keys
    keypad(stdscr, TRUE); // Enable arrow keys
    curs_set(0);          // Hide cursor

    printw("Hello, Tetris!\n");
    refresh();            // Render to screen
    getch();              // Wait for input

    endwin();             // End ncurses


}


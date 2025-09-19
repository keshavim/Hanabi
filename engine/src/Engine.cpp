//
// Created by overlord on 9/19/25.
//
#include "hanabi_pch.h"
#include "core/Engine.h"
#include "core/Game.h"
#include <iostream>

namespace hanabi {
Engine::~Engine() {
    CloseWindow();
}

void Engine::addGame(int w, int h) {
    Game g;
    g.init(w, h);
    games.emplace_back(g);
}

void Engine::run() {
    InitWindow(screenWidth, screenHeight, "Tetris AI Simulations");
    SetTargetFPS(60);

    running = true;
    while (running && !WindowShouldClose()) {
        // --- update ---
        for (auto& g : games) {
            if (g.isRunning()) {
                g.update();
            }
        }

        // --- render ---
        BeginDrawing();
        ClearBackground(BLACK);

        if (!games.empty()) {
            int cols = (int)std::ceil(std::sqrt(games.size()));
            int rows = (int)std::ceil((float)games.size() / cols);

            int cellSize = 20; // size of each block
            int gameWidthPx  = games[0].isRunning() ? games[0].isRunning() : 10 * cellSize;
            int gameHeightPx = 20 * cellSize;

            int spacingX = screenWidth / cols;
            int spacingY = screenHeight / rows;

            for (size_t i = 0; i < games.size(); i++) {
                int col = i % cols;
                int row = i / cols;
                int offsetX = col * spacingX + 10;
                int offsetY = row * spacingY + 10;

                games[i].draw(offsetX, offsetY, cellSize);
            }
        }

        EndDrawing();
    }
    running = false;
    std::cout << "[Engine] All games ended\n";
}

}
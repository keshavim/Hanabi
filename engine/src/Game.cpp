

#include "hanabi_pch.h"
#include "core/Game.h"
#include "core/logging.h"

namespace hanabi {
void Game::init(int boardWidth, int boardHeight) {
    width = boardWidth;
    height = boardHeight;
    running = true;
    std::cout << "[Game] Initialized board "
              << width << "x" << height << "\n";
}

void Game::update() {
    // TODO: game logic (piece falling, collisions, etc.)
}

void Game::draw(int offsetX, int offsetY, int cellSize) {
    // Draw a simple grid as a placeholder
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            DrawRectangleLines(
                offsetX + x * cellSize,
                offsetY + y * cellSize,
                cellSize, cellSize,
                DARKGRAY
            );
        }
    }
    DrawText("Tetris", offsetX + 5, offsetY + 5, 20, RAYWHITE);
}

}
//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_GAME_H
#define HANABITETRISAI_GAME_H
#include <string>
#include <vector>
#include <raylib.h>

namespace hanabi {
class Game {
public:
    Game() = default;
    ~Game() = default;

    void init(int boardWidth, int boardHeight);
    void update();
    void draw(int offsetX, int offsetY, int cellSize);

    bool isRunning() const { return running; }
    void stop() { running = false; }

private:
    bool running {false};
    int width {10};
    int height {20};
    // later: board state, pieces, score, etc.
};
}


#endif //HANABITETRISAI_GAME_H
//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_ENGINE_H
#define HANABITETRISAI_ENGINE_H

#include "Game.h"
#include <string>

namespace hanabi {

class Engine {
public:
    Engine() = default;
    ~Engine();

    void run();
    void addGame(int w, int h);

private:
    bool running {false};
    std::vector<Game> games;

    // one shared render surface
    int screenWidth {1200};
    int screenHeight {800};
};
} // namespace hanabi

#endif //HANABITETRISAI_ENGINE_H
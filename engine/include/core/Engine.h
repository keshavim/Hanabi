//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_ENGINE_H
#define HANABITETRISAI_ENGINE_H


#include <memory>
#include <string>

#include "Game.h"

namespace hanabi {

class Engine {
public:
    Engine();
    ~Engine();

    void run();                 // Main engine loop (menu, etc.)
    void startGame(const std::string& mode); // Start a game session

private:
    void init();                // Initialize engine resources
    void shutdown();            // Cleanup

    bool running {false};
    Game currentGame; // Active game session
};
}

#endif //HANABITETRISAI_ENGINE_H
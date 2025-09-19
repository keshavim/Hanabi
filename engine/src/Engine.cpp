//
// Created by overlord on 9/19/25.
//

#include "core/Engine.h"

#include "core/Game.h"
#include <iostream>

namespace hanabi {
Engine::Engine() {
    init();
}

Engine::~Engine() {
    shutdown();
}

void Engine::init() {
    // TODO: Initialize subsystems (logging, configs, etc.)
    std::cout << "[Engine] Initialized\n";
}

void Engine::shutdown() {
    // TODO: Clean up subsystems
    std::cout << "[Engine] Shutdown\n";
}

void Engine::run() {
    running = true;

    // TODO: Replace with menu/GUI
    std::cout << "[Engine] Running\n";

    // For now, auto-start a game in "ascii" mode
    startGame("ascii");

    running = false;
}

void Engine::startGame(const std::string& mode) {
    std::cout << "[Engine] Starting game in mode: " << mode << "\n";

    // TODO: Create correct backend based on mode (ascii, sfml, etc.)
    currentGame = Game();
    currentGame.run();
}
}
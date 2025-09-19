

#include "hanabi_pch.h"
#include "core/Game.h"
#include <iostream>

namespace hanabi {
Game::Game() {
    init();
}

Game::~Game() {
    shutdown();
}

void Game::init() {
    // TODO: Initialize backend wrappers, ECS, etc.
    std::cout << "[Game] Initialized\n";
}

void Game::shutdown() {
    // TODO: Cleanup resources
    std::cout << "[Game] Shutdown\n";
}

void Game::reset() {
    // TODO: Reset board, score, entities, etc.
    std::cout << "[Game] Reset\n";
}

void Game::run() {
    running = true;
    std::cout << "[Game] Running\n";

    // Basic loop stub
    while (running) {
        handleEvents();
        update();
        render();
        running = false; // TODO: replace with real quit condition
    }
}

void Game::handleEvents() {
    // TODO: Wrap input library
    std::cout << "[Game] Handling events\n";
}

void Game::update() {
    // TODO: Update game state (falling pieces, collisions, etc.)
    std::cout << "[Game] Updating\n";
}

void Game::render() {
    // TODO: Call renderer to draw
    std::cout << "[Game] Rendering\n";
}
}
//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_GAME_H
#define HANABITETRISAI_GAME_H

namespace hanabi {
#include <memory>

// Forward declarations
class Window;
class Renderer;
class EventHandler;

class Game {
public:
    Game();
    ~Game();

    void run();  // Main game loop
    void reset(); // Reset game state

private:
    void init();    // Initialize game resources
    void shutdown(); // Clean up resources
    void update();   // Game logic update
    void render();   // Draw frame
    void handleEvents(); // Process input/events

    // Wrappers for backend (to be set by Engine later)
    // std::unique_ptr<Window> window;
    // std::unique_ptr<Renderer> renderer;
    // std::unique_ptr<EventHandler> eventHandler;

    bool running {false};
};
}


#endif //HANABITETRISAI_GAME_H
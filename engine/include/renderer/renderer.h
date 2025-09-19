//
// Created by overlord on 9/18/25.
//

#ifndef HANABITETRISAI_RENDERER_H
#define HANABITETRISAI_RENDERER_H


#include <string>

namespace hanabi {
enum class Color {
    Red,
    Green,
    Blue,
    Yellow,
    White,
    Default
};


#include <vector>
#include <memory>

class GraphicsObject {
public:
    virtual ~GraphicsObject() = default;

    // Called every frame to update object state
    virtual void update() = 0;

    // Called by renderer to draw object
    virtual void render() = 0;
};


class Renderer {
public:
    Renderer();
    ~Renderer();

    void update();          // Update game state or objects
    void render();          // Draw all objects to the screen
    void processEvents();   // Handle input/events

    void addObject(std::shared_ptr<GraphicsObject> obj);

private:
    struct Impl;
    Impl* pImpl;
};




}

#endif //HANABITETRISAI_RENDERER_H
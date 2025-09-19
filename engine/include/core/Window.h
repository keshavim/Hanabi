//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_WINDOW_H
#define HANABITETRISAI_WINDOW_H


#pragma once
#include <string>
#include <cstdint>

//
// Struct to hold window configuration data
//
struct WindowConfig {
    std::string title {"Hanabi Tetris"};
    int width {800};
    int height {600};
};

//
// Abstract base class for a cross-platform window
//
class Window {
public:
    virtual ~Window() = default;

    // Core lifecycle
    virtual bool create(const WindowConfig& config = WindowConfig{}) = 0;
    virtual void destroy() = 0;

    // Window state
    virtual bool isOpen() const = 0;
    virtual void close() = 0;

    // Frame handling
    virtual void clear() = 0;
    virtual void display() = 0;

    // Info
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual const std::string& getTitle() const = 0;

    // Window controls
    virtual void setTitle(const std::string& title) = 0;
    virtual void setSize(int width, int height) = 0;
    virtual void setFullscreen(bool enabled) = 0;
    virtual void setVSync(bool enabled) = 0;
};



#endif //HANABITETRISAI_WINDOW_H
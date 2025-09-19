//
// Created by overlord on 9/19/25.
//

#ifndef HANABITETRISAI_WINDOW_H
#define HANABITETRISAI_WINDOW_H


#include <string>
#include <cstdint>
namespace hanabi {

class Window {
public:
    Window() = default;
    ~Window() = default;

    bool create(const std::string& title, int width, int height);
    void destroy();

    bool isOpen() const;
    void clear();
    void display();

private:
    bool open {false};
};


}
#endif //HANABITETRISAI_WINDOW_H
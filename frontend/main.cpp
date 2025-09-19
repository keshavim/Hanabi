//
// Created by overlord on 9/18/25.
//
#include "hanabi_pch.h"
#include "hanabi.h"


int main()
{
    hanabi::Engine engine;
    engine.addGame(10, 20);
    engine.addGame(10, 20);
    engine.addGame(10, 20);
    engine.addGame(10, 20);

    engine.run();


}
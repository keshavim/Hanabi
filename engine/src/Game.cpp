//
// Created by overlord on 9/18/25.
//
#include "hanabi_pch.h"
#include "core/test.h"
#include "core/logging.h"

Game::Game() = default;

void Game::print()
{
    HANABI_DEBUG("hello debug");
    HANABI_DEBUG("hello debug {}", 1);
    hanabi::println();
    hanabi::println("hello");
    hanabi::println("{}{}", "hello", "world");

}


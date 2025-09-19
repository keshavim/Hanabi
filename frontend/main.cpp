//
// Created by overlord on 9/18/25.
//
#include "hanabi_pch.h"
#include "hanabi.h"


int main()
{
    hanabi::println("hello");
    hanabi::println("hello {}", 1);

    HANABI_DEBUG("please");

    HANABI_ERROR("please {}", "work");


}
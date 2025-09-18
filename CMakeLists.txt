cmake_minimum_required(VERSION 3.20)
project(HanabiTetrisAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_SFML "Enable SFML frontend" OFF)

# Engine library
add_library(engine
        engine/src/Game.cpp
        # add more engine .cpp files here
)
target_include_directories(engine PUBLIC engine/include)

# Precompiled header
target_precompile_headers(engine PRIVATE engine/include/hanabi_pch.h)

# Single executable for all frontends
add_executable(hanabi
        frontend/main.cpp
)

target_link_libraries(hanabi PRIVATE engine)

# Output folder
set_target_properties(hanabi PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME_LOWER}
)

# SFML section (disabled for now)
if(BUILD_SFML)
    find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
    target_sources(hanabi PRIVATE frontend/sfml/main.cpp)
    target_link_libraries(hanabi PRIVATE sfml-system sfml-window sfml-graphics)
endif()

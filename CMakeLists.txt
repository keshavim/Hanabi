cmake_minimum_required(VERSION 3.20)
project(HanabiTetrisAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


# Engine library
file(GLOB_RECURSE ENGINE_SOURCES engine/src/*.cpp)
add_library(engine ${ENGINE_SOURCES})
target_include_directories(engine
        PUBLIC
        engine/include
        ${CURSES_INCLUDE_DIR})

# Precompiled header
target_precompile_headers(engine PRIVATE engine/include/hanabi_pch.h)



# --- Executable ---
file(GLOB_RECURSE FRONTEND_SOURCES frontend/*.cpp)
add_executable(hanabi ${FRONTEND_SOURCES})
target_include_directories(hanabi PRIVATE ${CURSES_INCLUDE_DIR})

target_link_libraries(hanabi
        PRIVATE
        engine
        ${CURSES_LIBRARIES}

)

# Output folder (bin/<OS>/hanabi)
set_target_properties(hanabi PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME_LOWER}
)


cmake_minimum_required(VERSION 3.20)
project(HanabiTetrisAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Don’t build raylib’s examples
add_subdirectory(vendor/raylib)


# Engine library
file(GLOB_RECURSE ENGINE_SOURCES engine/src/*.cpp)
add_library(hanabi_engine ${ENGINE_SOURCES})
target_include_directories(hanabi_engine
        PUBLIC
        engine/include
)
target_link_libraries(hanabi_engine PRIVATE raylib)

# Precompiled header
target_precompile_headers(hanabi_engine PRIVATE engine/include/hanabi_pch.h)



# --- Executable ---
file(GLOB_RECURSE FRONTEND_SOURCES frontend/*.cpp)
add_executable(hanabi ${FRONTEND_SOURCES})

target_link_libraries(hanabi
        PRIVATE
        hanabi_engine
        raylib
)

# Output folder (bin/<OS>/hanabi)
set_target_properties(hanabi PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME_LOWER}
)


cmake_minimum_required(VERSION 3.20)
project(HanabiTetrisAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options (toggle backends on/off later)
option(BUILD_ASCII "Build ASCII frontend" ON)
option(BUILD_SFML "Build SFML frontend" OFF)

if(WIN32)
    message(STATUS "Configuring for Windows")
elseif(APPLE)
    message(STATUS "Configuring for macOS")
elseif(UNIX)
    message(STATUS "Configuring for Linux")
endif()


# Engine library
add_library(engine engine/src/Game.cpp)
target_include_directories(engine PUBLIC engine/include)

# Common exe name
set(EXE_NAME hanabi)

# ASCII frontend
if(BUILD_ASCII)
    add_executable(ascii_frontend frontend/ascii/main.cpp)
    target_link_libraries(ascii_frontend PRIVATE engine)
    set_target_properties(ascii_frontend PROPERTIES
            OUTPUT_NAME ${EXE_NAME}
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME_LOWER}/ascii
    )
endif()

# SFML frontend (later)
#if(BUILD_SFML)
#    find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
#    add_executable(sfml_frontend frontend/sfml/main.cpp)
#    target_link_libraries(sfml_frontend PRIVATE engine sfml-system sfml-window sfml-graphics)
#    set_target_properties(sfml_frontend PROPERTIES
#            OUTPUT_NAME ${EXE_NAME}
#            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME_LOWER}/sfml
#    )
#endif()

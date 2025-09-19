#pragma once
#include <iostream>
#include <string>
#include <format>

// ==========================
// ANSI color codes
// ==========================
#define TEXT_COLOR_RESET  "\033[0m"
#define TEXT_COLOR_RED    "\033[31m"
#define TEXT_COLOR_YELLOW "\033[33m"
#define TEXT_COLOR_GREEN  "\033[32m"
#define TEXT_COLOR_BLUE   "\033[34m"


namespace hanabi {

// ==========================
// Core printing functions (C++23-style)
// ==========================
template<typename... Args>
inline void print(const std::string& fmt, Args&&... args) {
    std::cout << std::vformat(fmt, std::make_format_args(args...));
}

template<typename... Args>
inline void println(const std::string& fmt, Args&&... args) {
    std::cout << std::vformat(fmt, std::make_format_args(args...)) << '\n';
}

inline void println() {
    std::cout << '\n';
}

// ==========================
// Logging helper
// ==========================
template<typename... Args>
inline void log(const char* level, const char* color,
                const char* file, int line,
                const std::string& fmt, Args&&... args)
{
    std::cout << color
              << "[" << file << ":" << line << "] [" << level << "] "
              << std::vformat(fmt, std::make_format_args(args...))
              << TEXT_COLOR_RESET << '\n';
}

} // namespace hanabi

// ==========================
// Logging macros
// ==========================
#define HANABI_INFO(fmt, ...)  hanabi::log("INFO",  TEXT_COLOR_GREEN,  __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define HANABI_WARN(fmt, ...)  hanabi::log("WARN",  TEXT_COLOR_YELLOW, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define HANABI_ERROR(fmt, ...) hanabi::log("ERROR", TEXT_COLOR_RED,    __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define HANABI_DEBUG(fmt, ...) hanabi::log("DEBUG", TEXT_COLOR_BLUE,   __FILE__, __LINE__, fmt, ##__VA_ARGS__)

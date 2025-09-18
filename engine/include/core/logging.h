#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <format>

// ANSI color codes
constexpr const char* COLOR_RESET  = "\033[0m";
constexpr const char* COLOR_RED    = "\033[31m";
constexpr const char* COLOR_YELLOW = "\033[33m";
constexpr const char* COLOR_GREEN  = "\033[32m";
constexpr const char* COLOR_BLUE   = "\033[34m";


// Get current time as HH:MM:SS
inline std::string __current_time() {
    const auto now = std::chrono::system_clock::now();
    auto itt = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &itt);
#else
    localtime_r(&itt, &tm);
#endif
    return std::format("{:02}:{:02}:{:02}", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// ==========================
// Simple print function using std::format
// ==========================
namespace hanabi {
template<typename... Args>
inline void print(const std::string& fmt, const Args&... args) {
    std::fputs(std::vformat(fmt, std::make_format_args(args...)).c_str(), stdout);
}
inline void print(const std::string& fmt) {
    std::fputs(fmt.c_str(), stdout);
}

template<typename... Args>
inline void println(const std::string& fmt, const Args&... args) {
    std::fputs(std::vformat(fmt, std::make_format_args(args...)).c_str(), stdout);
    putchar('\n');
}
inline void println(const std::string& fmt) {
    std::fputs((fmt + "\n").c_str(), stdout);
}
inline void println() {
    putchar('\n');
}
}

// ==========================
// Logging macros with colors
// ==========================
#define LOG(level, color, ...) \
do { \
println("{}[{}] [{}] {}{}", color, __current_time(), level, std::vformat(__VA_ARGS__)); \
} while(0)

// Helper to wrap fmt+args
template<typename... Args>
inline std::string __format_args_wrapper(const std::string& fmt, const Args&... args) {
    return std::vformat(fmt, std::make_format_args(args...));
}

// Variadic logging macros
#define HANABI_INFO(...)  hanabi::println("{}[{}] [INFO] {}{}", COLOR_GREEN,  __current_time(), __format_args_wrapper(__VA_ARGS__), COLOR_RESET)
#define HANABI_WARN(...)  hanabi::println("{}[{}] [WARN] {}{}", COLOR_YELLOW, __current_time(), __format_args_wrapper(__VA_ARGS__), COLOR_RESET)
#define HANABI_ERROR(...) hanabi::println("{}[{}] [ERROR] {}{}", COLOR_RED,    __current_time(), __format_args_wrapper(__VA_ARGS__), COLOR_RESET)
#define HANABI_DEBUG(...) hanabi::println("{}[{}] [DEBUG] {}{}", COLOR_BLUE,   __current_time(), __format_args_wrapper(__VA_ARGS__), COLOR_RESET)

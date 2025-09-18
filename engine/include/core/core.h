//
// Created by overlord on 9/18/25.
//

#ifndef HANABITETRISAI_CORE_H
#define HANABITETRISAI_CORE_H

#pragma once

// Standard headers

#include <string>
#include <memory>
#include <iostream>


// Type aliases for convenience
using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using f32 = float;
using f64 = double;

// Small utility macros
#define UNUSED(x) (void)(x)
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Helper function (will remove these)
inline void print_debug(const std::string& msg) {
    std::cout << "[DEBUG] " << msg << std::endl;
}

inline void print_debug(const std::string& msg, u32 value) {
    std::cout << "[DEBUG] " << msg << ": " << value << std::endl;
}





#endif //HANABITETRISAI_CORE_H
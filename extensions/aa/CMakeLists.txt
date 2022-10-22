cmake_minimum_required(VERSION 3.17)
project(profcont_aa)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(../../../)

add_library(profcont_aa SHARED src/main.cpp src/rules/no_colored_text.cpp src/rules/no_colored_text.hpp src/rules/has_required_chapters.cpp src/rules/has_required_chapters.hpp src/entitiles/chapter.cpp src/entitiles/chapter.hpp)

cmake_minimum_required(VERSION 3.23)
project(ext_aa)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_library(profcont_aa SHARED src/main.cpp)

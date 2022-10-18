cmake_minimum_required(VERSION 3.23)
project(profcont)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(profcont src/main.cpp src/source/file_source.cpp src/exception/prof_cont_exception.hpp src/exception/source_exception.hpp src/target/file_target.cpp src/target/file_target.hpp src/exception/target_exception.hpp)

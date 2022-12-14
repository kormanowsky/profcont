cmake_minimum_required(VERSION 3.17)
project(profcont)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_executable(
        profcont
        src/main.cpp
        src/source/file_source.cpp
        src/exception/prof_cont_exception.hpp
        src/exception/source_exception.hpp
        src/target/file_target.cpp
        src/target/file_target.hpp
        src/exception/target_exception.hpp
        src/transformer/transformer.cpp
        src/transformer/transformer.hpp
        src/extension/base_extension_loader.hpp
        src/extension/extension_loader.cpp
        src/extension/extension_loader.hpp
        src/config/argparse/argparse.hpp
        src/rule/complex_rule.cpp
        src/rule/complex_rule.hpp
        src/rule/rule_solution.cpp
        src/rule/rule_solution.hpp
        src/config/base_config_loader.hpp
        src/config/base_config.hpp
        src/config/argparse/argparse_config_loader.cpp
        src/config/argparse/argparse_config_loader.hpp
        src/source/source_solution.cpp
        src/source/source_solution.hpp
        src/target/target_solution.cpp
        src/target/target_solution.hpp
        ext_entrypoint.hpp)

cmake_minimum_required(VERSION 3.28)
project(falling_sand_sim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML-3.0.0/lib/cmake/SFML)

add_executable(falling_sand_sim src/main.cpp src/Engine.cpp src/Grain.cpp src/Sand.cpp)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

target_include_directories(falling_sand_sim PRIVATE include)

target_link_libraries(falling_sand_sim PRIVATE SFML::Graphics)

# target_compile_options(falling_sand_sim PRIVATE -Wall -Wextra -Werror)
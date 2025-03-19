cmake_minimum_required(VERSION 3.28)
project(falling_sand_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(falling_sand_sim src/main.cpp src/Core/Engine.cpp src/Core/Sand.cpp)

target_link_libraries(falling_sand_sim PRIVATE SFML::Graphics)

target_include_directories(falling_sand_sim PRIVATE include)

target_compile_options(falling_sand_sim PRIVATE -Wall -Wextra -Werror)

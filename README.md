# Falling Sand Simulator
This project is a falling sand simulator implemented in C++ using the SFML library for graphical rendering.

## Simulation
The project uses a 2D grid to simulate falling sand, managing particle behavior dynamically. The Engine class controls the simulation in both versions, but the main processing occurs in the Sand class in the main branch and in the Grid class in the dev branch. These classes contain the most computationally expensive algorithms and core logic.
The class structures in the main and dev branches differ significantly.

## Requirements

- Visual Studio Code with the CMake Tools extension installed
- CMake installed for building the project
- Dependencies (SFML) are automatically fetched via CMake FetchContent

## Build and Run

1. Clone the repository.
2. Open the project folder in Visual Studio Code.
3. The CMake Tools extension will automatically detect the project and configure the build environment.
4. Press F7 or click the "Build" button in CMake Tools to start the build process. CMake will handle dependencies and compile the project.
5. Once the build is complete, run the program directly from the terminal or through the VSCode interface.

## Error
Err: build/_deps/freetype-src/CMakeLists.txt:113
Fix: Set cmake_minimum_required(VERSION 3.28)
Err: May occur in build/_deps/flac-src, ogg-src, vorbis-src
Fix: Same as above

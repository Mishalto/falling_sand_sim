# Falling Sand Simulator
This project is a falling sand simulator implemented in C++ using the SFML library for graphical rendering.

## Software Design
The project uses a 2D grid to simulate falling sand, managing particle behavior dynamically. The Engine class controls the simulation in both versions, but the main processing occurs in the Sand class in the main branch and in the Grid class in the dev branch. These classes contain the most computationally expensive algorithms and core logic.
The class structures in the main and dev branches differ significantly.

Most parameters, such as screen resolution and grid size, are managed through Constants/Constants.hpp

## Requirements

- Visual Studio Code with the CMake Tools extension installed
- CMake installed for building the project
- SFML 3.0.0 (64-bit) Visual C++ 17 (2022) https://www.sfml-dev.org/download/sfml/3.0.0/

## Build and Run

1. Clone the repository.
2. Download SFML 3.0.0 (Visual C++ 17) from the link above and extract it to the root folder of the project.
3. Open the project folder in Visual Studio Code.
4. The CMake Tools extension will automatically detect the project and configure the build environment.
5. Press F7 or click the "Build" button in CMake Tools to start the build process. CMake will handle dependencies and compile the project.
7. Once the build is complete, run the program using one of the following methods:
      - From the terminal: ./falling_sand_sim.exe
      - From the build folder: Clang/MinGW: run from build/, MSVC: run from build/Release/ or build/Debug/

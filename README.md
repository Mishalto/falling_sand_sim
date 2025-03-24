# Falling Sand Simulator

This project is a falling sand simulator implemented in C++ using the SFML library for graphical rendering. It employs a 2D grid to manage the behavior of particles like sand, showcasing simple sandbox algorithms with standard C++ libraries.

Engine class manages the simulation in both versions, but all the action happens in the Sand class in the main branch and the Grid class in the dev branch, respectively. The most computationally expensive algorithms are there, and all the main logic as well.

The class structures in the main and dev branches are very different.

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

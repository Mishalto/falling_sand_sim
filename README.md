# Falling Sand Simulator
This project is a falling sand simulator implemented in C++ using the SFML library for graphical rendering.

## Software Design
This project uses a 2D grid to simulate falling sand, managing particle behavior dynamically. The Engine class controls the simulation, while the Sand class contains the most computationally expensive algorithms and core logic.
Most parameters, such as screen resolution and grid size, are managed through Constants/Constants.hpp.

## Requirements

- Visual Studio Code with the CMake Tools extension installed
- Latest stable release of CMake 3.31.6 installed for building the project. At the time of writing, this version is 3.31.6
- Git (latest stable release recommended) for cloning the repository

## Build and Run

1. Clone the repository.
2. Open the project folder in Visual Studio Code.
3. The CMake Tools extension will automatically detect the project and configure the build environment.
4. Press F7 or click the "Build" button in CMake Tools to start the build process. CMake will handle dependencies and compile the project.
5. After a successful build, all your executable files will be placed in the /bin directory.
   You can run the program using one of the following methods:
   - ./falling_sand_sim.exe
   - or manually navigate to the bin folder inside your project directory and run falling_sand_sim.exe.

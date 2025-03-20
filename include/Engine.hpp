#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include <Sand.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    Sand sand_;
    std::array<std::array<bool, Grid::x_cells>, Grid::y_cells> grid_;
    sf::RenderWindow window_;

    void update();
    void draw();
    void check_events();
public:
    Engine();

    void start();
};
#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include <Sand.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    Sand sand_;
    sf::RenderWindow window_;

    void draw();
    void check_events();
public:
    Engine();

    void start();
};
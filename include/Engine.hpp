#pragma once

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Engine {

private:
    sf::RenderWindow window_;
    const int fps_ = 60;
public:
    Engine();

    void start();
};
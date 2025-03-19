#pragma once

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Engine {

private:
    sf::RenderWindow window_;
    const int fps_ = 60;

    void draw();
    void check_events();
public:
    Engine();

    void start();
};
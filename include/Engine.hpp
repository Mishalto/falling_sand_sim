#pragma once

#include <SFML/Graphics.hpp>

#include <Grain.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    Grain sand_;

    sf::RenderWindow window_;
    const int fps_ = 60;

    void update();
    void draw();
    void check_events();
public:
    Engine();

    void start();
};
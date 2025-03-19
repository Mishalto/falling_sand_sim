#pragma once

#include <SFML/Graphics.hpp>

#include <Sand.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    sf::RenderWindow window_;
    const int fps_ = 60;

    Sand sand_;

    void draw();
    void check_events();
public:
    Engine();

    void start();
};
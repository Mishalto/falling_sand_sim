#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Grain {

private:
    sf::RectangleShape grain_;
    sf::Vector2i coordinate_;

    uint8_t steps_to_idle_;
public:
    Grain(sf::Vector2i coordinate);

    void move(sf::Vector2i dir);
    void increase_steps_to_idle();
    void reset_steps_to_idle();

    int get_steps_to_idle();
    sf::RectangleShape& get_grain();
    sf::Vector2i& get_coordinate();
};
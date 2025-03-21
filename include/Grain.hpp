#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Grain {

private:
    sf::RectangleShape grain_;
    sf::Vector2i coordinate_;

public:
    Grain(sf::Vector2f mouse_pos, sf::Vector2i coordinate);

    sf::RectangleShape& get_grain();
    void move(sf::Vector2f dir);
    sf::Vector2i& get_coordinate();
};
#pragma once

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Grain {

private:
    sf::RectangleShape grain_;

public:
    Grain(sf::Vector2f mouse_pos);

    sf::RectangleShape& get_grain();
};
#pragma once

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Grain {

private:
    sf::RectangleShape grain_;

public:
    Grain();

    sf::RectangleShape& get_grain();
};
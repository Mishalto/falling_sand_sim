#pragma once

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Sand {

private:
    sf::RectangleShape grain_;

public:
    Sand();

    sf::RectangleShape& get_grain();
};
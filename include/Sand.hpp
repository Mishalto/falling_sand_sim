#pragma once

#include <SFML/Graphics.hpp>

class Sand {

private:
    sf::RectangleShape grain_;

public:
    Sand();

    const sf::RectangleShape& get_grain() const;
};
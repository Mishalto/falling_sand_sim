#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Constants/Constants.hpp>

class Grain {

private:
    sf::RectangleShape grain_;
    sf::Vector2i coordinate_;

    bool fAtRest;                 // true if grain has stopped moving

public:
    Grain(sf::Vector2i coordinate);

    void move(sf::Vector2i dir);

    sf::RectangleShape& get_grain();
    sf::Vector2i& get_coordinate();

    void setAtRest( bool f = true );
    bool isAtRest() const;

};
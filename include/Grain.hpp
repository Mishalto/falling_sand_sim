#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Constants/Constants.hpp>

class Grain : public Particle {

private:
    /* This is something to do with drawing the sfml package
    I do not understand it, except that the name of this attribute is very confusing!
    */
    // sf::RectangleShape grain_;

    /* The location of the sand grain
        Note that y is accessed before x
        because it was designed with the conventional row, column order in mind
    */
    // sf::Vector2i coordinate_;

    // bool is_at_rest_;                 // true if grain has stopped moving

public:
    // Grain(sf::Vector2i coordinate);
    Grain(sf::Vector2i coord);

    // // move location and change rectangle
    void move(sf::Vector2i dir) override;

    // sf::RectangleShape& get_grain();
    // sf::Vector2i& get_coordinate();

    // void set_at_rest(bool f = true);
    // bool is_at_rest() const;

};
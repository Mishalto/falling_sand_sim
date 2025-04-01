#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Constants/Constants.hpp>

class Sand : public Particle {

public:
    Sand(sf::Vector2i coord);

    void move(sf::Vector2i dir) override;
};
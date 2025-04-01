#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Constants/Constants.hpp>

class Sand : public Particle {
    public:
        // Constructor that initializes sand at the given coordinates (calls base class constructor)
        Sand(const sf::Vector2i& coord);
        // Moves the sand particle in the specified direction (implements sand movement logic)
        bool move(std::vector<std::vector<std::shared_ptr<Particle>>>& grid) override;
};

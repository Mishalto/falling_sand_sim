#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Sand.hpp>
#include <Constants/Constants.hpp>

class Sand : public Particle {
    using GridPtr = std::vector<std::vector<std::shared_ptr<Particle>>>;

    private:
        // Move the particle in the given direction
        void move(const sf::Vector2i& dir);
        // Checking availability of the bottom
        bool bottom_is_free(const GridPtr& grid);
        // Checking availability of the bottom-right
        bool bottom_right_is_free(const GridPtr& grid);
        // Checking availability of the bottom-left
        bool bottom_left_is_free(const GridPtr& grid);
    public:
        // Constructor that initializes sand at the given coordinates (calls base class constructor)
        Sand(const sf::Vector2i& coord);
        // Moves the sand particle in the specified direction (implements sand movement logic)
        void update(GridPtr& grid) override;
};

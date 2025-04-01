#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Constants/Constants.hpp>

class Sand : public Particle {
    using GridPtr = std::vector<std::vector<std::shared_ptr<Particle>>>;
    private:
        void move(const sf::Vector2i& dir);

        bool check_bottom() const;
    public:
        // Constructor that initializes sand at the given coordinates (calls base class constructor)
        Sand(const sf::Vector2i& coord);
        // Moves the sand particle in the specified direction (implements sand movement logic)
        bool is_move(GridPtr& grid) override;
};

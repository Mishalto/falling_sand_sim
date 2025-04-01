#pragma once

#include <SFML/Graphics.hpp>

class Particle {
    private:
        sf::RectangleShape particle_;  // Particle shape
        sf::Vector2i coordinate_;      // Particle position
        bool is_at_rest_;              // True if particle is not moving

    public:
        Particle(const sf::Vector2i& coord);  // Constructor, sets position

        virtual void move(sf::Vector2i coord) = 0;  // Moves the particle (must be implemented)

        sf::RectangleShape& get_part();  // Returns the shape
        sf::Vector2i& get_coord();       // Returns the position

        void set_at_rest(bool cond);  // Sets rest state
        bool is_at_rest() const;      // Checks if at rest
    };

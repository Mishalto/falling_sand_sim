#pragma once

#include <SFML/Graphics.hpp>

class Particle {
    private:
        // Particle shape
        sf::RectangleShape particle_;
        // Particle position
        sf::Vector2i coordinate_;
        // True if particle is not moving
        bool is_at_rest_;

    public:
        // Constructor, sets position
        Particle(const sf::Vector2i& coord);
        // Moves the particle (must be implemented)
        virtual bool is_move(std::vector<std::vector<std::shared_ptr<Particle>>>& grid) = 0;
        // Returns the shape
        sf::RectangleShape& get_part();
        // Returns the position
        sf::Vector2i& get_coord();
        // Sets rest state
        void set_at_rest(bool cond);
        // Checks if at rest
        bool is_at_rest() const;
    };
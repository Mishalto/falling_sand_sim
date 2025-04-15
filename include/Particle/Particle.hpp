#pragma once

#include <SFML/Graphics.hpp>

#include <Type.hpp>

class Particle {
    using GridPtr = std::vector<std::vector<std::shared_ptr<Particle>>>;
    private:
        // Particle shape
        sf::RectangleShape particle_;
        // Particle position in grid coordinates
        sf::Vector2i coordinate_;
        // Type of particle(e.g Sand, Water)
        Type type_;
        // Flag indicating whether the particle has stopped moved
        bool is_at_rest_;
        // Flag indicating whether the particle has moved in the current update
        bool is_moved_;

    public:
        // Constructor, sets position
        Particle(const sf::Vector2i& coord);
        // Moves the particle (must be implemented)
        virtual void update(GridPtr& grid) = 0;
        // Returns the particle shape
        sf::RectangleShape& get_part();
        // Returns the position in grid coordinates
        sf::Vector2i& get_coord();
        // Set is_at_rest_ based on the cond
        void set_at_rest(bool cond);
        // Checks if at rest
        bool is_at_rest() const;
        // Set is_moved_ variable based on the cond
        void set_is_move(bool cond);
        // Check is moved
        bool is_moved() const;
        // Set type based on func parameter
        void set_type(Type type);
        // Return particular type
        Type get_type() const;
    };
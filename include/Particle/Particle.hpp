#pragma once

#include <SFML/Graphics.hpp>

#include <ParticleType.hpp>

class Particle {
    using GridPtr = std::vector<std::vector<std::shared_ptr<Particle>>>;
    private:
        // Particle shape
        sf::RectangleShape particle_;
        // Particle position
        sf::Vector2i coordinate_;
        // Type of Part
        Type type_;
        // True if particle is not moving
        bool is_at_rest_;
        bool is_moved_;

    public:
        // Constructor, sets position
        Particle(const sf::Vector2i& coord);
        // Moves the particle (must be implemented)
        virtual void update(GridPtr& grid) = 0;
        // Returns the shape
        sf::RectangleShape& get_part();
        // Returns the position
        sf::Vector2i& get_coord();
        // Sets rest state
        void set_at_rest(bool cond);
        // Checks if at rest
        bool is_at_rest() const;

        void set_is_move(bool cond);

        bool is_moved() const;

        void set_type(Type type);
        Type get_type() const;
    };
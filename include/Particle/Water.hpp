#pragma once

#include <Particle.hpp>
#include <Constants/Constants.hpp>

class Water : public Particle {
    using GridPtr = std::vector<std::vector<std::shared_ptr<Particle>>>;

    private:
        void move(const sf::Vector2i& dir);

        bool bottom_is_free(const GridPtr& grid, const sf::Vector2i& cd) const;
        bool bottom_right_is_free(const GridPtr& grid, const sf::Vector2i& cd) const;
        bool bottom_left_is_free(const GridPtr& grid, const sf::Vector2i& cd) const;
    public:
        // Constructor that initializes sand at the given coordinates (calls base class constructor)
        Water(const sf::Vector2i& coord);
        // Moves the sand particle in the specified direction (implements sand movement logic)
        void update(GridPtr& grid) override;
};
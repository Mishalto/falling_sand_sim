#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Sand.hpp>
#include <Constants/Constants.hpp>

class ParticleManager {
private:
    /* 2D vector of shared pointers to Particle */
    using ParticlePtr = std::shared_ptr<Particle>;
    using Grid = std::vector<std::vector<ParticlePtr>>;
    // storage of the sand grains
    Grid grid_;

    void free_grains_above(const sf::Vector2i& location); // Unblock the grains above a location from which a grain just left

    // Checks if adjacent cells in the specified direction are empty to allow particle movement.
    bool bottom_is_empty(const sf::Vector2i& cd) const;
    bool bottom_right_is_empty(const sf::Vector2i& cd) const;
    bool bottom_left_is_empty(const sf::Vector2i& cd) const;
public:
    ParticleManager();

    void update();                              // move the grains downwards one step
    void add_particle(sf::Vector2i mouse_pos);  // add sand grain at position of mouse cursor
    void draw(sf::RenderWindow& window);        // draw all the sand grains
};
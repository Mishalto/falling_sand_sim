#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Type.hpp>
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

    // Unblock the grains above a location from which a grain just left
    void free_grains_above(const sf::Vector2i& location);
public:
    ParticleManager();
    // move the grains downwards one step
    void update();
    // add sand grain at position of mouse cursor
    void add_particle(sf::Vector2i mouse_pos, Type type);
    // draw all the sand grains
    void draw(sf::RenderWindow& window);
    // delete after finish
    void print_grid() const;
};
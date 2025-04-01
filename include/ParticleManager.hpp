#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Particle.hpp>
#include <Sand.hpp>
#include <Constants/Constants.hpp>

class ParticleManager
{

private:
    /* Data Structure

    A 2D vector containing shared pointers to the simulated grains of sand

    */
    typedef std::shared_ptr<Particle> grain_t;
    typedef std::vector<std::vector<grain_t>> grid_t;

    grid_t grid_;       // storage of the sand grains

    // Unblock the grains above a location from which a grain just left
    void freeGrainsAbove(const sf::Vector2i& location);

public:
    ParticleManager();

    /// move the grains downwards one step
    void update();

    /// add sand grain at position of mouse cursor
    void add_grain(sf::Vector2i mouse_pos);

    /// draw all the sand grains
    void draw(sf::RenderWindow& window);

};
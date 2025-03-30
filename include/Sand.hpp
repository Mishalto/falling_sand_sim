#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Grain.hpp>

class Sand
{

private:

    /* Data Structure

    A 2D vector containing shared pointers to the simulated grains of sand

    */
    typedef std::shared_ptr<Grain> grain_t;
    typedef std::vector<std::vector<grain_t>> grid_t;

    grid_t grid_;       // storage of the sand grains

    // Unblock the grains above a location from which a grain just left
    void freeGrainsAbove( const sf::Vector2i& location );

public:
    Sand();

    /// move the grains downwards one step
    void update();

    /// add sand grain at position of mouse cursor
    void add_grain(sf::Vector2i mouse_pos);

    /// draw all the sand grains
    void draw( sf::RenderWindow& window);

};
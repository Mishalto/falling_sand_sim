#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Grain.hpp>

class Sand
{

private:
    typedef std::shared_ptr<Grain> grain_t;
    typedef std::vector<std::vector<grain_t>> grid_t;

    grid_t grid_;

public:
    Sand();

    void update();
    void add_grain(sf::Vector2i mouse_pos);

    grid_t &getGrid()
    {
        return grid_;
    }
};
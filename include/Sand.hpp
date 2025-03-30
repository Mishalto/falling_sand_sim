#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Grain.hpp>

class Sand
{

private:
    typedef std::shared_ptr<Grain> grain_t;

    std::vector<std::vector<grain_t>> grid_;

    void init_grid();

public:
    Sand();

    void update();
    void add_grain(sf::Vector2i mouse_pos);
    std::vector<Grain> &get_grains();
};
#pragma once

#include <optional>
#include <array>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Grain.hpp>

class Sand {

private:
    std::vector<Grain> sand_pool_;
    std::array<std::array<bool, Grid::x_cells>, Grid::y_cells> grid_;

public:
    Sand();

    void add_grain(sf::Vector2i mouse_pos);
    std::vector<Grain>& get_grains();
    std::array<std::array<bool, Grid::x_cells>, Grid::y_cells>& get_grid();
};
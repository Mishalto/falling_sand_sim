#pragma once

#include <array>
#include <vector>

#include <SFML/Graphics.hpp>

#include <GrainState.hpp>
#include <Grain.hpp>

class Sand {

private:
    std::vector<Grain> sand_pool_;
    std::array<std::array<CellState, Grid::x_cells>, Grid::y_cells> grid_;

    void init_grid();
public:
    Sand();

    void update();
    void add_grain(sf::Vector2i mouse_pos);
    std::vector<Grain>& get_grains();
};
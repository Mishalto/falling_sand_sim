#include <Sand.hpp>

Sand::Sand() {
    sand_pool_.reserve(Memory::grains_count);
}

void Sand::add_grain(sf::Vector2f pos) {
    sand_pool_.emplace_back(Grain{});
    sand_pool_.back().get_grain().setPosition(pos);
}

std::vector<Grain>& Sand::get_grains() {
    return sand_pool_;
}

std::array<std::array<bool, Grid::x_cells>, Grid::y_cells>& Sand::get_grid() {
    return grid_;
}
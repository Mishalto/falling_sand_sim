#include <Sand.hpp>

Sand::Sand() {
    sand_pool_.reserve(Memory::grains_count);
}

void Sand::add_grain(sf::Vector2i mouse_pos) {
    for (size_t i = 0; i < grid_.size(); ++i) {
        for (size_t j = 0; j <grid_[i].size(); ++j) {
            if (mouse_pos.x > j * GrainStats::size && mouse_pos.x < j * GrainStats::size + GrainStats::size &&  // check left side and right side
                mouse_pos.y > i * GrainStats::size && mouse_pos.y < i * GrainStats::size + GrainStats::size) {  // check top and bottom
                    float x_pos = static_cast<int>(j) * GrainStats::size;
                    float y_pos = static_cast<int>(i) * GrainStats::size;
                    sf::Vector2f pos = {x_pos, y_pos};
                    sand_pool_.emplace_back(Grain{pos});
                }
        }
    }
}

std::vector<Grain>& Sand::get_grains() {
    return sand_pool_;
}

std::array<std::array<bool, Grid::x_cells>, Grid::y_cells>& Sand::get_grid() {
    return grid_;
}
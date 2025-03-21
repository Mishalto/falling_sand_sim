#include <Sand.hpp>

Sand::Sand() {
    sand_pool_.reserve(Memory::crains_count);
    init_grid();
}

void Sand::add_grain(sf::Vector2i mouse_pos) {
    for (size_t y = 0; y < grid_.size(); ++y) {
        for (size_t x = 0; x < grid_[y].size(); ++x) {
            if (mouse_pos.x >= x * GrainStats::size && mouse_pos.x <= x * GrainStats::size + GrainStats::size &&  // check left side and right side
                mouse_pos.y >= y * GrainStats::size && mouse_pos.y <= y * GrainStats::size + GrainStats::size &&  // check top and bottom
                !grid_[y][x]) { // Check the availability of the cell
                    float x_pos = static_cast<int>(x) * GrainStats::size;
                    float y_pos = static_cast<int>(y) * GrainStats::size;
                    sand_pool_.emplace_back(Grain{{x_pos, y_pos}, {static_cast<int>(x), static_cast<int>(y)}}); // vector2f(pos) / vector2i(coordinate)
                    grid_[y][x] = true;
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

void Sand::init_grid() {
    for (size_t y = 0; y < grid_.size(); ++y) {
        for (size_t x = 0; x < grid_[y].size(); ++x) {
            grid_[y][x] = false;
        }
    }
}

void Sand::step() {
    for (ptrdiff_t i = 0; i < sand_pool_.size(); ++i) {
        sf::Vector2i coord = sand_pool_[i].get_coordinate();
        if (coord.y < grid_.size() - 1 && !grid_[coord.y + 1][coord.x]) {
            sand_pool_[i].move({0, 1});
            grid_[coord.y][coord.x] = false;
            grid_[coord.y + 1][coord.x] = true;
        } else if (coord.x < grid_.size() && !grid_[coord.y][coord.x + 1]) {
            sand_pool_[i].move({1, 0});
            grid_[coord.y][coord.x] = false;
            grid_[coord.y][coord.x + 1] = true;
        }
    }
}
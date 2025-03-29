#include <Sand.hpp>

Sand::Sand() {
    // Reserve memory for grains using a constexpr value from Constants.hpp
    sand_pool_.reserve(Memory::grains_count);
    init_grid();
}

void Sand::init_grid() {
    // init grid_ by setting all cell to Free

    for (size_t y = 0; y < grid_.size(); ++y) {
        std::fill(grid_[y].begin(), grid_[y].end(), CellState::Free);
    }
}

void Sand::add_grain(sf::Vector2i mouse_pos) {
    // Grain is created using the mouse pos

    // Convert the mouse position to grid coordinates.
    sf::Vector2i grid_pos = {static_cast<int>(mouse_pos.x / GrainStats::size), static_cast<int>(mouse_pos.y / GrainStats::size)};
    if (grid_[grid_pos.y][grid_pos.x] == CellState::Free) {
        sand_pool_.emplace_back(Grain{grid_pos});
        grid_[grid_pos.y][grid_pos.x] = CellState::Occupied;
    }
}

void Sand::step()
{
    // move all sand grains that are free to fall downwards

    static constexpr int step = Physics::step;
    static int stepts_to_idle = 0;
    // loop over all the sand grains
    for (auto &g : sand_pool_)
    {
        // current location
        sf::Vector2i cd = g.get_coordinate();

        if (cd.y + step >= grid_.size() || grid_[cd.y][cd.x] == CellState::Idle)
        {
            // the grain is resting on the bottom of the grid
            continue;
        }
        if (grid_[cd.y + step][cd.x] == CellState::Free)
        {
            // cell below is empty so grain can fall straight down
            g.move({0, step});
            grid_[cd.y][cd.x] = CellState::Free;
            grid_[cd.y + step][cd.x] = CellState::Occupied;
        }
        else if (cd.x + step < grid_[0].size() && grid_[cd.y][cd.x + step] == CellState::Free && grid_[cd.y + step][cd.x + step] == CellState::Free)
        {
            // cells on right and down right are available
            // move right
            g.move({step, 0});
            grid_[cd.y][cd.x] = CellState::Free;
            grid_[cd.y][cd.x + step] = CellState::Occupied;
        }
        else if (cd.x - step >= 0 && grid_[cd.y][cd.x - step] == CellState::Free && grid_[cd.y + step][cd.x - step] == CellState::Free)
        {
            // cells on left and down left are available
            // move left
            g.move({-step, 0});
            grid_[cd.y][cd.x] = CellState::Free;
            grid_[cd.y][cd.x - step] = CellState::Occupied;
        }
        else {
            // currently is not working as expected

            // grid_[cd.y][cd.x] == GrainState::Idle;
        }
    }
}

std::vector<Grain>& Sand::get_grains() {
    // This is necessary for the Engine class to draw grains

    return sand_pool_;
}
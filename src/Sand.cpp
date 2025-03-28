#include <Sand.hpp>

Sand::Sand() {
    sand_pool_.reserve(Memory::crains_count);
    init_grid();
}

void Sand::init_grid() {
    for (size_t y = 0; y < grid_.size(); ++y) {
        for (size_t x = 0; x < grid_[y].size(); ++x) {
            grid_[y][x] = GrainState::Free;
        }
    }
}

void Sand::add_grain(sf::Vector2i mouse_pos) {
    for (size_t y = 0; y < grid_.size(); ++y) {
        for (size_t x = 0; x < grid_[y].size(); ++x) {
            if (mouse_pos.x >= x * GrainStats::size && mouse_pos.x <= x * GrainStats::size + GrainStats::size &&  // check left side and right side
                mouse_pos.y >= y * GrainStats::size && mouse_pos.y <= y * GrainStats::size + GrainStats::size &&  // check top and bottom
                grid_[y][x] == GrainState::Free) { // Check the availability of the cell
                    float x_pos = static_cast<int>(x) * GrainStats::size;
                    float y_pos = static_cast<int>(y) * GrainStats::size;
                    sand_pool_.emplace_back(Grain{{x_pos, y_pos}, {static_cast<int>(x), static_cast<int>(y)}}); // vector2f(pos) / vector2i(coordinate)
                    grid_[y][x] = GrainState::Occupied;
                }
        }
    }
}


void Sand::step()
{
    // move all sand grains that are free to fall downwards

    int step = Physics::step;

    // loop over all the sand grains
    for (auto &g : sand_pool_)
    {
        // current location
        sf::Vector2i cd = g.get_coordinate();

        if (cd.y + step >= grid_.size() && grid_[cd.y][cd.x] != GrainState::Idle)
        {
            // the grain is resting on the bottom of the grid
            // TODO mark the grain has resting, so that it does not need to be checked again
            continue;
        }
        if (grid_[cd.y + step][cd.x] == GrainState::Free)
        {
            // cell below is empty so grain can fall straight down
            g.move({0, step});
            grid_[cd.y][cd.x] = GrainState::Free;
            grid_[cd.y + step][cd.x] = GrainState::Occupied;
        }
        else if (cd.x + step < grid_[0].size() && grid_[cd.y][cd.x + step] == GrainState::Free && grid_[cd.y + step][cd.x + step] == GrainState::Free)
        {
            // cells on right and down right are available
            // move right
            g.move({step, 0});
            grid_[cd.y][cd.x] = GrainState::Free;
            grid_[cd.y][cd.x + step] = GrainState::Occupied;
        }
        else if (cd.x - step >= 0 && grid_[cd.y][cd.x - step] == GrainState::Free && grid_[cd.y + step][cd.x - step] == GrainState::Free)
        {
            // cells on left and down left are available
            // move left
            g.move({-step, 0});
            grid_[cd.y][cd.x] = GrainState::Free;
            grid_[cd.y][cd.x - step] = GrainState::Occupied;
        }
        else
        {
            // If there is nowhere to step, the state becomes IDLE and the cell is no longer checked
            grid_[cd.y][cd.x] = GrainState::Idle;
        }
    }
}


std::vector<Grain>& Sand::get_grains() {
    return sand_pool_;
}
#include <Water.hpp>

#include <iostream> // DELETE AFTER FIX!!!!!!!!!!!!!!!!

// The constructor initializes the sand particle with default values, determining its position based on the given coordinates (mouse coordinates).
Water::Water(const sf::Vector2i& coord) : Particle(coord), flow_dir(Directions::undefined) {
    sf::Vector2f calc_cd = {coord.x * ParticleStats::size, coord.y * ParticleStats::size};
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(sf::Color::Blue));
    get_part().setPosition(calc_cd);
    set_type(ParticleType::Water);
}

void Water::update(GridPtr& grid) {
    sf::Vector2i cd = get_coord();

    if (bottom_is_free(grid, cd)) {
        move({0, 1});
        grid[cd.y + 1][cd.x] = std::move(grid[cd.y][cd.x]);
        return;
    } else if (bottom_right_is_free(grid, cd)) {
        move({1, 1});
        grid[cd.y + 1][cd.x + 1] = std::move(grid[cd.y][cd.x]);
        return;
    } else if (bottom_left_is_free(grid, cd)) {
        move({-1, 1});
        grid[cd.y + 1][cd.x - 1] = std::move(grid[cd.y][cd.x]);
        return;
    }

    if (!is_moved() && flow_dir == Directions::undefined) {
        if (cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr) {
            flow_dir = Directions::right;
        } else if (cd.x - 1 >= 0 && grid[cd.y][cd.x - 1] == nullptr) {
            flow_dir = Directions::left;
        }
    }

    if (cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr && flow_dir == Directions::right) {
        move({1, 0});
        grid[cd.y][cd.x + 1] = std::move(grid[cd.y][cd.x]);
    } else if (cd.x - 1 >= 0 && grid[cd.y][cd.x - 1] == nullptr && flow_dir == Directions::left) {
        move({-1, 0});
        grid[cd.y][cd.x - 1] = std::move(grid[cd.y][cd.x]);
    } else if (cd.y + 1 < grid.size() - 1) {
        for (size_t i = 0; i < grid[0].size(); ++i) {
            if (grid[cd.y + 1][0 + i] != nullptr) { continue; }

            if (cd.x - 1 >= 0 && grid[cd.y][cd.x - 1] == nullptr) {
                move({-1, 0});
                grid[cd.y][cd.x - 1] = std::move(grid[cd.y][cd.x]);
            } else if (cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr) {
                move({1, 0});
                grid[cd.y][cd.x + 1] = std::move(grid[cd.y][cd.x]);
            }
        }
    }
}


// Checking availability of the bottom, bottom-left, and bottom-right.
bool Water::bottom_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && grid[cd.y + 1][cd.x] == nullptr;
}
bool Water::bottom_right_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && cd.x + 1 < grid[0].size() &&
           grid[cd.y + 1][cd.x + 1] == nullptr;
}
bool Water::bottom_left_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && cd.x - 1 >= 0 &&
           grid[cd.y + 1][cd.x - 1] == nullptr;
}

// Move the particle in the given direction
void Water::move(const sf::Vector2i& dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});
    get_coord().x += dir.x;
    get_coord().y += dir.y;
    set_is_move(true);
}
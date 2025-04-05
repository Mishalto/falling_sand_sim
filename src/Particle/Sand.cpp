#include <Sand.hpp>

// The constructor initializes the sand particle with default values, determining its position based on the given coordinates (mouse coordinates).
Sand::Sand(const sf::Vector2i& coord) : Particle(coord) {
    sf::Vector2f calc_cd = {coord.x * ParticleStats::size, coord.y * ParticleStats::size};
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(194, 178, 128));  // RGB combination for sand color
    get_part().setPosition(calc_cd);
    set_type(ParticleType::Sand);
}

// Moves the sand particle in the specified direction (implements sand movement logic)
void Sand::update(GridPtr& grid) {
    sf::Vector2i cd = get_coord();
    // Check out of bounds
    if (cd.y + 1 >= grid.size()) {
        set_at_rest(true);
        return;
    }
    // Check all directions
    if (bottom_is_free(grid)) {
        move({0, 1});   // To bottom
        grid[cd.y + 1][cd.x] = std::move(grid[cd.y][cd.x]);

    } else if (bottom_right_is_free(grid)) {
        move({1, 1});   // To right
        grid[cd.y + 1][cd.x + 1] = std::move(grid[cd.y][cd.x]);
    } else if (bottom_left_is_free(grid)) {
        move({-1, 1});  // To left
        grid[cd.y + 1][cd.x - 1] = std::move(grid[cd.y][cd.x]);
    }
}

// Move the particle in the given direction
void Sand::move(const sf::Vector2i& dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});
    get_coord() += {dir.x, dir.y};
}

// Checking availability of the bottom
bool Sand::bottom_is_free(const GridPtr& grid) {
    const auto cd = get_coord();
    // Check if bottom cell is free
    if (grid[cd.y + 1][cd.x] == nullptr) {
        return true;
    }
    // Check if bottom cell is water
    else if (grid[cd.y + 1][cd.x]->get_type() == ParticleType::Water) {
        return true;
    }

    return false;
}
// Cheking availability of the bottom-right
bool Sand::bottom_right_is_free(const GridPtr& grid) {
    const auto cd = get_coord();
    // Check out of bounds
    if (cd.y + 1 >= grid.size() || cd.x + 1 >= grid[0].size()) {
        return false;
    }
    // Check if bottom-right is free
    if (grid[cd.y + 1][cd.x + 1] == nullptr) {
        return true;
    }
    // Check if bottom-right is water
    else if (grid[cd.y + 1][cd.x + 1]->get_type() == ParticleType::Water) {
        return true;
    }

    return false;
}
// Cheking availability of the bottom-right
bool Sand::bottom_left_is_free(const GridPtr& grid) {
    const auto cd = get_coord();
    // Check out of bounds
    if (cd.y - 1 < 0 || cd.x - 1 < 0) {
        return false;
    }
    // Check if bottom-left is free
    if (grid[cd.y - 1][cd.x - 1] == nullptr) {
        return true;
    }
    // Check if bottom-left is water
    else if ((grid[cd.y - 1][cd.x - 1]->get_type() == ParticleType::Water)) {
        return true;
    }

    return false;
}

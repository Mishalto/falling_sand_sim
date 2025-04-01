#include <Sand.hpp>

// The constructor initializes the sand particle with default values, determining its position based on the given coordinates (mouse coordinates).
Sand::Sand(const sf::Vector2i& coord) : Particle(coord) {
    sf::Vector2f calc_cd = {coord.x * ParticleStats::size, coord.y * ParticleStats::size};
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(194, 178, 128));  // RGB combination for sand color
    get_part().setPosition(calc_cd);
}

// Moves the sand particle in the specified direction (implements sand movement logic)
void Sand::is_move(GridPtr& grid) {
    sf::Vector2i cd = get_coord();
    // Check out of bounds
    if (cd.y + 1 >= grid.size()) {
        set_at_rest(true);
    }
    // Check all directions
    if (bottom_is_free(grid, cd)) {
        move({0, 1});   // To bottom
        grid[cd.y + 1][cd.x] = std::move(grid[cd.y][cd.x]);
    } else if (bottom_right_is_free(grid, cd)) {
        move({1, 0});   // To right
        grid[cd.y][cd.x + 1] = std::move(grid[cd.y][cd.x]);
    } else if (bottom_left_is_free(grid, cd)) {
        move({-1, 0});  // To left
        grid[cd.y][cd.x - 1] = std::move(grid[cd.y][cd.x]);
    } else { set_at_rest(true); }
}

// Move the particle in the given direction
void Sand::move(const sf::Vector2i& dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});
    get_coord() += {dir.x, dir.y};
}

// Checking availability of the bottom, bottom-left, and bottom-right.
bool Sand::bottom_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return grid[cd.y + 1][cd.x] == nullptr;
}
bool Sand::bottom_right_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr &&
           grid[cd.y + 1][cd.x + 1] == nullptr;
}
bool Sand::bottom_left_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.x - 1 >= 0 && grid[cd.y][cd.x - 1] == nullptr &&
           grid[cd.y + 1][cd.x - 1] == nullptr;
}

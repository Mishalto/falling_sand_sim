#include <Water.hpp>

#include <iostream> // DELETE AFTER FIX!!!!!!!!!!!!!!!!

// The constructor initializes the sand particle with default values, determining its position based on the given coordinates (mouse coordinates).
Water::Water(const sf::Vector2i& coord) : Particle(coord) {
    sf::Vector2f calc_cd = {coord.x * ParticleStats::size, coord.y * ParticleStats::size};
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(sf::Color::Blue));
    get_part().setPosition(calc_cd);
}

void Water::update(GridPtr& grid) {
    sf::Vector2i cd = get_coord();
    // Check all directions
    if (bottom_is_free(grid, cd)) {
        move({0, 1});   // To bottom
        grid[cd.y + 1][cd.x] = std::move(grid[cd.y][cd.x]);
        grid[cd.y][cd.x]->set_is_move(true);
    } else if (bottom_right_is_free(grid, cd)) {
        move({1, 0});   // To right
        grid[cd.y][cd.x + 1] = std::move(grid[cd.y][cd.x]);
        grid[cd.y][cd.x]->set_is_move(true);
        std::cout << "block2\n";
    } else if (bottom_left_is_free(grid, cd)) {
        move({-1, 0});  // To left
        grid[cd.y][cd.x - 1] = std::move(grid[cd.y][cd.x]);
        grid[cd.y][cd.x]->set_is_move(true);
        std::cout << "block3\n";
    } else if (cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr) {
        move({1, 0});
        grid[cd.y][cd.x + 1] = std::move(grid[cd.y][cd.x]);
        grid[cd.y][cd.x]->set_is_move(true);
        std::cout << "block4\n";
    }
}

// Checking availability of the bottom, bottom-left, and bottom-right.
bool Water::bottom_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && grid[cd.y + 1][cd.x] == nullptr;
}
bool Water::bottom_right_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && cd.x + 1 < grid[0].size() && grid[cd.y][cd.x + 1] == nullptr &&
           grid[cd.y + 1][cd.x + 1] == nullptr;
}
bool Water::bottom_left_is_free(const GridPtr& grid, const sf::Vector2i& cd) const {
    return cd.y + 1 < grid.size() && cd.x - 1 >= 0 && grid[cd.y][cd.x - 1] == nullptr &&
           grid[cd.y + 1][cd.x - 1] == nullptr;
}

// Move the particle in the given direction
void Water::move(const sf::Vector2i& dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});
    get_coord().x += dir.x;
    get_coord().y += dir.y;
}
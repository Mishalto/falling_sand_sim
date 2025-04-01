#include <Sand.hpp>

Sand::Sand(sf::Vector2i coord) : Particle(coord) {
    get_part().setSize(GrainStats::size_2f);
    get_part().setFillColor(GrainStats::color);
    float x = coord.x * GrainStats::size;
    float y = coord.y * GrainStats::size;
    get_part().setPosition({x, y});
}

void Sand::move(sf::Vector2i dir) {
    get_part().move({dir.x * GrainStats::size, dir.y * GrainStats::size});
    if (dir.y == 1) {
        // Down
        get_coord().y += dir.y;
    }
    else if (dir.x == 1) {
        // Right
        get_coord().x += dir.x;
    }
    else if (dir.x == -1) {
        // Left
        get_coord().x += dir.x;
    }
}
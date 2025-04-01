#include <Sand.hpp>

Sand::Sand(const sf::Vector2i& coord) : Particle(coord) {
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(ParticleStats::color);
    float x = coord.x * ParticleStats::size;
    float y = coord.y * ParticleStats::size;
    get_part().setPosition({x, y});
}

 // Rework needed
 // TODO
void Sand::move(sf::Vector2i dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});

    if (dir.y == 1) {
        get_coord().y += dir.y; // Down
    }
    else if (dir.x == 1) {
        get_coord().x += dir.x; // Right
    }
    else if (dir.x == -1) {
        get_coord().x += dir.x; // Left
    }
}
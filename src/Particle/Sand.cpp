#include <Sand.hpp>

Sand::Sand(const sf::Vector2i& coord) : Particle(coord) {
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(194, 178, 128));  // RGB combination for sand color
    float x = coord.x * ParticleStats::size;
    float y = coord.y * ParticleStats::size;
    get_part().setPosition({x, y});
}

void Sand::move(sf::Vector2i dir) {
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});

    get_coord() += dir;
}
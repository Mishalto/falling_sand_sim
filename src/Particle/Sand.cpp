#include <Sand.hpp>

Sand::Sand(const sf::Vector2i& coord) : Particle(coord) {   // The constructor initializes the sand particle with default values, determining its position based on the given coordinates (mouse coordinates).
    get_part().setSize(ParticleStats::size_2f);
    get_part().setFillColor(sf::Color(194, 178, 128));      // RGB combination for sand color
    float x = coord.x * ParticleStats::size;
    float y = coord.y * ParticleStats::size;
    get_part().setPosition({x, y});
}

void Sand::move(sf::Vector2i dir) { // Moves the sand particle in the specified direction (implements sand movement logic)
    get_part().move({dir.x * ParticleStats::size, dir.y * ParticleStats::size});
    get_coord() += dir;
}
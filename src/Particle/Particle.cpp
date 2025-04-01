#include <Particle.hpp>

Particle::Particle(const sf::Vector2i& coord) : coordinate_(coord), is_at_rest_(false) {}

sf::RectangleShape& Particle::get_part() {
    return particle_;   // Returns a reference to the particle's graphical object
}

sf::Vector2i& Particle::get_coord() {
    return coordinate_; // Returns a reference to the particle coordinates
}

void Particle::set_at_rest(bool cond) {
    is_at_rest_ = cond; // Sets the particle rest state
}

bool Particle::is_at_rest() const {
    return is_at_rest_; // Checks if the particle is at rest
}

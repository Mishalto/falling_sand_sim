#include <Particle.hpp>

Particle::Particle(const sf::Vector2i& coord) : coordinate_(coord), is_at_rest_(false) {}

// Returns a reference to the particle's graphical object
sf::RectangleShape& Particle::get_part() {
    return particle_;
}

// Returns a reference to the particle coordinates
sf::Vector2i& Particle::get_coord() {
    return coordinate_;
}
// Sets the particle rest state
void Particle::set_at_rest(bool cond) {
    is_at_rest_ = cond;
}
// Checks if the particle is at rest
bool Particle::is_at_rest() const {
    return is_at_rest_;
}

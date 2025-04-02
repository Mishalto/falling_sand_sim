#include <Particle.hpp>

Particle::Particle(const sf::Vector2i& coord) : coordinate_(coord), is_at_rest_(false), is_moved_(false) {}

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

void Particle::set_is_move(bool cond) {
    is_moved_ = cond;
}

bool Particle::is_moved() const {
    return is_moved_;
}
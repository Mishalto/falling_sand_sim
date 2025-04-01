#include <Particle.hpp>

Particle::Particle(sf::Vector2i coord) : coordinate_(coord), is_at_rest_(false) {}

sf::RectangleShape& Particle::get_part() {
    return particle_;
}

sf::Vector2i& Particle::get_coord() {
    return coordinate_;
}

void Particle::set_at_rest(bool cond) {
    is_at_rest_ = cond;
}

bool Particle::is_at_rest() const {
    return is_at_rest_;
}
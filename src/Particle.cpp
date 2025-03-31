#include <Particle.hpp>

Particle::Particle(const sf::Vector2i& coord) : coordinate_(coord) {
}

sf::RectangleShape& Particle::get_part() {
    return particle_;
}

sf::Vector2i& Particle::get_coord() {
    return coordinate_;
}

void Particle::set_at_rest() {
    is_at_rest_ = true;
}

bool Particle::is_at_rest() const {
    return is_at_rest_;
}
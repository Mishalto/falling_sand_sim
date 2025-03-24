#include <Grain.hpp>

Grain::Grain(sf::Vector2f mouse_pos, sf::Vector2i coordinate) : coordinate_(coordinate) {
    grain_.setSize(GrainStats::size_2f);
    grain_.setFillColor(GrainStats::color);
    grain_.setPosition(mouse_pos);
}

sf::RectangleShape& Grain::get_grain() {
    return grain_;
}

void Grain::move(sf::Vector2i dir) {
    grain_.move({dir.x * GrainStats::size, dir.y * GrainStats::size});
    if (dir.y == Physics::step) {
        coordinate_.y += dir.y;
    }
    if (dir.x == Physics::step) {
        coordinate_.x += dir.x;
    }
    if (dir.x == -Physics::step) {
        coordinate_.x += dir.x;
    }
}

sf::Vector2i& Grain::get_coordinate() {
    return coordinate_;
}
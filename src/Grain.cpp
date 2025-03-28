#include <Grain.hpp>

Grain::Grain(sf::Vector2i coordinate) : coordinate_(coordinate) {
    grain_.setSize(GrainStats::size_2f);
    grain_.setFillColor(GrainStats::color);
    float x = coordinate.x * GrainStats::size;
    float y = coordinate.y * GrainStats::size;
    grain_.setPosition({x, y});
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
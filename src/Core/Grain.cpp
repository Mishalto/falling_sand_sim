#include <Grain.hpp>

Grain::Grain(sf::Vector2f mouse_pos) {
    grain_.setSize(GrainStats::size_2f);
    grain_.setFillColor(GrainStats::color);
    grain_.setPosition(mouse_pos);
}

sf::RectangleShape& Grain::get_grain() {
    return grain_;
}
#include <Grain.hpp>

Grain::Grain() {
    grain_.setSize(GrainStats::size);
    grain_.setFillColor(GrainStats::color);
    grain_.setPosition({static_cast<sf::Vector2f>(sf::Mouse::getPosition())});
}

sf::RectangleShape& Grain::get_grain() {
    return grain_;
}
#include <Grain.hpp>

Grain::Grain() {
    grain_.setSize(GrainStats::size);
    grain_.setFillColor(GrainStats::color);
}

sf::RectangleShape& Grain::get_grain() {
    return grain_;
}
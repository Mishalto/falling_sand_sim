#include <Grain.hpp>

Grain::Grain() {
    grain_.setSize(GrainStats::size_2f);
    grain_.setFillColor(GrainStats::color);
}

sf::RectangleShape& Grain::get_grain() {
    return grain_;
}
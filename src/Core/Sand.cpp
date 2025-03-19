#include <Sand.hpp>

Sand::Sand() {
    grain_.setSize(Grain::size);
    grain_.setFillColor(Grain::color);
}

sf::RectangleShape& Sand::get_grain() {
    return grain_;
}
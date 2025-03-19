#include <Sand.hpp>

Sand::Sand() {
    grain_.setSize({10, 10});
    grain_.setFillColor(sf::Color::Yellow);
    grain_.setPosition({500, 500});
}

const sf::RectangleShape& Sand::get_grain() const {
    return grain_;
}
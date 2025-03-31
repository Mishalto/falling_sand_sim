#include <Grain.hpp>

Grain::Grain(sf::Vector2i coordinate)
: coordinate_(coordinate), fAtRest( false ) {
    // Grain param are set using from Constants.hpp and its grid pos is calc from coordinate_

    grain_.setSize(GrainStats::size_2f);
    grain_.setFillColor(GrainStats::color);
    float x = coordinate.x * GrainStats::size;
    float y = coordinate.y * GrainStats::size;
    grain_.setPosition({x, y});
}

void Grain::move(sf::Vector2i dir) {
    // This method move the Grain using the given dir * GrainSize
    grain_.move({dir.x * GrainStats::size, dir.y * GrainStats::size});
    if (dir.y == 1) {
        // Down
        coordinate_.y += dir.y;
    }
    else if (dir.x == 1) {
        // Right
        coordinate_.x += dir.x;
    }
    else if (dir.x == -1) {
        // Left
        coordinate_.x += dir.x;
    }
}

sf::RectangleShape& Grain::get_grain() {
    // Method are needed in the Engine class to draw
    return grain_;
}
sf::Vector2i& Grain::get_coordinate() {
    // Need Sand::update for logic check and position up
    return coordinate_;
}

void Grain::setAtRest( bool f) {
    fAtRest = f;
}
bool Grain::isAtRest() const {
    return fAtRest;
}
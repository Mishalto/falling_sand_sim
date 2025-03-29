#include <Grain.hpp>

Grain::Grain(sf::Vector2i coordinate) : coordinate_(coordinate), steps_to_idle_(0) {
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
    if (dir.y == Physics::step) {
        // Down
        coordinate_.y += dir.y;
        // If the grain hasn't been idle for 10 steps yet, reset its idle steps counter
        reset_steps_to_idle();
    }
    else if (dir.x == Physics::step) {
        // Right
        coordinate_.x += dir.x;
        reset_steps_to_idle();
    }
    else if (dir.x == -Physics::step) {
        // Left
        coordinate_.x += dir.x;
        reset_steps_to_idle();
    }
}

void Grain::increase_steps_to_idle() {
    // Increases the number of steps to idle, but no more than 10.
    if (steps_to_idle_ < 10) {
        ++steps_to_idle_;
    }
}
void Grain::reset_steps_to_idle() {
    // Reset the steps to idle counter to 0 when the grain moves.
    if (steps_to_idle_ < 10)
    steps_to_idle_ = 0;
}

int Grain::get_steps_to_idle() {
    return steps_to_idle_;
}
sf::RectangleShape& Grain::get_grain() {
    // Method are needed in the Engine class to draw
    return grain_;
}
sf::Vector2i& Grain::get_coordinate() {
    // Need Sand::update for logic check and position up
    return coordinate_;
}
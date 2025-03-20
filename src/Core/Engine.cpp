#include <Engine.hpp>

Engine::Engine() : window_(sf::VideoMode({Resolution::width, Resolution::height}), "Falling Sand Simulator", sf::Style::None) {
    window_.setFramerateLimit(Resolution::fps);
}

void Engine::start() {
    while (window_.isOpen()) {
        check_events();
        draw();
    }
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sand_.add_grain(sf::Mouse::getPosition());
    }
}

void Engine::draw() {
    window_.clear();
    for (auto& s : sand_.get_grains()) {
        for (auto& grain : s) {
            if (grain) {
                window_.draw(grain->get_grain());
            }
        }
    }
    window_.display();
}
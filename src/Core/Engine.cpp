#include <Engine.hpp>

Engine::Engine() : window_(sf::VideoMode({Resolution::width, Resolution::height}), "Falling Sand Simulator", sf::Style::None) {
    window_.setFramerateLimit(fps_);
}

void Engine::start() {
    while (window_.isOpen()) {
        check_events();
        update();
        draw();
    }
}

void Engine::update() {
    sand_.get_grain().move({1, 1});
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
        sand_.get_grain().setPosition({mouse_pos});
    }
}

void Engine::draw() {
    window_.clear();
    window_.draw(sand_.get_grain());
    window_.display();
}
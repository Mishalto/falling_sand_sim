#include <Engine.hpp>

Engine::Engine() : window_(sf::VideoMode({Resolution::width, Resolution::height}), "Falling sand simulator", sf::Style::None) {
    window_.setFramerateLimit(fps_);
}

void Engine::start() {
    while (window_.isOpen()) {
        check_events();
        draw();
    }
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window_.close();
    }
}

void Engine::draw() {
    window_.clear();
    window_.display();
}
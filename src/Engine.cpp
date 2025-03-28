#include <Engine.hpp>

Engine::Engine() : window_(sf::VideoMode({Resolution::width, Resolution::height}), "Falling Sand Simulator", sf::Style::None) {
    window_.setFramerateLimit(Resolution::fps);
}

void Engine::start() {
    while (window_.isOpen()) {
        check_events();
        update();
        draw();
    }
}

void Engine::update() {
    sand_.step();
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if(sf::Mouse::getPosition(window_).y < Resolution::height && sf::Mouse::getPosition(window_).y >= 0
        && sf::Mouse::getPosition(window_).x < Resolution::width && sf::Mouse::getPosition(window_).x >= 0)
        {
            sand_.add_grain(sf::Mouse::getPosition(window_));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        sand_.step();
    }
}

void Engine::draw() {
    window_.clear();
    for (auto& s : sand_.get_grains()) {
        window_.draw(s.get_grain());
    }
    window_.display();
}
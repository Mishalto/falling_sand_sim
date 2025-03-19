#include <GameManager.hpp>

GameManager::GameManager() : window_(sf::VideoMode({Resolution::width, Resolution::height}), "Falling sand simulator", sf::Style::None) {
    window_.setFramerateLimit(fps_);
}

void GameManager::start() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window_.isOpen()) {
        while (const std::optional event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window_.close();
        }

    window_.clear();
    window_.draw(shape);
    window_.display();
    }
}
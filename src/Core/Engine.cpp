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
    particle_pool.update();
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        window_.close();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if(sf::Mouse::getPosition(window_).y < Resolution::height && sf::Mouse::getPosition(window_).y >= 0
        && sf::Mouse::getPosition(window_).x < Resolution::width && sf::Mouse::getPosition(window_).x >= 0)
        {
            particle_pool.add_particle(sf::Mouse::getPosition(window_), "left");
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
        if(sf::Mouse::getPosition(window_).y < Resolution::height && sf::Mouse::getPosition(window_).y >= 0
        && sf::Mouse::getPosition(window_).x < Resolution::width && sf::Mouse::getPosition(window_).x >= 0)
        {
            particle_pool.add_particle(sf::Mouse::getPosition(window_), "right");
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        update();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        particle_pool.print_grid();
    }
}

void Engine::draw() {
    window_.clear();
    particle_pool.draw( window_);
    window_.display();
}
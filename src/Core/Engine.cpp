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
    for (auto& grain : sand_.get_grains()) {
        grain.get_grain();
    }
}

void Engine::check_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        for (size_t i = 0; i < grid_.size(); ++i) {
            for (size_t j = 0; j < grid_[i].size(); ++j) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition();
                if (mouse_pos.x > j * GrainStats::size && mouse_pos.x < j * GrainStats::size + GrainStats::size &&
                    mouse_pos.y > i * GrainStats::size && mouse_pos.y < i * GrainStats::size + GrainStats::size) {
                        float x_pos = static_cast<int>(j) * GrainStats::size;
                        float y_pos = static_cast<int>(i) * GrainStats::size;
                        sf::Vector2f pos = {x_pos, y_pos};
                        sand_.add_grain(pos);
                    }
            }
        }
    }
}

void Engine::draw() {
    window_.clear();
    for (auto& grain : sand_.get_grains()) {
        window_.draw(grain.get_grain());
    }
    window_.display();
}
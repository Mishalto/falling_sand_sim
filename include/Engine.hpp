#pragma once

#include <SFML/Graphics.hpp>

#include <ParticleManager.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    ParticleManager sand_;
    sf::RenderWindow window_;

    void draw();
    void check_events();
    void update();
public:
    Engine();

    void start();
};
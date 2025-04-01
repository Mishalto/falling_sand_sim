#pragma once

#include <SFML/Graphics.hpp>

#include <ParticleManager.hpp>
#include <Constants/Constants.hpp>

class Engine {

private:
    ParticleManager particle_pool;
    sf::RenderWindow window_;

    void draw();
    void check_events();
    void update();
public:
    Engine();

    void start();
};
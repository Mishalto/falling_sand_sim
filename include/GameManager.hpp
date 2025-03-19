#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <Constants/Constants.hpp>

class GameManager {
private:
    // Video
    sf::RenderWindow window_;
    const int fps_ = 60;
public:
    GameManager();

    void start();
};
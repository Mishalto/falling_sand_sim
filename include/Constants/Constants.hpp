#pragma once

#include <SFML/Graphics.hpp>

namespace Resolution {
    const int width = 1920;
    const int height = 1080;
}

namespace GrainStats {
    const sf::Vector2f size = {5, 5};
    const sf::Color color = sf::Color(194, 178, 128);
}

namespace Physics {
    const sf::Vector2f falling_speed = {0, 10};
}

namespace Memory {
    const int grains_count = 1000;
}
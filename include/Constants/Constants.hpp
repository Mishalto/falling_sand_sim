#pragma once

#include <SFML/Graphics.hpp>

namespace Resolution {
    constexpr int width = 1920;
    constexpr int height = 1080;
    constexpr int fps = 60;
}

namespace GrainStats {
    constexpr float size = 5;
    constexpr sf::Vector2f size_2f = {size, size};
    constexpr sf::Color color = sf::Color(194, 178, 128);
}

namespace Physics {
    constexpr sf::Vector2f falling_speed = {0, 10};
}

namespace Memory {
    constexpr int grains_count = 1000;
}
#pragma once

#include <array>

#include <SFML/Graphics.hpp>

namespace Resolution {
    constexpr int width = 1920;
    constexpr int height = 1080;
    constexpr int fps = 60;
}

namespace Memory {
    constexpr int grains_count = 1000;
}

namespace GrainStats {
    constexpr float size = 10;
    constexpr sf::Vector2f size_2f = {size, size};
    constexpr sf::Color color = sf::Color(194, 178, 128);
}

namespace Grid {
    constexpr int x_cells = Resolution::width / GrainStats::size;
    constexpr int y_cells = Resolution::height / GrainStats::size;
}

namespace Physics {
    constexpr float x = 0;
    constexpr float y = 10;
    constexpr sf::Vector2f falling_speed = {x, y};
}
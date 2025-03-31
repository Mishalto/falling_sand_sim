#pragma once

#include <array>

#include <SFML/Graphics.hpp>

namespace Resolution {
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr int fps = 10000;
}

namespace Memory {
    constexpr int grains_count = 250;
}

namespace GrainStats {
    constexpr float size = 2;
    constexpr sf::Vector2f size_2f = {size, size};
    constexpr sf::Color color = sf::Color(194, 178, 128);
    constexpr uint8_t idle_threshold = 50;
}

namespace Grid {
    constexpr int x_cells = Resolution::width / GrainStats::size;
    constexpr int y_cells = Resolution::height / GrainStats::size;
}
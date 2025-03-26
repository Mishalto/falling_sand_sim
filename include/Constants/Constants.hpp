#pragma once

#include <array>

#include <SFML/Graphics.hpp>

namespace Resolution {
    constexpr int width = 2560;
    constexpr int height = 1440;
    constexpr int fps = 10000;
}

namespace Memory {
    constexpr int crains_count = 250;
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
    constexpr int step = 1;
}
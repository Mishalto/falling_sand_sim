#pragma once

#include <array>

#include <SFML/Graphics.hpp>

namespace Resolution {
    constexpr int width = 800;  // Defines the screen width in pixels
    constexpr int height = 600; // Defines the screen height in pixels
    constexpr int fps = 10000; // Defines the target frames per second (fps)
}

namespace GrainStats {
    constexpr float size = 2;   // Defines the size of a single grain of sand in pixels
    constexpr sf::Vector2f size_2f = {size, size};  // Represents the size as a 2D vector (used for rendering)
    constexpr sf::Color color = sf::Color(194, 178, 128);   // Defines the default color of the sand grains (light brown)
}

namespace Grid {
    // Calculates the number of horizontal grid cells based on screen width and grain size
    constexpr int x_cells = Resolution::width / GrainStats::size;

    // Calculates the number of vertical grid cells based on screen height and grain size
    constexpr int y_cells = Resolution::height / GrainStats::size;
}
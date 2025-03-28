#pragma once

#include <cstdint>

enum class CellState : uint8_t {
    Free,
    Occupied,
    Idle
};
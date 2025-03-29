#pragma once

#include <cstdint>

enum class CellState : uint8_t {
    // This enum represents all the current states of the cells

    Free,       // The cell is free and can be occupied
    Occupied,   // The cell is currently occupied by a grain
    Idle        // The cell is no longer updating (can no longer move)
};

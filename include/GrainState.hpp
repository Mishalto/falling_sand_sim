#pragma once

#include <cstdint>

enum class GrainState : uint8_t {
    Free,
    Occupied,
    Idle
};
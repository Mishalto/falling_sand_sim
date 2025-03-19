#include <Sand.hpp>

Sand::Sand() {
    sand_pool_.reserve(Memory::grains_count);
}

void Sand::add_grain() {
    sand_pool_.emplace_back(Grain{});
}

std::vector<Grain>& Sand::get_grains() {
    return sand_pool_;
}
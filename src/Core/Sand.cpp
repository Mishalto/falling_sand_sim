#include <Sand.hpp>

Sand::Sand() {}

void Sand::add_grain() {
    sand_pool_.emplace_back(Grain{});
}

std::vector<Grain>& Sand::get_grains() {
    return sand_pool_;
}
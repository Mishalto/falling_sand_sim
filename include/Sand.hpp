#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Grain.hpp>

class Sand {

private:
    std::vector<Grain> sand_pool_;

public:
    Sand();

    std::vector<Grain>& get_grains();
    void add_grain();
};
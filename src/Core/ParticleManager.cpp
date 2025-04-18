#include <Core/ParticleManager.hpp>

ParticleManager::ParticleManager() : grid_(GridData::y_cells, std::vector<ParticlePtr>(GridData::x_cells)) {}

// move all sand grains that are free to fall downwards
void ParticleManager::update() {
    static constexpr int s = 1;  // s - step
    // loop over all the rows of sand grains
    // we start at the bottom because a grain moving my liberate grains higher up
    for (int krow = grid_.size() - 1; krow >= 0; krow--) {
        for (auto& part : grid_[krow]) {
            // Skip empty
            if (part == nullptr) {
                continue;
            }
            // Skip moved particular
            if (!part->is_moved()) {
                part->update(grid_);
            }
        }
    }
}
// Particle is created using the mouse pos
// Convert the mouse position to grid coordinates.
void ParticleManager::add_particle(sf::Vector2i mouse_pos, Type type) {
    sf::Vector2i grid_pos = {
        static_cast<int>(mouse_pos.x / ParticleStats::size),
        static_cast<int>(mouse_pos.y / ParticleStats::size)};
    // Check empty
    if (grid_[grid_pos.y][grid_pos.x] != nullptr) { return; }
    // Added Particle based on its Type
    if (type == Type::Sand) {
        grid_[grid_pos.y][grid_pos.x] = ParticlePtr(new Sand(grid_pos));
        return;
    }
}

// Unblock the grains above a location from which a grain just left
void ParticleManager::free_grains_above(const sf::Vector2i& location) {
    // free grains that may have been blocked;

    // check if grain is on window bottom - always blocked
    if (location.y - 1 < 0) { return; }

    // ensure grain above, if present, is free
    auto n = grid_[location.y - 1][location.x];
    if (n != nullptr)
        n->set_at_rest(false);

    // ensure grain above left, if present, is free
    if (location.x - 1 >= 0) {
        n = grid_[location.y - 1][location.x - 1];
        if (n != nullptr)
            n->set_at_rest(false);
    }

    // ensure grain above right, if present, is free
    // check for right boundary ( fix TID20 )
    if (location.x + 1 < grid_[0].size()) {
        n = grid_[location.y - 1][location.x + 1];
        if (n != nullptr)
            n->set_at_rest(false);
    }
}

// draw all the sand grains
void ParticleManager::draw(sf::RenderWindow &window) {
    for (auto &row : grid_)
        for (auto grain : row)
            if (grain != nullptr)
            {
                window.draw(grain->get_part());
                if (grain->is_moved())
                grain->set_is_move(false);
            }
}

// delete after finish
void ParticleManager::print_grid() const {
    for (const auto& s : grid_) {
        for (const auto& j : s) {
            if (j != nullptr) {
                std::cout << 1 << " ";
            } else {
                std::cout << 0 << " ";
            }
        }
        std::cout << '\n';
    }
}
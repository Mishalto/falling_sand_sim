#include <ParticleManager.hpp>

ParticleManager::ParticleManager() : grid_(GridData::y_cells, std::vector<ParticlePtr>(GridData::x_cells)) {}

// move all sand grains that are free to fall downwards
void ParticleManager::update() {
    static constexpr int s = 1;     // s - step
    // loop over all the rows of sand grains
    // we start at the bottom because a grain moving my liberate grains higher up
    for (int krow = grid_.size() - 1; krow >= 0; krow--) {
        for (auto& part : grid_[krow]) {
            // Skip empty cells
            if (part == nullptr) { continue; }
            // Skip particles that are already at rest
            if (part->is_at_rest()) { continue; }

            // Get current particle position
            sf::Vector2i cd = part->get_coord();

            // Track if particle has moved
            bool fMoved = false;
            if (part->is_move(grid_)) {
                fMoved = true;
            } else {
                part->set_at_rest(true);
            }
            // If particle moved, free particles above it
            // Else mark particle as at rest if it didn't move
            if (fMoved) {
                free_grains_above(cd);
            } else {
                part->set_at_rest(true);
            }
        }
    }
}
// Grain is created using the mouse pos
// Convert the mouse position to grid coordinates.
void ParticleManager::add_particle(sf::Vector2i mouse_pos, std::string_view button) {
    sf::Vector2i grid_pos = {
        static_cast<int>(mouse_pos.x / ParticleStats::size),
        static_cast<int>(mouse_pos.y / ParticleStats::size)};
// check that there is no grain already at this position
    if (grid_[grid_pos.y][grid_pos.x] != nullptr)
        return;
    if (button == "left") {
        grid_[grid_pos.y][grid_pos.x] = ParticlePtr(new Sand(grid_pos));    // construct the grain
    } else if (button == "right") {
        grid_[grid_pos.y][grid_pos.x] = ParticlePtr(new Water(grid_pos));
    }
}

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

void ParticleManager::draw(sf::RenderWindow &window) {
    for (auto &row : grid_)
        for (auto grain : row)
            if (grain != nullptr)
            {
                window.draw(grain->get_part());
            }
}
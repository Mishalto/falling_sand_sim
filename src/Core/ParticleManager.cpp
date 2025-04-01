#include <ParticleManager.hpp>

ParticleManager::ParticleManager() : grid_(GridData::y_cells, std::vector<ParticlePtr>(GridData::x_cells)) {}

void ParticleManager::update() {    // move all sand grains that are free to fall downwards
    static constexpr int s = 1;     // s - step
    // loop over all the rows of sand grains
    // we start at the bottom because a grain moving my liberate grains higher up
    for (int krow = grid_.size() - 1; krow >= 0; krow--) {
        for (auto& grain : grid_[krow]) {               // loop over the grains in the row
            if (grain == nullptr) { continue; }         // check that location holds a grain
            if (grain->is_at_rest()) { continue; }      // check that grain is not blocked

            sf::Vector2i cd = grain->get_coord();       // current location

            if (cd.y + s >= grid_.size()) {             // the grain is resting on the bottom of the grid
                grain->set_at_rest(true);
                continue;
            }
            // try moving grain down
            bool fMoved = false;
            if (bottom_is_empty(cd)) {
                grain->move({0, s});
                grid_[cd.y + s][cd.x] = std::move(grid_[cd.y][cd.x]);
                fMoved = true;
            } else if (bottom_right_is_empty(cd)) {
                grain->move({s, 0});
                grid_[cd.y][cd.x + s] = std::move(grid_[cd.y][cd.x]);
                fMoved = true;
            } else if (bottom_left_is_empty(cd)) {
                grain->move({-s, 0});
                grid_[cd.y][cd.x - s] = std::move(grid_[cd.y][cd.x]);;
                fMoved = true;
            }

            if (fMoved) {
                free_grains_above(cd);      // free grains that may have been blocked;
            } else {
                grain->set_at_rest(true); // grain is blocked
            }
        }
    }
}

void ParticleManager::add_particle(sf::Vector2i mouse_pos) {            // Grain is created using the mouse pos
    sf::Vector2i grid_pos = {                                           // Convert the mouse position to grid coordinates.
        static_cast<int>(mouse_pos.x / ParticleStats::size),
        static_cast<int>(mouse_pos.y / ParticleStats::size)};

    if (grid_[grid_pos.y][grid_pos.x] != nullptr)                       // check that there is no grain already at this position
        return;
    grid_[grid_pos.y][grid_pos.x] = ParticlePtr(new Sand(grid_pos));    // construct the grain
}

void ParticleManager::free_grains_above(const sf::Vector2i& location) {
    // free grains that may have been blocked;
    if (location.y - 1 < 0) { return; }
    auto n = grid_[location.y - 1][location.x];
    if (n != nullptr)
        n->set_at_rest(false);
    if (location.x - 1 >= 0) {
        n = grid_[location.y - 1][location.x - 1];
        if (n != nullptr)
            n->set_at_rest(false);
    }
    if (location.x + 1 < grid_[0].size()) {
        n = grid_[location.y - 1][location.x + 1];
        if (n != nullptr)
            n->set_at_rest(false);
    }
}

// Checks if adjacent cells in the specified direction are empty to allow particle movement.
bool ParticleManager::bottom_is_empty(const sf::Vector2i& cd) const {
    return grid_[cd.y + 1][cd.x] == nullptr;
}
bool ParticleManager::bottom_right_is_empty(const sf::Vector2i& cd) const {
    return cd.x + 1 < grid_[0].size() && grid_[cd.y][cd.x + 1] == nullptr &&
    grid_[cd.y + 1][cd.x + 1] == nullptr;
}
bool ParticleManager::bottom_left_is_empty(const sf::Vector2i& cd) const {
    return cd.x - 1 >= 0 && grid_[cd.y][cd.x - 1] == nullptr &&
    grid_[cd.y + 1][cd.x - 1] == nullptr;
}

void ParticleManager::draw(sf::RenderWindow &window) {
    for (auto &row : grid_) for (auto grain : row) if (grain != nullptr) { window.draw(grain->get_part()); }
}
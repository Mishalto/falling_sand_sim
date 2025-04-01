#include <ParticleManager.hpp>

ParticleManager::ParticleManager()
    : grid_(Grid::y_cells, std::vector<grain_t>(Grid::x_cells)) {
}

void ParticleManager::update() {
    // move all sand grains that are free to fall downwards

    static constexpr int step = 1;

    // loop over all the rows of sand grains
    // we start at the bottom because a grain moving my liberate grains higher up
    for (int krow = grid_.size() - 1; krow >= 0; krow--)
    {
        // loop over the grains in the row
        for (grain_t grain : grid_[krow])
        {
            // check that location holds a grain
            if (grain == NULL)
                continue;

            // check that grain is not blocked
            if (grain->is_at_rest())
                continue;

            // current location
            sf::Vector2i cd = grain->get_coord();

            if (cd.y + step >= grid_.size()) {
                // the grain is resting on the bottom of the grid
                grain->set_at_rest(true);
                continue;
            }

            // try moving grain down
            bool fMoved = false;
            if (grid_[cd.y + step][cd.x] == NULL) {
                // cell below is empty so grain can fall straight down
                grain->move({0, step});
                grid_[cd.y + step][cd.x] = grain;
                grid_[cd.y][cd.x] = NULL;
                fMoved = true;
            } else if (cd.x + step < grid_[0].size() && grid_[cd.y][cd.x + step] == NULL &&
                       grid_[cd.y + step][cd.x + step] == NULL) {
                // cells on right and down right are available
                // move right
                grain->move({step, 0});
                grid_[cd.y][cd.x + step] = grain;
                grid_[cd.y][cd.x] = NULL;
                fMoved = true;
            } else if (cd.x - step >= 0 && grid_[cd.y][cd.x - step] == NULL &&
                       grid_[cd.y + step][cd.x - step] == NULL) {
                // cells on left and down left are available
                // move left
                grain->move({-step, 0});
                grid_[cd.y][cd.x - step] = grain;
                grid_[cd.y][cd.x] = NULL;
                fMoved = true;
            }

            if (fMoved) {
                // free grains that may have been blocked;
                freeGrainsAbove(cd);
            } else {
                // grain is blocked
                grain->set_at_rest(true);
            }
        }
    }
}

void ParticleManager::add_grain(sf::Vector2i mouse_pos) {
    // Grain is created using the mouse pos

    // Convert the mouse position to grid coordinates.
    sf::Vector2i grid_pos = {
        static_cast<int>(mouse_pos.x / GrainStats::size),
        static_cast<int>(mouse_pos.y / GrainStats::size)};

    // check that there is no grain already at this position
    if (grid_[grid_pos.y][grid_pos.x] != NULL)
        return;

    // construct the grain
    grid_[grid_pos.y][grid_pos.x] = grain_t(new Grain(grid_pos));
}

void ParticleManager::draw(sf::RenderWindow &window)
{
    for (auto &row : grid_)
        for (auto grain : row)
            if (grain != NULL)
                window.draw(grain->get_part());
}

void ParticleManager::freeGrainsAbove(const sf::Vector2i &location) {
    // free grains that may have been blocked;
    if (location.y - 1 < 0)
        return;
    auto n = grid_[location.y - 1][location.x];
    if (n != NULL)
        n->set_at_rest(false);
    if (location.x - 1 >= 0) {
        n = grid_[location.y - 1][location.x - 1];
        if (n != NULL)
            n->set_at_rest(false);
    }
    if (location.x + 1 < grid_.size()) {
        n = grid_[location.y - 1][location.x + 1];
        if (n != NULL)
            n->set_at_rest(false);
    }
}
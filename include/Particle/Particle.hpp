#pragma once

#include <SFML/Graphics.hpp>

class Particle {
private:
    sf::RectangleShape particle_;
    sf::Vector2i coordinate_;
    bool is_at_rest_;
public:
    Particle(const sf::Vector2i& coord);

    virtual void move(sf::Vector2i coord) = 0;

    sf::RectangleShape& get_part();
    sf::Vector2i& get_coord();

    void set_at_rest(bool cond);
    bool is_at_rest() const;
};
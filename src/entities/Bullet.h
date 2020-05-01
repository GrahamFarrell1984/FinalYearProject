#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>

#include "BaseEntity.h"

class Bullet : public BaseEntity
{
public:
    Bullet(sf::Vector2f pos, sf::Vector2f vel);

    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;



private:
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::RectangleShape m_rect;
};
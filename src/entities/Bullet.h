#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "BaseEntity.h"
#include "EntityTypes.h"

class Bullet : public BaseEntity
{
public:
    Bullet(sf::Vector2f pos, Entity::Direction);

    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;

private:
    // Diff speed for diff weapons ?
    static constexpr auto kBulletSpeed = 8;

    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::RectangleShape m_rect;
};
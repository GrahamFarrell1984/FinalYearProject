#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "BaseEntity.h"

class Zombie : public BaseEntity
{
public:
    Zombie(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

    void setPosition(sf::Vector2f pos);

    Rect getBounds() const;

private:
    sf::Sprite m_sprite;
    sf::Vector2f m_pos;
    sf::RectangleShape m_rect;
};

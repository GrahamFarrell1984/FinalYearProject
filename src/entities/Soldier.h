#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "AnimatedSprite.h"
#include "BaseEntity.h"

class Soldier : public BaseEntity
{
public:
    Soldier(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;
    Rect getBounds() const;

private:
    Anim::State m_animState;
    sf::Vector2f m_pos;
    sf::RectangleShape m_rect;
    AnimatedSprite m_animSprite;
};

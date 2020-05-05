#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "AnimatedSprite.h"
#include "AnimationStates.h"
#include "BaseEntity.h"
#include "EntityTypes.h"

class Bullet : public BaseEntity
{
public:
    Bullet(sf::Vector2f position, Entity::Direction, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;
    Entity::State getState() const;
    void setIsHit();

private:
    // Diff speed for diff weapons ?
    static constexpr auto BulletSpeed = 8;
    static constexpr auto MaxDistance = 100;
    static constexpr Rect ClsnUpOffset{ 9, -4, 7, 16 };
    static constexpr Rect ClsnDownOffset{ 9, 24, 7, 16 };
    static constexpr Rect ClsnLeftOffset{ -16, 15, 18, 5 };
    static constexpr Rect ClsnRightOffset{ 24, 15, 18, 5 };

    sf::Vector2f m_position;
    sf::Vector2f m_startPosition;
    sf::Vector2f m_velocity;
    sf::RectangleShape m_rect;
    Point m_clsnOffset;
    Entity::Direction m_direction;
    Entity::State m_state;
    Anim::State m_animState;
    AnimatedSprite m_animSprite;
};

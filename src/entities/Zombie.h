#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "AnimatedSprite.h"
#include "BaseEntity.h"
#include "EntityTypes.h"

class Zombie : public BaseEntity
{
public:
    Zombie(sf::Vector2f position, const sf::Vector2f& playerPos, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;
    void setPosition(sf::Vector2f pos);
    Rect getBounds() const;
    Entity::State getState() const;
    void setIsHit();

private:
    void changeDirection();
    void checkBounds();

    static constexpr auto CloseDistance = 10;
    static constexpr auto MaxDistanceFollow = 100;
    static constexpr auto WanderSpeed = 1;
    static constexpr auto ChaseSpeed = 1.5f;
    static constexpr auto DirectionTicks = 50;
    static constexpr auto ChaseDirectionTicks = 20;

    Entity::Direction m_dir;
    Entity::State m_state;
    Anim::State m_animState;
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    float m_speed;
    uint32_t m_tick;
    sf::RectangleShape m_rect;
    AnimatedSprite m_animSprite;
    const sf::Vector2f& m_playerPos;
};

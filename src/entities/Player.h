#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <utility>

#include "AnimatedSprite.h"
#include "BaseEntity.h"
#include "Keyboard.h"

class Player : public BaseEntity
{
public:
    Player(sf::Vector2f position, const sf::Texture* texture);

    void processInput(const Keyboard& keyboard);
    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;
    sf::Vector2f getPos() const;
    Entity::Direction getDir() const;

    bool checkHasFired() const;
    void setHasFired(bool fire);

private:
    static constexpr auto NormalSpeed  = 2;
    static constexpr auto PowerUpSpeed = 4;
    static constexpr auto BulletTickCD = 8;

    void updateMovingState();
    void updateFiringState();

    bool m_hasFired;
    bool m_moving;
    uint32_t m_speed;
    uint32_t m_bulletTick;
    Entity::Direction m_dir;
    Entity::State m_state;
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::RectangleShape m_rect;
    AnimatedSprite m_animSprite;
};
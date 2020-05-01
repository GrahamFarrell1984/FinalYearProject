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
    sf::Vector2f getVel() const;

    bool checkHasFired() const;
    void setHasFired(bool fire);

private:
    bool m_hasFired;
    Entity::State m_prevState;
    Entity::State m_currState;
    float    m_speed;
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::RectangleShape m_rect;
    AnimatedSprite m_animSprite;
};
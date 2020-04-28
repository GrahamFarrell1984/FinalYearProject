#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

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

private:
    Entity::State m_prevState;
    Entity::State m_currState;
    sf::Vector2f m_pos;
    AnimatedSprite m_animSprite;


};
#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <utility>

#include "AnimatedSprite.h"
#include "AnimationStates.h"
#include "BaseEntity.h"
#include "EntityTypes.h"
#include "Keyboard.h"

class Civilian : public BaseEntity
{
public:
    Civilian(sf::Vector2f position, const sf::Texture* texture);

    void processInput(const Keyboard& keyboard);
    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;

private:
    sf::Vector2f m_pos;
    sf::RectangleShape m_rect;
    Anim::State m_animState;
    AnimatedSprite m_animSprite;
};
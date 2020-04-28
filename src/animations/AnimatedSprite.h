#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_map>
#include <vector>

#include "EntityData.h"
#include "EntityTypes.h"
#include "Types.h"

class AnimatedSprite
{
public:
    AnimatedSprite(sf::Vector2f pos,
                   const sf::Texture* texture,
                   const FrameData& frameData,
                   const AnimData& animData);

    void changeState(Entity::State state);
    void updatePosition(sf::Vector2f pos);
    void checkForFrameUpdate();
    void render(sf::RenderWindow& window);

private:
    sf::Uint8 m_tick;           // Current ticks
    sf::Uint8 m_frameIndex;     // Current Frame Index
    Frame m_frame;
    Entity::State m_state;
    sf::Sprite m_sprite;

    const FrameData& m_frameData;
    const AnimData& m_animData;
};
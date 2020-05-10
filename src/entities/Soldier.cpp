#include "Soldier.h"

Soldier::Soldier(sf::Vector2f position, const sf::Texture* texture)
        : m_animState{ Anim::State::LOOKING_AROUND }
        , m_pos{ position }
        , m_rect{ sf::Vector2f(27, 10) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
{
    // Test
    m_rect.setPosition(m_pos.x + 2, m_pos.y + 39);
    m_rect.setFillColor(sf::Color(0, 255, 0, 100));
}

void Soldier::update()
{
    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();
    m_localBounds = m_animSprite.getBounds();
}

void Soldier::render(sf::RenderWindow& window)
{

    m_animSprite.render(window);
    // Toggle this to turn on and off collision boxes.
//    window.draw(m_rect);
}

Rect Soldier::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_rect.getPosition().x),
                 static_cast<sf::Int32>(m_rect.getPosition().y),
                 static_cast<sf::Int32>(m_rect.getSize().x),
                 static_cast<sf::Int32>(m_rect.getSize().y) };
}
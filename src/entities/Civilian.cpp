#include "Civilian.h"

Civilian::Civilian(sf::Vector2f position, const sf::Texture* texture)
        : m_animState{ Anim::State::JUMPING }
        , m_pos{ position }
        , m_rect{ sf::Vector2f(20, 10) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
{
    // Test
    m_rect.setPosition(m_pos.x + 13, m_pos.y + 60);
    m_rect.setFillColor(sf::Color(0, 255, 0, 100));
}

void Civilian::update()
{
    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();
    m_localBounds = m_animSprite.getBounds();
}

void Civilian::render(sf::RenderWindow& window)
{

    m_animSprite.render(window);
    // Toggle this to turn on and off collision boxes.
    window.draw(m_rect);
}

Rect Civilian::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_rect.getPosition().x),
                 static_cast<sf::Int32>(m_rect.getPosition().y),
                 static_cast<sf::Int32>(m_rect.getSize().x),
                 static_cast<sf::Int32>(m_rect.getSize().y) };
}
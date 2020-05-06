#include "Zombie.h"

Zombie::Zombie(sf::Vector2f position, const sf::Texture* texture)
        : m_animState{ Anim::State::ZOMBIEWALKINGUP }
        , m_pos { position }
        , m_rect{ sf::Vector2f(24, 48) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
{
//    m_sprite.setTexture(*texture);
//    m_sprite.setPosition(position);

    // Test
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255,0,0,100));
}

void Zombie::update()
{
    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();
    m_localBounds = m_animSprite.getBounds();
//    m_rect.setPosition(m_pos.x, m_pos.y);
//    m_sprite.setPosition(m_pos);
}

void Zombie::render(sf::RenderWindow& window)
{
    m_animSprite.render(window);
//    window.draw(m_sprite);
    window.draw(m_rect);
}

void Zombie::setPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

Rect Zombie::getBounds() const
{
    return Rect {
            static_cast<sf::Int32>(m_rect.getPosition().x),
            static_cast<sf::Int32>(m_rect.getPosition().y),
            static_cast<sf::Int32>(m_rect.getSize().x),
            static_cast<sf::Int32>(m_rect.getSize().y)
    };
}

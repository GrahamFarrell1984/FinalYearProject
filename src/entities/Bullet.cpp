#include "Bullet.h"

#include <SFML/Graphics/Texture.hpp>

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel)
        : m_pos { pos }
        , m_vel { vel }
        , m_rect{ sf::Vector2f(10, 10) }
{
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255,0,0,100));
}

void Bullet::update()
{
    m_pos.x += m_vel.x * 5.f;
    m_pos.y += m_vel.y * 5.f;
    m_rect.setPosition(m_pos.x, m_pos.y);

    if (m_pos.x < 0 || m_pos.x > 1024 || m_pos.y <  0 || m_pos.y > 768 ) {
        m_destroyed = true;
    }
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(m_rect);
}

Rect Bullet::getBounds() const
{
    return Rect {
            static_cast<int32_t>(m_rect.getPosition().x),
            static_cast<int32_t>(m_rect.getPosition().y),
            static_cast<int32_t>(m_rect.getSize().x),
            static_cast<int32_t>(m_rect.getSize().y)
    };
}
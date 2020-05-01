#include "Bullet.h"

#include <SFML/Graphics/Texture.hpp>

Bullet::Bullet(sf::Vector2f pos, Entity::Direction dir)
        : m_pos{ pos }
        , m_vel{ 0, 0 }
        , m_rect{ sf::Vector2f(10, 10) }
{
    if (dir == Entity::Direction::Up) {
        m_vel = sf::Vector2f(0, -1);
    } else if (dir == Entity::Direction::Down) {
        m_vel = sf::Vector2f(0, 1);
    } else if (dir == Entity::Direction::Left) {
        m_vel = sf::Vector2f(-1, 0);
    } else if (dir == Entity::Direction::Right) {
        m_vel = sf::Vector2f(1, 0);
    }

    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255, 0, 0, 100));
}

void Bullet::update()
{
    m_pos.x += (m_vel.x * kBulletSpeed);
    m_pos.y += (m_vel.y * kBulletSpeed);
    m_rect.setPosition(m_pos.x, m_pos.y);

    if (m_pos.x < 0 || m_pos.x > 1024 || m_pos.y < 0 || m_pos.y > 768) {
        m_destroyed = true;
    }
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(m_rect);
}

Rect Bullet::getBounds() const
{
    return Rect{ static_cast<int32_t>(m_rect.getPosition().x),
                 static_cast<int32_t>(m_rect.getPosition().y),
                 static_cast<int32_t>(m_rect.getSize().x),
                 static_cast<int32_t>(m_rect.getSize().y) };
}
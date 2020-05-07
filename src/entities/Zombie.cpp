#include "Zombie.h"
#include<math.h>

Zombie::Zombie(sf::Vector2f position, const sf::Vector2f& playerPos, const sf::Texture* texture)
        : m_dir{ Entity::Direction::Down }
        , m_state{ Entity::State::SPAWNING }
        , m_animState{ Anim::State::ZOMBIESPAWNING }
        , m_pos{ position }
        , m_vel{ 0, 0 }
        , m_rect{ sf::Vector2f(34, 53) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
        , m_playerPos { playerPos }
{

    // Test
    m_rect.setPosition(m_pos.x + 5, m_pos.y + 10);
    m_rect.setFillColor(sf::Color(255,0,0,100));
}

void Zombie::update()
{
    if (m_state == Entity::State::SPAWNING && m_animSprite.isAnimFinishedPlaying()) {
        m_state = Entity::State::STANDING;
        m_animState = Anim::State::ZOMBIEMOVINGDOWN;
        m_dir = Entity::Direction::Down;
    } else if (m_state == Entity::State::DYING && m_animSprite.isAnimFinishedPlaying()) {
        m_destroyed = true;
    } else {
//        double distance = sqrt(pow(m_pos.x - m_playerPos.x, 2) + pow(m_pos.y - m_playerPos.y, 2));
//        if (distance < MaxDistanceFollow) {
//            m_animState = Anim::State::ZOMBIEEXPLODING;
//        } else {
//            m_animState = Anim::State::ZOMBIEMOVINGDOWN;
//        }

        // Logic to move around here.
    }

    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();
    m_localBounds = m_animSprite.getBounds();
}

void Zombie::render(sf::RenderWindow& window)
{
    m_animSprite.render(window);
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

void Zombie::setIsHit()
{
    if (m_state != Entity::State::SPAWNING && m_state != Entity::State::DYING) {
        m_state     = Entity::State::DYING;
        m_animState = Anim::State::ZOMBIEEXPLODING;
        m_vel       = sf::Vector2f(0, 0);
    }
}
Entity::State Zombie::getState() const
{
    return m_state;
}
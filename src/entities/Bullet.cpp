#include <SFML/Graphics/Texture.hpp>

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, Entity::Direction direction, const sf::Texture* texture)
        : m_position{ position }
        , m_startPosition{ position }
        , m_velocity{ 0, 0 }
        , m_rect{ }
        , m_clsnOffset{ }
        , m_direction{ direction }
        , m_state{ Entity::State::MOVING }
        , m_animState{ Anim::State::NONE }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
{
    switch (m_direction) {
        case Entity::Direction::Up:
            m_velocity = sf::Vector2f(0, -1);
            m_clsnOffset = { ClsnUpOffset.x, ClsnUpOffset.y };
            m_rect.setSize(sf::Vector2f(ClsnUpOffset.w, ClsnUpOffset.h));
            m_animState = Anim::State::BULLET_UP;
            break;
        case Entity::Direction::Down:
            m_velocity = sf::Vector2f(0, 1);
            m_clsnOffset = { ClsnDownOffset.x, ClsnDownOffset.y };
            m_rect.setSize(sf::Vector2f(ClsnDownOffset.w, ClsnDownOffset.h));
            m_animState = Anim::State::BULLET_DOWN;
            break;
        case Entity::Direction::Left:
            m_velocity = sf::Vector2f(-1, 0);
            m_clsnOffset = { ClsnLeftOffset.x, ClsnLeftOffset.y };
            m_rect.setSize(sf::Vector2f(ClsnLeftOffset.w, ClsnLeftOffset.h));
            m_animState = Anim::State::BULLET_LEFT;
            break;
        case Entity::Direction::Right:
            m_velocity = sf::Vector2f(1, 0);
            m_clsnOffset = { ClsnRightOffset.x, ClsnRightOffset.y };
            m_rect.setSize(sf::Vector2f(ClsnRightOffset.w, ClsnRightOffset.h));
            m_animState = Anim::State::BULLET_RIGHT;
            break;
    }
    m_rect.setPosition(m_position.x, m_position.y);
    m_rect.setFillColor(sf::Color(255, 0, 0, 100));
}

void Bullet::update()
{
    if (m_state == Entity::State::DYING && m_animSprite.isAnimFinishedPlaying()) {
        m_state = Entity::State::DEAD;
        m_destroyed = true;
    } else {
        m_position.x += (m_velocity.x * BulletSpeed);
        m_position.y += (m_velocity.y * BulletSpeed);
        m_rect.setPosition(m_position.x + m_clsnOffset.x, m_position.y + m_clsnOffset.y);
        m_animSprite.updatePosition(m_position);

        // Clean Up this shite
        if (std::abs(m_position.x - m_startPosition.x) > MaxDistance || std::abs(m_position.y - m_startPosition.y) > MaxDistance) {
            setIsHit();
        }

    }
    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();

    m_localBounds = m_animSprite.getBounds();
}

void Bullet::render(sf::RenderWindow& window)
{
    m_animSprite.render(window);
    // Uncomment to see collision boxes
    // window.draw(m_rect);
}

Rect Bullet::getBounds() const
{
    return Rect{ static_cast<int32_t>(m_rect.getPosition().x),
                 static_cast<int32_t>(m_rect.getPosition().y),
                 static_cast<int32_t>(m_rect.getSize().x),
                 static_cast<int32_t>(m_rect.getSize().y) };
}

Entity::State Bullet::getState() const
{
    return m_state;
}

void Bullet::setIsHit()
{
    m_state = Entity::State::DYING;
    m_velocity = sf::Vector2f(0,0);
    switch (m_direction) {
        case Entity::Direction::Up:
            m_animState = Anim::State::BULLET_DYING_UP;
            break;
        case Entity::Direction::Down:
            m_animState = Anim::State::BULLET_DYING_DOWN;
            break;
        case Entity::Direction::Left:
            m_animState = Anim::State::BULLET_DYING_LEFT;
            break;
        case Entity::Direction::Right:
            m_animState = Anim::State::BULLET_DYING_RIGHT;
            break;
    }
}

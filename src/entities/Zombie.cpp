#include "AudioManager.h"
#include "math.h"
#include "Zombie.h"

Zombie::Zombie(sf::Vector2f position, const sf::Vector2f& playerPos, const sf::Texture* texture)
        : m_dir{ Entity::Direction::Down }
        , m_state{ Entity::State::SPAWNING }
        , m_animState{ Anim::State::ZOMBIE_SPAWNING }
        , m_pos{ position }
        , m_vel{ 0, 0 }
        , m_speed { WanderSpeed }
        , m_tick { 0 }
        , m_rect{ sf::Vector2f(20, 20) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
        , m_playerPos { playerPos }
{
    // Test
    m_rect.setPosition(m_pos.x + 5, m_pos.y + 10);
    m_rect.setFillColor(sf::Color(255,0,0,100));
}

void Zombie::update()
{
    if (m_state == Entity::State::SPAWNING) {
        if (m_animSprite.isAnimFinishedPlaying()) {
            changeDirection();
        }
    } else if (m_state == Entity::State::DYING) {
        if (m_animSprite.isAnimFinishedPlaying()) {
            m_destroyed = true;
        }
    } else {
        m_speed = ChaseSpeed;
        double distance = sqrt(pow(m_pos.x - m_playerPos.x, 2) + pow(m_pos.y - m_playerPos.y, 2));
        if (distance < CloseDistance) {
            m_vel = sf::Vector2f(0, 0);
        } else if (distance < MaxDistanceFollow) {
            ++m_tick;
            if (m_tick >= ChaseDirectionTicks) {
                m_tick = 0;
                int32_t xDist = m_playerPos.x - m_pos.x;
                int32_t yDist = m_playerPos.y - m_pos.y;
                if (std::abs(xDist) >= std::abs(yDist)) {
                    if (xDist < 0) {
                        m_vel       = sf::Vector2f(-1, 0);
                        m_dir       = Entity::Direction::Left;
                        m_animState = Anim::State::ZOMBIE_MOVING_LEFT;
                    } else {
                        m_vel       = sf::Vector2f(1, 0);
                        m_dir       = Entity::Direction::Right;
                        m_animState = Anim::State::ZOMBIE_MOVING_RIGHT;
                    }
                } else {
                    if (yDist < 0) {
                        m_vel       = sf::Vector2f(0, -1);
                        m_dir       = Entity::Direction::Up;
                        m_animState = Anim::State::ZOMBIE_MOVING_UP;
                    } else {
                        m_vel       = sf::Vector2f(0, 1);
                        m_dir       = Entity::Direction::Down;
                        m_animState = Anim::State::ZOMBIE_MOVING_DOWN;
                    }
                }
            }
        } else {
            ++m_tick;
            m_speed = WanderSpeed;
            if (m_tick >= DirectionTicks) {
                changeDirection();
            }
            checkBounds();
        }

    }
    m_pos.x += m_vel.x * m_speed;
    m_pos.y += m_vel.y * m_speed;

    m_animSprite.updatePosition(m_pos);
    m_rect.setPosition(m_pos.x + 10, m_pos.y + 30);

    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();
    m_localBounds = m_animSprite.getBounds();
}

void Zombie::render(sf::RenderWindow& window)
{
    m_animSprite.render(window);
    // Toggle this to turn on and off collision boxes.
//    window.draw(m_rect);
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
    m_state     = Entity::State::DYING;
    m_animState = Anim::State::ZOMBIE_EXPLODING;
    m_vel       = sf::Vector2f(0, 0);
    m_rect.setPosition(sf::Vector2f(-1000, -1000));
    Singleton<AudioManager>::getInstance().playSound(Assets::Sfx::SFXC.id);
}
Entity::State Zombie::getState() const
{
    return m_state;
}

void Zombie::changeDirection()
{
    m_tick         = 0;
    m_state        = Entity::State::MOVING;
    auto randomNum = static_cast<uint32_t>(rand() % 4);
    switch (randomNum) {
        case 0:
            m_vel       = sf::Vector2f(0, -1);
            m_dir       = Entity::Direction::Up;
            m_animState = Anim::State::ZOMBIE_MOVING_UP;
            break;
        case 1:
            m_vel       = sf::Vector2f(0, 1);
            m_dir       = Entity::Direction::Down;
            m_animState = Anim::State::ZOMBIE_MOVING_DOWN;
            break;
        case 2:
            m_vel       = sf::Vector2f(-1, 0);
            m_dir       = Entity::Direction::Left;
            m_animState = Anim::State::ZOMBIE_MOVING_LEFT;
            break;
        case 3:
            m_vel       = sf::Vector2f(1, 0);
            m_dir       = Entity::Direction::Right;
            m_animState = Anim::State::ZOMBIE_MOVING_RIGHT;
            break;
        default:
            break;
    }
}
void Zombie::checkBounds()
{
    if (m_pos.x <= 50) {
        m_vel       = sf::Vector2f(1, 0);
        m_dir       = Entity::Direction::Right;
        m_animState = Anim::State::ZOMBIE_MOVING_RIGHT;
        m_tick = 0;
    } else if (m_pos.x + m_localBounds.w >= 1998) {
        m_vel       = sf::Vector2f(-1, 0);
        m_dir       = Entity::Direction::Left;
        m_animState = Anim::State::ZOMBIE_MOVING_LEFT;
        m_tick = 0;
    } else if (m_pos.y + m_localBounds.h <= 50) {
        m_vel       = sf::Vector2f(0, 1);
        m_dir       = Entity::Direction::Down;
        m_animState = Anim::State::ZOMBIE_MOVING_DOWN;
        m_tick = 0;
    } else if (m_pos.y + m_localBounds.h >= 1480) {
        m_vel       = sf::Vector2f(0, -1);
        m_dir       = Entity::Direction::Up;
        m_animState = Anim::State::ZOMBIE_MOVING_UP;
        m_tick = 0;
    }
}

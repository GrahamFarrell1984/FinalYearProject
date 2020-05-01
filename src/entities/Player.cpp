#include "Player.h"

Player::Player(sf::Vector2f position, const sf::Texture* texture)
        : m_hasFired{ false }
        , m_moving{ false }
        , m_speed{ NormalSpeed }
        , m_bulletTick { BulletTickCD }
        , m_dir{ Entity::Direction::Down }
        , m_state{ Entity::State::STANDFACINGDOWN }
        , m_pos{ position }
        , m_vel{ 0, 1 }
        , m_rect{ sf::Vector2f(26, 42) }
        , m_animSprite{ position, texture, PlayerSpriteData, PlayerAnimation }
{
    // Test
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255, 0, 0, 100));
}

void Player::processInput(const Keyboard& keyboard)
{
    m_moving = true;

    if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::HOLD)) {
        m_dir = Entity::Direction::Up;
        m_vel = sf::Vector2f(0, -1);
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::HOLD)) {
        m_dir = Entity::Direction::Down;
        m_vel = sf::Vector2f(0, 1);
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Left, State::HOLD)) {
        m_dir = Entity::Direction::Left;
        m_vel = sf::Vector2f(-1, 0);
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Right, State::HOLD)) {
        m_dir = Entity::Direction::Right;
        m_vel = sf::Vector2f(1, 0);
    } else {
        m_moving = false;
        m_vel = sf::Vector2f(0, 0);
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Space, State::HOLD)) {
        if (!m_hasFired) {
            if (m_bulletTick >= BulletTickCD) {
                m_hasFired = true;
                m_bulletTick = 0;
            }
            // Temp
            m_vel = sf::Vector2f(0, 0);
            updateFiringState();
        }
    } else {
        updateMovingState();
    }
}

void Player::update()
{
    ++m_bulletTick;
    m_pos.x += m_vel.x * m_speed;
    m_pos.y += m_vel.y * m_speed;

    m_animSprite.updatePosition(m_pos);
    m_rect.setPosition(m_pos.x, m_pos.y);
}

void Player::render(sf::RenderWindow& window)
{
    m_animSprite.changeState(m_state);
    m_animSprite.checkForFrameUpdate();

    m_animSprite.render(window);
    // Toggle this to turn on and off collision boxes.
    window.draw(m_rect);
}

Rect Player::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_rect.getPosition().x),
                 static_cast<sf::Int32>(m_rect.getPosition().y),
                 static_cast<sf::Int32>(m_rect.getSize().x),
                 static_cast<sf::Int32>(m_rect.getSize().y) };
}

sf::Vector2f Player::getPos() const
{
    return m_pos;
}

Entity::Direction Player::getDir() const
{
    return m_dir;
}

bool Player::checkHasFired() const
{
    return m_hasFired;
}

void Player::setHasFired(bool hasFired)
{
    m_hasFired = hasFired;
}

void Player::updateMovingState()
{
    switch (m_dir) {
        case Entity::Direction::Up :
            m_state = m_moving ? Entity::State::MOVEUP : Entity::State::STANDFACINGUP;
            break;
        case Entity::Direction::Down:
            m_state = m_moving ? Entity::State::MOVEDOWN : Entity::State::STANDFACINGDOWN;
            break;
        case Entity::Direction::Left:
            m_state = m_moving ? Entity::State::MOVELEFT : Entity::State::STANDFACINGLEFT;
            break;
        case Entity::Direction::Right:
            m_state = m_moving ? Entity::State::MOVERIGHT : Entity::State::STANDFACINGRIGHT;
            break;
    }
}

void Player::updateFiringState()
{
    switch (m_dir) {
        case Entity::Direction::Up :
            m_state = Entity::State::SHOOTUP;
            //m_state = m_moving ? Entity::State::MOVEUP : Entity::State::STANDFACINGUP;
            break;
        case Entity::Direction::Down:
            m_state = Entity::State::SHOOTDOWN;
            //m_state = m_moving ? Entity::State::MOVEDOWN : Entity::State::STANDFACINGDOWN;
            break;
        case Entity::Direction::Left:
            m_state = Entity::State::SHOOTLEFT;
            //m_state = m_moving ? Entity::State::MOVELEFT : Entity::State::STANDFACINGLEFT;
            break;
        case Entity::Direction::Right:
            m_state = Entity::State::SHOOTRIGHT;
            //m_state = m_moving ? Entity::State::MOVERIGHT : Entity::State::STANDFACINGRIGHT;
            break;
    }
}
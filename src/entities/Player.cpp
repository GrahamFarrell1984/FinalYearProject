#include "Player.h"

Player::Player(sf::Vector2f position, const sf::Texture* texture)
        : m_hasFired{ false }
        , m_prevState{ Entity::State::STANDFACINGDOWN }
        , m_currState{ Entity::State::STANDFACINGDOWN }
        , m_speed { 2.f }
        , m_pos{ position }
        , m_vel{ 0, 1}
        , m_rect{ sf::Vector2f(52, 50) }
        , m_animSprite{ position, texture, PlayerSpriteData, PlayerAnimation }
{
    // Test
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255, 0, 0, 100));

    // Set Animation state
    m_animSprite.changeState(Entity::State::STANDFACINGDOWN);
}

void Player::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::HOLD)) {
        m_currState = Entity::State::MOVEDOWN;
        m_pos.y += 2;
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::HOLD)) {
        m_currState = Entity::State::MOVEUP;
        m_pos.y -= 2;
    } else {
        switch (m_currState) {
            case Entity::State::MOVEDOWN:
                m_currState = Entity::State::STANDFACINGDOWN;
                break;
            case Entity::State::MOVEUP:
                m_currState = Entity::State::STANDFACINGUP;
                break;
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Right, State::HOLD)) {
        m_currState = Entity::State::MOVERIGHT;
        m_pos.x += 2;
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Left, State::HOLD)) {
        m_currState = Entity::State::MOVELEFT;
        m_pos.x -= 2;
    } else {
        switch (m_currState) {
            case Entity::State::MOVERIGHT:
                m_currState = Entity::State::STANDFACINGRIGHT;
                break;
            case Entity::State::MOVELEFT:
                m_currState = Entity::State::STANDFACINGLEFT;
                break;
        }
    }
    if (keyboard.checkKeyAndState(sf::Keyboard::Space, State::PRESS)) {
        if (!m_hasFired) {
            m_hasFired = true;
        }
    }
}

void Player::update()
{
    // HACK will fix tomoro
    if (m_currState == Entity::State::MOVELEFT || m_currState == Entity::State::STANDFACINGLEFT) {
        m_vel.x = -1;
    } else if (m_currState == Entity::State::MOVERIGHT || m_currState == Entity::State::STANDFACINGRIGHT) {
        m_vel.x = 1;
    } else {
        m_vel.x = 0;
    }

    if (m_currState == Entity::State::MOVEUP || m_currState == Entity::State::STANDFACINGUP) {
        m_vel.y = -1;
    } else if (m_currState == Entity::State::MOVEDOWN || m_currState == Entity::State::STANDFACINGDOWN) {
        m_vel.y = 1;
    } else {
        m_vel.y = 0;
    }

    m_animSprite.updatePosition(m_pos);
    m_rect.setPosition(m_pos.x, m_pos.y);
}

void Player::render(sf::RenderWindow& window)
{
    if (m_currState != m_prevState) {
        m_animSprite.changeState(m_currState);
    }
    m_animSprite.checkForFrameUpdate();
    m_prevState = m_currState;
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

sf::Vector2f Player::getVel() const
{
    return m_vel;
}

bool Player::checkHasFired() const
{
    return m_hasFired;
}

void Player::setHasFired(bool hasFired)
{
    m_hasFired = hasFired;
}
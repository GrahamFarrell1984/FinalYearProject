#include "Player.h"

Player::Player(sf::Vector2f position, const sf::Texture* texture)
        : m_prevState{ Entity::State::MOVEDOWN }
        , m_currState{ Entity::State::MOVEDOWN }
        , m_pos{ position }
        , m_animSprite{ position, texture, PSD, PANIM }
{
    // Set Animation state
    m_animSprite.changeState(Entity::State::STANDDOWN);
}

void Player::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::HOLD)) {
        m_pos.y +=2;
        m_currState = Entity::State::MOVEDOWN;
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::HOLD)) {
        m_pos.y -=2;
        m_currState = Entity::State::MOVEUP;
    } else {
        switch (m_currState) {
            case Entity::State::MOVEDOWN:
                m_currState = Entity::State::STANDDOWN;
                break;
            case Entity::State::MOVEUP:
                m_currState = Entity::State::STANDUP;
                break;
        }
    }
}

void Player::update()
{
    m_animSprite.updatePosition(m_pos);
}

void Player::render(sf::RenderWindow& window)
{
    if (m_currState != m_prevState) {
        m_animSprite.changeState(m_currState);
    }
    m_animSprite.checkForFrameUpdate();
    m_prevState = m_currState;
    m_animSprite.renderer(window);
}
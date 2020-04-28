#include "Player.h"

Player::Player(sf::Vector2f position, const sf::Texture* texture)
        : m_prevState{ Entity::State::MOVEDOWN }
        , m_currState{ Entity::State::MOVEDOWN }
        , m_pos{ position }
        , m_rect { sf::Vector2f(52, 50) }
        , m_animSprite{ position, texture, PlayerSpriteData, PlayerAnimation }
{
    // Test
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255,0,0,100));

    // Set Animation state
    m_animSprite.changeState(Entity::State::STANDFACINGDOWN);
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
                m_currState = Entity::State::STANDFACINGDOWN;
                break;
            case Entity::State::MOVEUP:
                m_currState = Entity::State::STANDFACINGUP;
                break;
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Right, State::HOLD)) {
        m_pos.x +=2;
        m_currState = Entity::State::MOVERIGHT;
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Left, State::HOLD)) {
        m_pos.x -=2;
        m_currState = Entity::State::MOVELEFT;
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
}

void Player::update()
{
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
    return Rect {
            static_cast<sf::Int32>(m_rect.getPosition().x),
            static_cast<sf::Int32>(m_rect.getPosition().y),
            static_cast<sf::Int32>(m_rect.getSize().x),
            static_cast<sf::Int32>(m_rect.getSize().y)
    };
}

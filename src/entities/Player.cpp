#include "Player.h"
#include "TextureData.h"

Player::Player() : m_dir(Direction::DOWN)
{
}

void Player::setup(sf::Vector2f position, const sf::Texture* texture)
{
    m_sprite.setTexture(*texture);
    m_sprite.setTextureRect(sf::IntRect(PDOWN.x, PDOWN.y, PDOWN.w, PDOWN.h));
    m_sprite.setPosition(position);
}


void Player::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::HOLD)) {
        m_sprite.move(0, -2);
        m_dir = Direction::UP;
        m_sprite.setTextureRect(sf::IntRect(PUP.x, PUP.y, PUP.w, PUP.h));
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::HOLD)) {
        m_sprite.move(0, 2);
        m_dir = Direction::DOWN;
        m_sprite.setTextureRect(sf::IntRect(PDOWN.x, PDOWN.y, PDOWN.w, PDOWN.h));
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Left, State::HOLD)) {
        m_sprite.move(-2, 0);
        m_dir = Direction::LEFT;
        m_sprite.setTextureRect(sf::IntRect(PLEFT.x, PLEFT.y, PLEFT.w, PLEFT.h));
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Right, State::HOLD)) {
        m_sprite.move(2, 0);
        m_dir = Direction::RIGHT;
        m_sprite.setTextureRect(sf::IntRect(PRIGHT.x, PRIGHT.y, PRIGHT.w, PRIGHT.h));
    }
}

void Player::update()
{
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

#include "AudioManager.h"
#include "Player.h"

Player::Player(sf::Vector2f position, sf::Vector2f worldSize, const sf::Texture* texture)
        : m_hasFired{ false }
        , m_moving{ false }
        , m_invincible{ false }
        , m_health{ MaxHealth }
        , m_speed{ NormalSpeed }
        , m_bulletTick{ BulletTickCD }
        , m_invincibleTick{ 0 }
        , m_dir{ Entity::Direction::Down }
        , m_state{ Entity::State::STANDING }
        , m_animState{ Anim::State::STAND_FACING_DOWN }
        , m_pos{ position }
        , m_vel{ 0, 0 }
        , m_worldSize{worldSize }
        , m_rect{ sf::Vector2f(18, 20) }
        , m_animSprite{ position, texture, SpriteData, SpriteAnimation }
        , m_zombiesKilledCount{ 0 }
        , m_cheerleadersRescuedCount{ 0 }
        , m_soldiersRescuedCount { 0 }
        , m_bulletCount{ 100 }
{
    m_rect.setPosition(m_pos.x, m_pos.y);
    m_rect.setFillColor(sf::Color(255, 0, 0, 100));
}

void Player::processInput(const Keyboard& keyboard)
{
    m_moving = true;
    // Only allow input from the keyboard if the player is not dead
    if (m_state != Entity::State::DYING && m_state != Entity::State::HIT) {
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
            m_vel    = sf::Vector2f(0, 0);
        }

        if (keyboard.checkKeyAndState(sf::Keyboard::Space, State::HOLD)) {
            if (!m_hasFired) {
                if (m_bulletTick >= BulletTickCD) {
                    m_hasFired   = true;
                    m_bulletTick = 0;
                }
                m_vel = sf::Vector2f(0, 0);
                updateFiringState();
            }
        } else {
            m_bulletTick = BulletTickCD;
            updateMovingState();
        }
    }
}

void Player::update()
{
    ++m_bulletTick;
    m_pos.x += m_vel.x * m_speed;
    m_pos.y += m_vel.y * m_speed;

    if (m_invincible) {
        ++m_invincibleTick;
        if (m_invincibleTick >= InvincibleTickCD) {
            m_invincibleTick = 0;
            m_invincible     = false;
        }
    }

    if (m_animState == Anim::State::DYING && m_animSprite.isAnimFinishedPlaying()) {
        m_animState = Anim::State::NONE;
        m_state     = Entity::State::DEAD;
    } else if (m_state == Entity::State::HIT && m_animSprite.isAnimFinishedPlaying()) {
        if (m_health <= 0) {
            m_state      = Entity::State::DYING;
            m_animState  = Anim::State::DYING;
            m_invincible = false;
        } else {
            m_invincible = true;
            m_state      = Entity::State::STANDING;
            m_moving     = false;
            updateMovingState();
        }
    }

    m_animSprite.updatePosition(m_pos);
    if (m_pos.x < 16 ) { // Checking world boundary on left
        m_pos.x = 16;
    } else if (m_pos.x + m_localBounds.w > (m_worldSize.x - 16)) { // Checking world boundary on right
        m_pos.x  = (m_worldSize.x - 16) - m_localBounds.w;
    } else if (m_pos.y < 32 ) { // Checking world boundary on top
        m_pos.y = 32;
    } else if (m_pos.y + m_localBounds.h > (m_worldSize.y - 48)) { // Checking world boundary on bottom
        m_pos.y  = (m_worldSize.y - 48) - m_localBounds.h;
    }

    m_rect.setPosition(m_pos.x + ClsnOffset.x, m_pos.y + ClsnOffset.y);
    m_animSprite.changeState(m_animState);
    m_animSprite.checkForFrameUpdate();

    m_localBounds = m_animSprite.getBounds();
}

void Player::render(sf::RenderWindow& window)
{
    if (!m_invincible || (m_invincible && m_invincibleTick % InvisibleDrawTicks == 0)) {
        m_animSprite.render(window);
    }
    // Toggle this to turn on and off collision boxes.
//    window.draw(m_rect);
}

Rect Player::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_rect.getPosition().x),
                 static_cast<sf::Int32>(m_rect.getPosition().y),
                 static_cast<sf::Int32>(m_rect.getSize().x),
                 static_cast<sf::Int32>(m_rect.getSize().y)
    };
}

const sf::Vector2f& Player::getPos() const
{
    return m_pos;
}

Entity::Direction Player::getDir() const
{
    return m_dir;
}

Entity::State Player::getState() const
{
    return m_state;
}

bool Player::isDead() const
{
    return m_state == Entity::State::DEAD;
}

bool Player::isInvincible() const
{
    return m_invincible;
}

void Player::setIsHit()
{
    if (!isInvincible() && m_state != Entity::State::HIT &&  m_state != Entity::State::DYING) {
        --m_health;
        m_vel   = sf::Vector2f(0, 0);
        m_state = Entity::State::HIT;
        updateHitState();
        Singleton<AudioManager>::getInstance().playSound(Assets::Sfx::SFXE.id);
    }
}

bool Player::checkHasFired() const
{
    return m_hasFired;
}

void Player::setHasFired(bool hasFired)
{
    m_hasFired = hasFired;
    setBulletCount(-1);
}

int Player::getHealth() const
{
    return m_health;
}

void Player::setZombiesKilledCount()
{
    m_zombiesKilledCount += 1;
}

int Player::getZombiesKilledCount()
{
    return m_zombiesKilledCount;
}

void Player::setCheerleadersRescuedCount()
{
    m_cheerleadersRescuedCount += 1;
}

int Player::getCheerleadersRescuedCount()
{
    return m_cheerleadersRescuedCount;
}

void Player::setSoldiersRescuedCount()
{
    m_soldiersRescuedCount += 1;
}

int Player::getSoldiersRescuedCount()
{
    return m_soldiersRescuedCount;
}

void Player::setBulletCount(int bulletCount)
{
    if (!getBulletCount() == 0) {
        m_bulletCount += bulletCount;
    } else {
        m_bulletCount = 0;
    }
}

int Player::getBulletCount()
{
    return m_bulletCount;
}

void Player::increaseBulletCount()
{
    if (getBulletCount() >= 0 && getBulletCount() <= 90) {
        m_bulletCount += 10;
    } else if (getBulletCount() >= 91 && getBulletCount() <= 100) {
        m_bulletCount = 100;
    }
}

void Player::increaseHealth()
{
    if (getHealth() == 0) {
        m_health = 0;
    } else if (getHealth() > 0 && getHealth() < 5) {
        m_health += 1;
    } else if (getHealth() == 5) {
        m_health = 5;
    }
}

void Player::updateMovingState()
{
    switch (m_dir) {
        case Entity::Direction::Up:
            m_animState = m_moving ? Anim::State::MOVE_UP : Anim::State::STAND_FACING_UP;
            break;
        case Entity::Direction::Down:
            m_animState = m_moving ? Anim::State::MOVE_DOWN : Anim::State::STAND_FACING_DOWN;
            break;
        case Entity::Direction::Left:
            m_animState = m_moving ? Anim::State::MOVE_LEFT : Anim::State::STAND_FACING_LEFT;
            break;
        case Entity::Direction::Right:
            m_animState = m_moving ? Anim::State::MOVE_RIGHT : Anim::State::STAND_FACING_RIGHT;
            break;
    }
}

void Player::updateFiringState()
{
    switch (m_dir) {
        case Entity::Direction::Up:
            m_animState = Anim::State::SHOOT_UP;
            //m_state = m_moving ? Entity::State::MOVEUP : Entity::State::STANDFACINGUP;
            break;
        case Entity::Direction::Down:
            m_animState = Anim::State::SHOOT_DOWN;
            //m_state = m_moving ? Entity::State::MOVEDOWN : Entity::State::STANDFACINGDOWN;
            break;
        case Entity::Direction::Left:
            m_animState = Anim::State::SHOOT_LEFT;
            //m_state = m_moving ? Entity::State::MOVELEFT : Entity::State::STANDFACINGLEFT;
            break;
        case Entity::Direction::Right:
            m_animState = Anim::State::SHOOT_RIGHT;
            //m_state = m_moving ? Entity::State::MOVERIGHT : Entity::State::STANDFACINGRIGHT;
            break;
    }
}

void Player::updateHitState()
{
    switch (m_dir) {
        case Entity::Direction::Up:
            m_animState = Anim::State::HIT_FACING_UP;
            break;
        case Entity::Direction::Down:
            m_animState = Anim::State::HIT_FACING_DOWN;
            break;
        case Entity::Direction::Left:
            m_animState = Anim::State::HIT_FACING_LEFT;
            break;
        case Entity::Direction::Right:
            m_animState = Anim::State::HIT_FACING_RIGHT;
            break;
    }
}
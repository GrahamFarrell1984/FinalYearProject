#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <utility>

#include "AnimatedSprite.h"
#include "AnimationStates.h"
#include "BaseEntity.h"
#include "EntityTypes.h"
#include "Keyboard.h"

class Player : public BaseEntity
{
public:
    Player(sf::Vector2f position, sf::Vector2f worldSize, const sf::Texture* texture);

    void processInput(const Keyboard& keyboard);
    void update() override;
    void render(sf::RenderWindow& window) override;

    Rect getBounds() const;
    const sf::Vector2f& getPos() const;
    Entity::Direction getDir() const;
    Entity::State getState() const;

    bool isDead() const;
    bool isInvincible() const;
    void setIsHit();

    bool checkHasFired() const;
    void setHasFired(bool fire);

    int getHealth() const;

    void setZombiesKilledCount();
    int getZombiesKilledCount();

    void setCheerleadersRescuedCount();
    int getCheerleadersRescuedCount();

    void setSoldiersRescuedCount();
    int getSoldiersRescuedCount();

    void setBulletCount(int bulletCount);
    int getBulletCount();
    void increaseBulletCount();
    void increaseHealth();

private:
    static constexpr auto NormalSpeed        = 2;
    static constexpr auto PowerUpSpeed       = 4;
    static constexpr auto MaxHealth          = 5;
    static constexpr auto BulletTickCD       = 25;
    static constexpr auto InvisibleDrawTicks = 5;
    static constexpr auto InvincibleTickCD   = 100;
    static constexpr Point ClsnOffset        = Point{ 5, 20 };

    void updateMovingState();
    void updateFiringState();
    void updateHitState();

    bool m_hasFired;
    bool m_moving;
    bool m_invincible;
    int32_t m_health;
    uint32_t m_speed;
    uint32_t m_bulletTick;
    uint32_t m_invincibleTick;
    Entity::Direction m_dir;
    Entity::State m_state;
    Anim::State m_animState;
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::Vector2f m_worldSize;
    sf::RectangleShape m_rect;
    AnimatedSprite m_animSprite;
    int m_zombiesKilledCount;
    int m_cheerleadersRescuedCount;
    int m_soldiersRescuedCount;
    int m_bulletCount;
};

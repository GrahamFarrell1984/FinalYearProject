#pragma once

#include "BaseEntity.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Civilian.h"
#include "RectUtils.h"

namespace ClsnManager {
    static void pzClsn(std::vector<Player*>players, std::vector<Zombie*>zombies)
    {
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    //zombie->setPosition(sf::Vector2f(rand() % 700 + 1, rand() % 700 + 1));
                    if (!player->isInvincible() && player->getState() != Entity::State::HIT && player->getState() != Entity::State::DYING) {
                        player->setIsHit();
                    }
                }
            }
        }
    }

    static void bzClsn(std::vector<Bullet*> bullets, std::vector<Zombie*> zombies)
    {
        for (auto bullet : bullets) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(bullet->getBounds(), zombie->getBounds())) {
                    bullet->setIsHit();
                }
            }
        }
    }

    static void playerCivilianCollision(std::vector<Player*> players, std::vector<Civilian*> civilians)
    {
        for (auto player : players) {
            for (auto civilian : civilians) {
                if (Utils::isIntersecting(player->getBounds(), civilian->getBounds())) {
                    civilian->m_destroyed = true;
                }
            }
        }
    }
}
#pragma once

#include "BaseEntity.h"
#include "Bullet.h"
#include "Civilian.h"
#include "EntityManager.h"
#include "Player.h"
#include "RectangleHelper.h"
#include "Zombie.h"

namespace ClsnManager {
    static void update(EntityManager& entityManager)
    {
        auto players  = entityManager.getEntityGroup<Player>();
        auto bullets  = entityManager.getEntityGroup<Bullet>();
        auto zombies  = entityManager.getEntityGroup<Zombie>();
        auto civilians = entityManager.getEntityGroup<Civilian>();

        auto player = players.front();

        // Handle All Player Collisions
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    //zombie->setPosition(sf::Vector2f(rand() % 700 + 1, rand() % 700 + 1));
                    if (!player->isInvincible() && player->getState() != Entity::State::HIT && player->getState() != Entity::State::DYING) {
                        player->setIsHit();
                    }
                }
            }
            for (auto civilian : civilians) {
                if (Utils::isIntersecting(player->getBounds(), civilian->getBounds())) {
                    civilian->m_destroyed = true;
                    player->setCiviliansRescuedCount();
                }
            }
        }

        // Handle All Bullet Collisions
        for (auto bullet : bullets) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(bullet->getBounds(), zombie->getBounds())) {
                    bullet->setIsHit();
                    zombie->m_destroyed = true;
                    player->setZombiesKilledCount();
                }
            }
        }
    }

}  // namespace ClsnManager
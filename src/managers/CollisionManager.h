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
        AudioManager& audioManager = Singleton<AudioManager>::getInstance();

        auto players  = entityManager.getEntityGroup<Player>();
        auto bullets  = entityManager.getEntityGroup<Bullet>();
        auto zombies  = entityManager.getEntityGroup<Zombie>();
        auto civilians = entityManager.getEntityGroup<Civilian>();

        auto player = players.front();

        // Handle All Player Collisions
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    player->setIsHit();
                }
            }
            for (auto civilian : civilians) {
                if (Utils::isIntersecting(player->getBounds(), civilian->getBounds())) {
                    civilian->m_destroyed = true;
                    player->setCiviliansRescuedCount();
                    audioManager.playSound(Assets::Sfx::SFXB.id);
                }
            }
        }

        // Handle All Bullet Collisions
        for (auto bullet : bullets) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(bullet->getBounds(), zombie->getBounds())) {
                    bullet->setIsHit();
                    if (zombie->getState() != Entity::State::DYING) {
                        zombie->setIsHit();
                        player->setZombiesKilledCount();
                    }
                }
            }
        }
    }

}  // namespace ClsnManager
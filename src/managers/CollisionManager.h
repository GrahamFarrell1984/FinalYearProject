#pragma once

#include "BaseEntity.h"
#include "Bullet.h"
#include "Cheerleader.h"
#include "EntityManager.h"
#include "Player.h"
#include "RectangleHelper.h"
#include "Soldier.h"
#include "Zombie.h"

namespace ClsnManager {
    static void update(EntityManager& entityManager)
    {
        AudioManager& audioManager = Singleton<AudioManager>::getInstance();

        auto players  = entityManager.getEntityGroup<Player>();
        auto bullets  = entityManager.getEntityGroup<Bullet>();
        auto zombies  = entityManager.getEntityGroup<Zombie>();
        auto cheerleaders = entityManager.getEntityGroup<Cheerleader>();
        auto soldiers = entityManager.getEntityGroup<Soldier>();

        auto player = players.front();

        // Handle All Player Collisions
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    player->setIsHit();
                }
            }
            for (auto cheerleader : cheerleaders) {
                if (Utils::isIntersecting(player->getBounds(), cheerleader->getBounds())) {
                    cheerleader->m_destroyed = true;
                    player->setCheerleadersRescuedCount();
                    // Just testing
                    player->increaseHealth();
                    audioManager.playSound(Assets::Sfx::SFXB.id);
                }
            }
            for (auto soldier : soldiers) {
                if (Utils::isIntersecting(player->getBounds(), soldier->getBounds())) {
                    soldier->m_destroyed = true;
                    player->setSoldiersRescuedCount();
                    // Just testing
                    player->increaseBulletCount();
                    audioManager.playSound(Assets::Sfx::SFXB.id);
                }
            }
        }

        // Handle All Bullet Collisions
        for (auto bullet : bullets) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(bullet->getBounds(), zombie->getBounds())) {
                    bullet->setIsHit();
                    if (zombie->getState() != Entity::State::DYING && zombie->getState() != Entity::State::SPAWNING) {
                        zombie->setIsHit();
                        player->setZombiesKilledCount();
                    }
                }
            }
        }
    }

}  // namespace ClsnManager
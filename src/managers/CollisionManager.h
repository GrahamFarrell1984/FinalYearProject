#pragma once

#include "BaseEntity.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "RectUtils.h"

namespace ClsnManager {
    static void pzClsn(std::vector<Player*>players, std::vector<Zombie*>zombies)
    {
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    zombie->setPosition(sf::Vector2f(rand() % 700 + 1, rand() % 700 + 1));
                }
            }
        }
    }

    static void bzClsn(std::vector<Bullet*> bullets, std::vector<Zombie*> zombies)
    {
        for (auto bullet : bullets) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(bullet->getBounds(), zombie->getBounds())) {
                    bullet->m_destroyed = true;
                    zombie->m_destroyed = true;
                }
            }
        }
    }
}
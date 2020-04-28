#pragma once

#include "BaseEntity.h"
#include "Player.h"
#include "Zombie.h"
#include "RectUtils.h"

namespace ClsnManager {
    static void playerZombieCollision(std::vector<Player*>players, std::vector<Zombie*>zombies)
    {
        for (auto player : players) {
            for (auto zombie : zombies) {
                if (Utils::isIntersecting(player->getBounds(), zombie->getBounds())) {
                    zombie->setPosition(sf::Vector2f(rand() % 700 + 1, rand() % 700 + 1));
                }
            }
        }
    }

    static void bulletEnemyCollision()
    {
    }

    static void playerItemCollision()
    {
    }

}
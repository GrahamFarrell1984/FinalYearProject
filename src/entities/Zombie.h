#pragma once

#include "Entity.h"
class Zombie : public Entity
{
public:
    Zombie();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
};
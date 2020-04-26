#pragma once

#include "Entity.h"
class Mummy : public Entity
{
public:
    Mummy();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
};
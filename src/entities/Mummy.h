#pragma once

#include "Entity.h"
class Mummy : public Entity
{
public:
    Mummy(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
};

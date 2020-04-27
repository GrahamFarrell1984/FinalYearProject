#pragma once

#include "Entity.h"

#include <SFML/System/Vector2.hpp>

class Zombie : public Entity
{
public:
    Zombie(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
};

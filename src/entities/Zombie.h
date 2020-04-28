#pragma once

#include <SFML/System/Vector2.hpp>

#include "BaseEntity.h"

class Zombie : public BaseEntity
{
public:
    Zombie(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
};
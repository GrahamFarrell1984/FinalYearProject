#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

struct Entity
{
    virtual ~Entity() {}
    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
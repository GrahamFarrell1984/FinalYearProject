#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Entity
{
public:
    virtual ~Entity() {}
    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    sf::Sprite m_sprite;
};

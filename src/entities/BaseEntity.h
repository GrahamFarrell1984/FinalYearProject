#pragma once

#include <Types.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class BaseEntity
{
public:
    BaseEntity()
            : m_destroyed{ false }
    {
    }

    virtual ~BaseEntity() {}
    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    bool m_destroyed;
};
#pragma once

#include <Types.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class BaseEntity
{
public:
    BaseEntity()
            : m_visable    { true }
            , m_destroyed  { false }
            , m_localBounds{ 0, 0, 0, 0 }
    {
    }

    virtual ~BaseEntity() {}
    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    bool m_visable;
    bool m_destroyed;
    Rect m_localBounds;
};

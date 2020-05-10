#pragma once

#include <Types.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class BaseEntity
{
public:
    BaseEntity()
            : m_visible    { true }
            , m_destroyed  { false }
            , m_localBounds{ 0, 0, 0, 0 }
    {
    }

    virtual ~BaseEntity() = default;
    virtual void update()                         = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    bool m_visible;
    bool m_destroyed;
    Rect m_localBounds;
};

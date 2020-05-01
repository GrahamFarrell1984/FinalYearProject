#pragma once

#include <SFML/Graphics.hpp>

#include "Types.h"

class Camera
{
public:
    Camera(Point worldSize, Point viewSize);
    sf::View update(sf::Vector2f target);

private:
    float m_zoom;
    sf::View m_view;
    sf::Vector2i m_viewSize;
    sf::Vector2i m_worldSize;
    sf::Vector2f m_test;
};
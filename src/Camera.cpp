#include "Camera.h"

// The boundary check need to be divided by 2 / multipled by 0.5f
// because the viewSize is 1/2 of the window size.

Camera::Camera(Point worldSize, Point viewSize)
        : m_view{sf::FloatRect(0, 0, viewSize.x, viewSize.y)}
        , m_viewSize {viewSize.x, viewSize.y}
        , m_worldSize{worldSize.x, worldSize.y}
{
}

sf::View Camera::update(sf::Vector2f target)
{
    // Boundary Checks
    if (target.x < m_viewSize.x * 0.5f) {
        target.x = m_viewSize.x * 0.5f;
    } else if (target.x > static_cast<float>((m_worldSize.x - (m_viewSize.x * 0.5f)))) {
        target.x = (m_worldSize.x - (m_viewSize.x * 0.5f));
    }

    if (target.y < m_viewSize.y * 0.5f) {
        target.y = m_viewSize.y * 0.5f;
    } else if (target.y > static_cast<float>((m_worldSize.y - (m_viewSize.y * 0.5f)))) {
        target.y = (m_worldSize.y - (m_viewSize.y * 0.5f));
    }

    m_view.setCenter(target);
    return m_view;
}
Rect Camera::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_view.getCenter().x - m_viewSize.x * 0.5f),
                 static_cast<sf::Int32>(m_view.getCenter().y - m_viewSize.y * 0.5f),
                 static_cast<sf::Int32>(m_viewSize.x),
                 static_cast<sf::Int32>(m_viewSize.y)
    };
}

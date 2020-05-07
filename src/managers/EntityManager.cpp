#include "EntityManager.h"
#include "RectangleHelper.h"


// Always update each entity the first time to set positions etc.
void EntityManager::update(Rect camView)
{
    for (const auto& e : m_entities) {
        if (e->m_visable) {
            e->update();
        }

        Point p{ static_cast<int32_t>(e->m_localBounds.x + e->m_localBounds.w * 0.5f),
                 static_cast<int32_t>(e->m_localBounds.y + e->m_localBounds.w * 0.5f)
        };

        Utils::contains(camView, p, Offset) ? e->m_visable = true : e->m_visable = false;
    }
    sortDrawOrder();
}

void EntityManager::render(sf::RenderWindow &window)
{
    for (const auto& e : m_entities) {
        if (e->m_visable) {
            e->render(window);
        }
    }
}
void EntityManager::cleanup()
{
    // Remove from map
    for (auto& kv : m_groupedEntities){
        auto& v = kv.second;
        v.erase(std::remove_if(std::begin(v), std::end(v), [](auto e) {
            return e->m_destroyed;
        }), std::end(v));
    }

    // Remove from list
    m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities), [](const auto& e) {
        return e->m_destroyed;
    }), std::end(m_entities));
}

void EntityManager::sortDrawOrder()
{
    std::sort(m_entities.begin(),m_entities.end(), [](const auto& e1, const auto& e2){
        return (e1->m_localBounds.y + e1->m_localBounds.w) < (e2->m_localBounds.y + e2->m_localBounds.w);
    });
}

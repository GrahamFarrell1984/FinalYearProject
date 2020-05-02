#include "EntityManager.h"

void EntityManager::update()
{
    for (const auto& e : m_entities) {
        e->update();
    }
}

void EntityManager::render(sf::RenderWindow &window)
{
    for (const auto& e : m_entities) {
        e->render(window);
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

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
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>
#include <typeindex>
#include <vector>

#include "Entity.h"
#include <iostream>
class EntityManager
{
public:
    void update();
    void render(sf::RenderWindow& window);

    template <typename T>
    std::vector<T*>& getEntityGroupByType()
    {
        return  m_groupedEntities[std::type_index(typeid(T))];
    }

    template <typename T, typename... Args>
    T& create(Args&&... args)
    {
        // Checks to make sure T is of type Entity.
        static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

        std::unique_ptr<T> entity = std::make_unique<T>(std::forward<Args>(args)...);
        m_groupedEntities[std::type_index(typeid(T))].emplace_back(entity.get());
        m_entities.emplace_back(std::move(entity));
        return *static_cast<T*>(m_entities.back().get());
    }

private:
    std::vector<std::unique_ptr<Entity>> m_entities;
    std::map<std::type_index, std::vector<Entity*>> m_groupedEntities;
};
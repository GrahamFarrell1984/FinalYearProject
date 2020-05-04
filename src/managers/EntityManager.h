#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <typeindex>
#include <vector>

#include "BaseEntity.h"
class EntityManager
{
public:
    void update(Rect view);
    void render(sf::RenderWindow& window);
    void cleanup();

    template <typename T>
    auto getEntityGroup()
    {
        std::vector<T*> entityGroupsWithCorrectType;
        auto& entityGroup = m_groupedEntities[std::type_index(typeid(T))];
        std::transform(std::begin(entityGroup), std::end(entityGroup), std::back_inserter(entityGroupsWithCorrectType),
                       [](BaseEntity* e) {
                           return static_cast<T*>(e);
                       });
        return entityGroupsWithCorrectType;
    }

    template <typename T, typename... Args>
    T& create(Args&&... args)
    {
        // Checks to make sure T is of type Entity.
        static_assert(std::is_base_of<BaseEntity, T>::value, "T must be derived from Entity");

        std::unique_ptr<T> entity = std::make_unique<T>(std::forward<Args>(args)...);
        m_groupedEntities[std::type_index(typeid(T))].emplace_back(entity.get());
        m_entities.emplace_back(std::move(entity));
        return *static_cast<T*>(m_entities.back().get());
    }
private:
    static constexpr auto Offset = 50;

    void sortDrawOrder();


    std::vector<std::unique_ptr<BaseEntity>> m_entities;
    std::map<std::type_index, std::vector<BaseEntity*>> m_groupedEntities;
};

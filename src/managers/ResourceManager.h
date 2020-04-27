#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>

#include "AssetData.h"

template <typename ResourceType>
class ResourceManager
{
public:
    const ResourceType* getResource(sf::Uint8 index) const
    {
        const auto it = m_resources.find(index);
        return it != m_resources.end() ? it->second.get() : nullptr;
    }

    void loadResource(uint8_t index, const std::string& filepath)
    {
        std::unique_ptr<ResourceType> resource = std::make_unique<ResourceType>();
        if (resource->loadFromFile(filepath)) {
            m_resources.try_emplace(index, std::move(resource));
        }
    }

private:
    std::map<uint8_t, std::unique_ptr<ResourceType>> m_resources;
};

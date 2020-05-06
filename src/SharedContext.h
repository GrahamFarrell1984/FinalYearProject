#pragma once

template <typename ResourceType>
class ResourceManager;

struct SharedContext
{
    const ResourceManager<sf::Font>& fontHolder;
    const ResourceManager<sf::Texture>& textureHolder;
};

#pragma once

template <typename ResourceType>
class ResourceManager;

struct SharedContext
{
    const ResourceManager<sf::Font>& fontManager;
    const ResourceManager<sf::Texture>& textureManager;
};
#pragma once

template <typename ResourceType>
class ResourceManager;
class AudioManager;

struct SharedContext
{
    const ResourceManager<sf::Font>& fontHolder;
    const ResourceManager<sf::Texture>& textureHolder;
    AudioManager& audioManager;
};

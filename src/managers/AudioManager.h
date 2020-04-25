#pragma once

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <array>

#include "ResourceManager.h"

class AudioManager
{
public:
    AudioManager(const ResourceManager<sf::SoundBuffer>& sfxBufferManager);

    void playMusic(const Data data, const bool loop = false);
    void stopMusic();
    void pauseMusic();
    void resumeMusic();

    void playSound(sf::Uint8 index);
    void stopAllSounds();

private:
    static constexpr auto MAXSOUNDS = 16;

    const ResourceManager<sf::SoundBuffer>& m_sfxBufferManager;
    std::array<sf::Sound, MAXSOUNDS> m_sfx;
    sf::Music m_music;
};
#pragma once

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <array>

#include "ResourceManager.h"
#include "Singleton.h"

class AudioManager : public Singleton<AudioManager>
{
public:
    void loadResource(uint8_t index, const std::string& filepath);

    void playMusic(Data data, bool loop = false);
    void stopMusic();
    void pauseMusic();
    void resumeMusic();

    void playSound(uint8_t index);
    void stopAllSounds();

private:
    static constexpr auto MAXSOUNDS = 16;

    ResourceManager<sf::SoundBuffer> m_sfxBufferManager;
    std::array<sf::Sound, MAXSOUNDS> m_sfx;
    sf::Music m_music;
};

#include "AudioManager.h"

AudioManager::AudioManager(const ResourceManager<sf::SoundBuffer>& sfxBufferManager)
        : m_sfxBufferManager{ sfxBufferManager }
        , m_sfx             { }
{
}

void AudioManager::playSound(const sf::Uint8 index)
{
    // Check if there is a free sfx slot available and play sfx
    auto sfx = std::find_if(m_sfx.begin(), m_sfx.end(), [](const auto& sfx) {
        return sfx.getStatus() == sf::SoundSource::Status::Stopped;
    });

    if (sfx != m_sfx.end()) {
        sfx->setBuffer(*m_sfxBufferManager.getResource(index));
        sfx->play();
    }
}
void AudioManager::stopAllSounds()
{
    for (auto sfx : m_sfx) {
        sfx.stop();
    }
}
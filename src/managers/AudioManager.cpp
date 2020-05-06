#include "AudioManager.h"


void AudioManager::loadResource(uint8_t index, const std::string& filepath)
{
    m_sfxBufferManager.loadResource(index, filepath);
}


void AudioManager::playMusic(const Data data, const bool loop)
{
    if (m_music.openFromFile(data.filepath)) {
        if (loop) {
            m_music.setLoop(loop);
        }
        m_music.play();
    }
}

void AudioManager::stopMusic()
{
    if (m_music.getStatus() == sf::SoundSource::Status::Playing) {
        m_music.stop();
        m_music.setLoop(false);
    }
}

void AudioManager::pauseMusic()
{
    if (m_music.getStatus() == sf::SoundSource::Status::Playing) {
        m_music.pause();
    }
}

void AudioManager::resumeMusic()
{
    if (m_music.getStatus() == sf::SoundSource::Status::Paused) {
        m_music.play();
    }
}

void AudioManager::playSound(const uint8_t index)
{
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

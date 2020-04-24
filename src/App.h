#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include "AudioManager.h"
#include "Keyboard.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class App
{
public:
    App();

    bool setup();
    void run();

private:
    void checkForUpdates();
    void processEvents();
    void update();
    void render();

    bool m_initialised;
    sf::Time m_timePerFrame;
    sf::RenderWindow m_window;
    ResourceManager<sf::Font> m_fontManager;
    ResourceManager<sf::SoundBuffer> m_sfxBufferManager;
    ResourceManager<sf::Texture> m_textureManager;
    AudioManager m_audioManager;
    SceneManager m_sceneManager;
    Keyboard m_keyboard;
};
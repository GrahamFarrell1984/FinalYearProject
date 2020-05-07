#include "App.h"

#include "Singleton.h"
#include "AudioManager.h"

App::App()
        : m_initialised{ false }
        , m_timePerFrame{ sf::seconds(1.f / 60.f) }
        , m_window{ sf::VideoMode(1024, 768), "Outbreak", sf::Style::Close }
        , m_fontManager{}
        , m_sfxBufferManager{}
        , m_textureManager{}
        , m_sceneManager{ SharedContext{ m_fontManager, m_textureManager } }
        , m_keyboard{}
{
}

bool App::setup()
{
    Singleton<AudioManager>::getInstance().loadResource(Assets::Sfx::SFXA.id, Assets::Sfx::SFXA.filepath);
    Singleton<AudioManager>::getInstance().loadResource(Assets::Sfx::SFXB.id, Assets::Sfx::SFXB.filepath);
    Singleton<AudioManager>::getInstance().loadResource(Assets::Sfx::SFXC.id, Assets::Sfx::SFXC.filepath);
    m_textureManager.loadResource(Assets::Texture::TEXA.id, Assets::Texture::TEXA.filepath);
    m_textureManager.loadResource(Assets::Texture::PLAYER.id, Assets::Texture::PLAYER.filepath);
    m_textureManager.loadResource(Assets::Texture::ZOMBIE.id, Assets::Texture::ZOMBIE.filepath);
    m_textureManager.loadResource(Assets::Texture::MUMMY.id, Assets::Texture::MUMMY.filepath);
    m_textureManager.loadResource(Assets::Texture::LEVEL.id, Assets::Texture::LEVEL.filepath);
    m_fontManager.loadResource(Assets::Font::FONTA.id, Assets::Font::FONTA.filepath);

    // Load assets here, failing to load assets should quit the game.
    m_initialised = true;
    return m_initialised;
}

void App::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window.isOpen()) {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while (timeSinceLastUpdate > m_timePerFrame) {
            timeSinceLastUpdate -= m_timePerFrame;

            checkForUpdates();
            if (m_sceneManager.isSceneStackEmpty()) {
                m_window.close();
            } else {
                processEvents();
                update();
                render();
            }
        }
    }
}

void App::checkForUpdates()
{
    m_sceneManager.checkForUpdates();
}

void App::processEvents()
{
    sf::Event event{};
    m_keyboard.update();
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            m_keyboard.setKey(event.key.code, true);
        } else if (event.type == sf::Event::KeyReleased) {
            m_keyboard.setKey(event.key.code, false);
        }
    }
    m_sceneManager.processInput(m_keyboard);
}

void App::update()
{
    m_sceneManager.update();
}

void App::render()
{
    m_window.clear();
    m_sceneManager.render(m_window);
    m_window.display();
}
#include "App.h"

App::App()
        : m_initialised      { false }
        , m_timePerFrame     { sf::seconds(1.f / 60.f) }
        , m_window           { sf::VideoMode(1024, 768), "SFML", sf::Style::Close }
        , m_fontManager      { }
        , m_sfxBufferManager { }
        , m_textureManager   { }
        , m_audioManager     { m_sfxBufferManager }
        , m_sceneManager     { SharedContext{ m_fontManager, m_textureManager, m_audioManager } }
        , m_keyboard         { }
{
}

bool App::setup()
{
    m_sfxBufferManager.loadResource(Assets::Sfx::Test.id, Assets::Sfx::Test.filepath);
    m_fontManager.loadResource(Assets::Font::EBB.id, Assets::Font::EBB.filepath);
    m_textureManager.loadResource(Assets::Texture::Player.id, Assets::Texture::Player.filepath);

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
            processEvents();
            update();
            render();

            if (m_sceneManager.isSceneStackEmpty()) {
                m_window.close();
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
    m_sceneManager.update(m_timePerFrame);
}

void App::render()
{
    m_window.clear();
    m_sceneManager.render(m_window);
    m_window.display();
}
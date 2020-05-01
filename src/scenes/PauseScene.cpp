#include "PauseScene.h"

#include "TextureData.h"
#include "AudioManager.h"
#include "ResourceManager.h"

#include <iostream>
using namespace std;

PauseScene::PauseScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name, true }
        , m_options   { MENUOPTIONS::RESUME }
        , m_sprite { }
        , m_cursorPos { 320, 559} // Testing cursor position. x was 384
{
}

void PauseScene::processInput(const Keyboard& keyboard)
{
    AudioManager& audioManager = getSharedContext().audioManager;

    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::PRESS)) {
        if (m_options == MENUOPTIONS::RESUME) {
            m_options = MENUOPTIONS::MAINMENU;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
            cout << "Pause Scene Down Key Pressed \n";
        } else if (m_options == MENUOPTIONS::MAINMENU) {
            m_options = MENUOPTIONS::QUIT;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
            cout << "Pause Scene Down Key Pressed \n";
        }
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::PRESS)) {
        if (m_options == MENUOPTIONS::MAINMENU) {
            m_options = MENUOPTIONS::RESUME;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
            cout << "Pause Scene Up Key Pressed \n";
        } else if (m_options == MENUOPTIONS::QUIT) {
            m_options = MENUOPTIONS::MAINMENU;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
            cout << "Pause Scene Up Key Pressed \n";
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        audioManager.playSound(Assets::Sfx::SFXA.id);
        switch (m_options) {
            case MENUOPTIONS::RESUME:
                requestSceneChange(Scene::Action::POP);
                break;
            case MENUOPTIONS::MAINMENU:
                requestSceneChange(Scene::Action::POPUNTIL, Scene::Name::TITLE);
                break;
            case MENUOPTIONS::QUIT:
                requestSceneChange(Scene::Action::POPALL);
                break;
        }
    }
}

void PauseScene::update()
{
}

void PauseScene::render(sf::RenderWindow& window)
{
    // Draw all the transparent skulls
    m_sprite.setTextureRect(sf::IntRect(SKULL2SRCPOS.x, SKULL2SRCPOS.y, SIZE, SIZE));
    for (std::size_t row = 0; row < MAXROW; ++row) {
        for (std::size_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the title text
    m_sprite.setPosition(static_cast<float>(TITLEPOS.x), static_cast<float>(TITLEPOS.y));
    m_sprite.setTextureRect(sf::IntRect(PAUSEDTITLESRCRECT.x, PAUSEDTITLESRCRECT.y, PAUSEDTITLESRCRECT.w, PAUSEDTITLESRCRECT.h));
    window.draw(m_sprite);

    // Draw the menu options text
    m_sprite.setPosition(static_cast<float>(TEXTPOS.x), static_cast<float>(TEXTPOS.y));
    m_sprite.setTextureRect(sf::IntRect(FONT1SRCPOS.x, FONT1SRCPOS.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSORSRCRECT.x, CURSORSRCRECT.y, CURSORSRCRECT.w, CURSORSRCRECT.h));
    window.draw(m_sprite);
}

void PauseScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXB.id));
//    m_sprite.setTextureRect(sf::IntRect(SKULL2SRCPOS.x, SKULL2SRCPOS.y, SIZE, SIZE));
//    m_sprite.setScale(4,3);

    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.pauseMusic();

    // Add Pause sounds
}

void PauseScene::onExit()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.resumeMusic();
}

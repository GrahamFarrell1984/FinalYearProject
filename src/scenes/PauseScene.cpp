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
    m_sprite.setTextureRect(sf::IntRect(BIG_TRANSPARENT_SKULL_SRC_POS.x, BIG_TRANSPARENT_SKULL_SRC_POS.y, SIZE, SIZE));
    for (int32_t row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the paused title text
    m_sprite.setPosition(static_cast<float>(TITLE_POS.x), static_cast<float>(TITLE_POS.y));
    m_sprite.setTextureRect(sf::IntRect(PAUSED_TITLE_SRC_RECT.x, PAUSED_TITLE_SRC_RECT.y, PAUSED_TITLE_SRC_RECT.w, PAUSED_TITLE_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the paused menu text
    m_sprite.setPosition(static_cast<float>(PAUSED_MENU_POS.x), static_cast<float>(PAUSED_MENU_POS.y));
    m_sprite.setTextureRect(sf::IntRect(PAUSED_MENU_SRC_RECT.x, PAUSED_MENU_SRC_RECT.y, SIZE, PAUSED_MENU_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSOR_SRC_RECT.x, CURSOR_SRC_RECT.y, CURSOR_SRC_RECT.w, CURSOR_SRC_RECT.h));
    window.draw(m_sprite);
}

void PauseScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));

    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.pauseMusic();

    // Add Pause sounds
}

void PauseScene::onExit()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.resumeMusic();
}

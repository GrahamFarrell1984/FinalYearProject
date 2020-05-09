#include "GameoverScene.h"

#include "TextureData.h"
#include "AudioManager.h"
#include "ResourceManager.h"

GameoverScene::GameoverScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_options   { MENUOPTIONS::MAINMENU }
        , m_sprite    { }
        , m_cursorPos { 320, 623} // Testing cursor position. x was 384
{
}

void GameoverScene::processInput(const Keyboard& keyboard)
{
    auto& audioManager = Singleton<AudioManager>::getInstance();

    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::PRESS)) {
        if (m_options == MENUOPTIONS::MAINMENU) {
            m_options = MENUOPTIONS::QUIT;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::PRESS)) {
        if (m_options == MENUOPTIONS::QUIT) {
            m_options = MENUOPTIONS::MAINMENU;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        audioManager.playSound(Assets::Sfx::SFXA.id);
        switch (m_options) {
            case MENUOPTIONS::MAINMENU:
                requestSceneChange(Scene::Action::POPALL);
                requestSceneChange(Scene::Action::PUSH, Scene::Name::TITLE);
                break;
            case MENUOPTIONS::QUIT:
                requestSceneChange(Scene::Action::POPALL);
                break;
        }
    }
}

void GameoverScene::update()
{
}

void GameoverScene::render(sf::RenderWindow& window)
{
    // Draw all the greyed out skulls
    m_sprite.setTextureRect(sf::IntRect(BIG_GREY_SKULL_SRC_RECT.x, BIG_GREY_SKULL_SRC_RECT.y, BIG_GREY_SKULL_SRC_RECT.w, BIG_GREY_SKULL_SRC_RECT.h));
    for (int32_t row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the gamer over title text
    m_sprite.setPosition(static_cast<float>(TITLE_POS.x), static_cast<float>(TITLE_POS.y));
    m_sprite.setTextureRect(sf::IntRect(GAME_OVER_TITLE_SRC_RECT.x, GAME_OVER_TITLE_SRC_RECT.y, GAME_OVER_TITLE_SRC_RECT.w, GAME_OVER_TITLE_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the menu options text
    m_sprite.setPosition(static_cast<float>(OPTIONS_AND_GAME_OVER_MENU_POS.x), static_cast<float>(OPTIONS_AND_GAME_OVER_MENU_POS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.x, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.y, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.w, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSOR_SRC_RECT.x, CURSOR_SRC_RECT.y, CURSOR_SRC_RECT.w, CURSOR_SRC_RECT.h));
    window.draw(m_sprite);
}

void GameoverScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::SCENES.id));

    Singleton<AudioManager>::getInstance().playMusic(Assets::Music::MUSICA);
}

void GameoverScene::onExit()
{
    auto& audioManager = Singleton<AudioManager>::getInstance();
    audioManager.stopAllSounds();
    audioManager.stopMusic();
}

#include "AudioManager.h"
#include "ControlsScene.h"
#include "ResourceManager.h"
#include "TextureData.h"

ControlsScene::ControlsScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_options{ MENU_OPTIONS::RETURN }
        , m_sprite{}
        , m_cursorPos{ 320, 623 }
{
}

void ControlsScene::processInput(const Keyboard& keyboard)
{
    AudioManager& audioManager = Singleton<AudioManager>::getInstance();

    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::PRESS)) {
        if (m_options == MENU_OPTIONS::RETURN) {
            m_options = MENU_OPTIONS::QUIT;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::PRESS)) {
        if (m_options == MENU_OPTIONS::QUIT) {
            m_options = MENU_OPTIONS::RETURN;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        audioManager.playSound(Assets::Sfx::SFXA.id);
        switch (m_options) {
            case MENU_OPTIONS::RETURN:
                requestSceneChange(Scene::Action::POP);
                break;
            case MENU_OPTIONS::QUIT:
                requestSceneChange(Scene::Action::POP_ALL);
                break;
        }
    }
}

void ControlsScene::update()
{
}

void ControlsScene::render(sf::RenderWindow& window)
{
    // Draw all the greyed out skulls
    m_sprite.setTextureRect(sf::IntRect(BIG_GREY_SKULL_SRC_RECT.x, BIG_GREY_SKULL_SRC_RECT.y, BIG_GREY_SKULL_SRC_RECT.w, BIG_GREY_SKULL_SRC_RECT.h));
    for (int32_t row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the options title text
    m_sprite.setPosition(static_cast<float>(TITLE_POS.x), static_cast<float>(TITLE_POS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONS_TITLE_SRC_RECT.x, OPTIONS_TITLE_SRC_RECT.y, OPTIONS_TITLE_SRC_RECT.w, OPTIONS_TITLE_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the game controls text
    m_sprite.setPosition(static_cast<float>(GAME_CONTROLS_TEXT_POS.x), static_cast<float>(GAME_CONTROLS_TEXT_POS.y));
    m_sprite.setTextureRect(
            sf::IntRect(GAME_CONTROLS_TEXT_SRC_RECT.x, GAME_CONTROLS_TEXT_SRC_RECT.y, GAME_CONTROLS_TEXT_SRC_RECT.w, GAME_CONTROLS_TEXT_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the options menu text
    m_sprite.setPosition(static_cast<float>(OPTIONS_AND_GAME_OVER_MENU_POS.x), static_cast<float>(OPTIONS_AND_GAME_OVER_MENU_POS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.x, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.y, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.w, OPTIONS_AND_GAME_OVER_MENU_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSOR_SRC_RECT.x, CURSOR_SRC_RECT.y, CURSOR_SRC_RECT.w, CURSOR_SRC_RECT.h));
    window.draw(m_sprite);
}

void ControlsScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::SCENES.id));
}

void ControlsScene::onExit()
{
}

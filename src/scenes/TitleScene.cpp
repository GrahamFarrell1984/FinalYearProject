#include "AudioManager.h"
#include "ResourceManager.h"
#include "TitleScene.h"
#include "TextureData.h"

TitleScene::TitleScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_options   { MENUOPTIONS::START }
        , m_sprite    { }
        , m_cursorPos { 320, 559} // Testing cursor position. x was 384
{
}

void TitleScene::processInput(const Keyboard& keyboard)
{
    AudioManager& audioManager = Singleton<AudioManager>::getInstance();

    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::PRESS)) {
        if (m_options == MENUOPTIONS::START) {
            m_options = MENUOPTIONS::OPTIONS;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        } else if (m_options == MENUOPTIONS::OPTIONS) {
            m_options = MENUOPTIONS::QUIT;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::PRESS)) {
        if (m_options == MENUOPTIONS::OPTIONS) {
            m_options = MENUOPTIONS::START;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        } else if (m_options == MENUOPTIONS::QUIT) {
            m_options = MENUOPTIONS::OPTIONS;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        audioManager.playSound(Assets::Sfx::SFXA.id);
        switch (m_options) {
            case MENUOPTIONS::START:
                requestSceneChange(Scene::Action::PUSH, Scene::Name::GAME);
                break;
            case MENUOPTIONS::OPTIONS:
                requestSceneChange(Scene::Action::PUSH, Scene::Name::OPTIONS);
                break;
            case MENUOPTIONS::QUIT:
                requestSceneChange(Scene::Action::POPALL);
                break;
        }
    }
}

void TitleScene::update()
{
}

void TitleScene::render(sf::RenderWindow& window)
{
    // Draw all the greyed out skulls
    m_sprite.setTextureRect(sf::IntRect(BIG_GREY_SKULL_SRC_RECT.x, BIG_GREY_SKULL_SRC_RECT.y, BIG_GREY_SKULL_SRC_RECT.w, BIG_GREY_SKULL_SRC_RECT.h));
    for (int32_t row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the main title text
    m_sprite.setPosition(static_cast<float>(TITLE_POS.x), static_cast<float>(TITLE_POS.y));
    m_sprite.setTextureRect(sf::IntRect(MAIN_TITLE_SRC_RECT.x, MAIN_TITLE_SRC_RECT.y, MAIN_TITLE_SRC_RECT.w, MAIN_TITLE_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the white skull
    m_sprite.setPosition(static_cast<float>(BIG_WHITE_SKULL_POS.x), static_cast<float>(BIG_WHITE_SKULL_POS.y));
    m_sprite.setTextureRect(sf::IntRect(BIG_WHITE_SKULL_SRC_POS.x, BIG_WHITE_SKULL_SRC_POS.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the title options text
    m_sprite.setPosition(static_cast<float>(MAIN_TITLE_MENU_POS.x), static_cast<float>(MAIN_TITLE_MENU_POS.y));
    m_sprite.setTextureRect(sf::IntRect(MAIN_TITLE_MENU_SRC_RECT.x, MAIN_TITLE_MENU_SRC_RECT.y, MAIN_TITLE_MENU_SRC_RECT.w, MAIN_TITLE_MENU_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSOR_SRC_RECT.x, CURSOR_SRC_RECT.y, CURSOR_SRC_RECT.w, CURSOR_SRC_RECT.h));
    window.draw(m_sprite);
}

void TitleScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::SCENES.id));

    Singleton<AudioManager>::getInstance().playMusic(Assets::Music::MUSICA);
}

void TitleScene::onExit()
{
    AudioManager& audioManager = Singleton<AudioManager>::getInstance();
    audioManager.stopMusic();
    audioManager.stopAllSounds();
}

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
    AudioManager& audioManager = getSharedContext().audioManager;

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
    m_sprite.setTextureRect(sf::IntRect(SKULL0SRCPOS.x, SKULL0SRCPOS.y, SIZE, SIZE));
    for (std::size_t row = 0; row < MAXROW; ++row) {
        for (std::size_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }

    // Draw the title text
    m_sprite.setPosition(static_cast<float>(TITLEPOS.x), static_cast<float>(TITLEPOS.y));
    m_sprite.setTextureRect(sf::IntRect(GAMEOVERTITLESRCRECT.x, GAMEOVERTITLESRCRECT.y, GAMEOVERTITLESRCRECT.w, GAMEOVERTITLESRCRECT.h));
    window.draw(m_sprite);

    // Draw the menu options text
    m_sprite.setPosition(static_cast<float>(TEXTPOS.x), static_cast<float>(TEXTPOS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONSRCRECT.x, OPTIONSRCRECT.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSORSRCRECT.x, CURSORSRCRECT.y, CURSORSRCRECT.w, CURSORSRCRECT.h));
    window.draw(m_sprite);
}

void GameoverScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXB.id));

    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.playMusic(Assets::Music::MUSICA);
}

void GameoverScene::onExit()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();
}
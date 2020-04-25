#include "TitleScene.h"

#include "TextureData.h"
#include "AudioManager.h"
#include "ResourceManager.h"

TitleScene::TitleScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_options   { MENUOPTIONS::START }
        , m_sprite    { }
        , m_cursorPos { 320, 559} // Testing cursor position. x was 384
{
}

void TitleScene::processInput(const Keyboard& keyboard)
{
    AudioManager& audioManager = getSharedContext().audioManager;

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
                requestSceneChange(Scene::Action::PUSH, Scene::Name::TEST);
                break;
            case MENUOPTIONS::QUIT:
                requestSceneChange(Scene::Action::POPALL);
                break;
        }
    }
}

void TitleScene::update(const sf::Time deltaTime)
{
}

void TitleScene::render(sf::RenderWindow& window)
{
    // Draw all the greyed out skulls
    m_sprite.setTextureRect(sf::IntRect(SKULL0SRCPOS.x, SKULL0SRCPOS.y, SIZE, SIZE));
    for (sf::Int32 row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }
    // Draw the white skull
    m_sprite.setPosition(static_cast<float>(WSKULLPOS.x), static_cast<float>(WSKULLPOS.y));
    m_sprite.setTextureRect(sf::IntRect(SKULL1SRCPOS.x, SKULL1SRCPOS.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the text
    m_sprite.setPosition(static_cast<float>(TEXTPOS.x), static_cast<float>(TEXTPOS.y));
    m_sprite.setTextureRect(sf::IntRect(FONTSRCPOS.x, FONTSRCPOS.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the title text
    m_sprite.setPosition(static_cast<float>(TITLEPOS.x), static_cast<float>(TITLEPOS.y));
    m_sprite.setTextureRect(sf::IntRect(TITLESRCRECT.x, TITLESRCRECT.y, TITLESRCRECT.w, TITLESRCRECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSORSRCRECT.x, CURSORSRCRECT.y, CURSORSRCRECT.w, CURSORSRCRECT.h));
    window.draw(m_sprite);
}

void TitleScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));
//    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXB.id));

    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.playMusic(Assets::Music::MUSICA);
}

void TitleScene::onExit()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();
}

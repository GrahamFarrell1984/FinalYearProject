#include "OptionsScene.h"

#include "TextureData.h"
#include "AudioManager.h"
#include "ResourceManager.h"

OptionsScene::OptionsScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_text   { }
        , m_options   { MENUOPTIONS::RETURN }
        , m_sprite { }
        , m_cursorPos { 320, 623} // Testing cursor position. x was 384
{
}

void OptionsScene::processInput(const Keyboard& keyboard)
{
    AudioManager& audioManager = getSharedContext().audioManager;

    if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::PRESS)) {
        if (m_options == MENUOPTIONS::RETURN) {
            m_options = MENUOPTIONS::QUIT;
            m_cursorPos.y += CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::PRESS)) {
        if (m_options == MENUOPTIONS::QUIT) {
            m_options = MENUOPTIONS::RETURN;
            m_cursorPos.y -= CURSOROFFSET;
            audioManager.playSound(Assets::Sfx::SFXA.id);
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        audioManager.playSound(Assets::Sfx::SFXA.id);
        switch (m_options) {
            case MENUOPTIONS::RETURN:
                requestSceneChange(Scene::Action::POP);
                break;
            case MENUOPTIONS::QUIT:
                requestSceneChange(Scene::Action::POPALL);
                break;
        }
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::X, State::PRESS)) {
        requestSceneChange(Scene::Action::POP);
    }
}

void OptionsScene::update(const sf::Time deltaTime)
{
}

void OptionsScene::render(sf::RenderWindow& window)
{
    // Draw all the greyed out skulls
    m_sprite.setTextureRect(sf::IntRect(SKULL0SRCPOS.x, SKULL0SRCPOS.y, SIZE, SIZE));
    for (sf::Int32 row = 0; row < MAXROW; ++row) {
        for (int32_t col = 0; col < MAXCOL; ++col) {
            m_sprite.setPosition(static_cast<float>(OFFSETX + (SIZE * col)), static_cast<float>(SIZE * row));
            window.draw(m_sprite);
        }
    }
//    // Draw the white skull
//    m_sprite.setPosition(static_cast<float>(WSKULLPOS.x), static_cast<float>(WSKULLPOS.y));
//    m_sprite.setTextureRect(sf::IntRect(SKULL1SRCPOS.x, SKULL1SRCPOS.y, SIZE, SIZE));
//    window.draw(m_sprite);

    // Draw the text
    m_sprite.setPosition(static_cast<float>(TEXTPOS.x), static_cast<float>(TEXTPOS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONSRCRECT.x, OPTIONSRCRECT.y, SIZE, SIZE));
    window.draw(m_sprite);

    // Draw the title text
    m_sprite.setPosition(static_cast<float>(TITLEPOS.x), static_cast<float>(TITLEPOS.y));
    m_sprite.setTextureRect(sf::IntRect(OPTIONSTITLESRCRECT.x, OPTIONSTITLESRCRECT.y, OPTIONSTITLESRCRECT.w, OPTIONSTITLESRCRECT.h));
    window.draw(m_sprite);

    // Draw the controls text
    m_sprite.setPosition(static_cast<float>(CONTROLTEXTPOS.x), static_cast<float>(CONTROLTEXTPOS.y));
    m_sprite.setTextureRect(sf::IntRect(CONTROLSTEXTSRCRECT.x, CONTROLSTEXTSRCRECT.y, CONTROLSTEXTSRCRECT.w, CONTROLSTEXTSRCRECT.h));
    window.draw(m_sprite);

    // Draw the cursor
    m_sprite.setPosition(static_cast<float>(m_cursorPos.x), static_cast<float>(m_cursorPos.y));
    m_sprite.setTextureRect(sf::IntRect(CURSORSRCRECT.x, CURSORSRCRECT.y, CURSORSRCRECT.w, CURSORSRCRECT.h));
    window.draw(m_sprite);
}

void OptionsScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));
//    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXB.id));

//    AudioManager& audioManager = getSharedContext().audioManager;
//    audioManager.playMusic(Assets::Music::MUSICA);
}

void OptionsScene::onExit()
{
}
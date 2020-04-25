#include "PauseScene.h"

#include "TextureData.h"
#include "AudioManager.h"
#include "ResourceManager.h"

PauseScene::PauseScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name, true }
        , m_sprite { }
{
}

void PauseScene::processInput(const Keyboard& keyboard)
{
    // NOTE : Test - please remove
    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        requestSceneChange(Scene::Action::POPALL);
    }
}

void PauseScene::update(const sf::Time deltaTime)
{
}

void PauseScene::render(sf::RenderWindow& window)
{
    // NOTE : Test - please remove
    window.draw(m_sprite);
}

void PauseScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));
    m_sprite.setTextureRect(sf::IntRect(SKULL2SRCPOS.x, SKULL2SRCPOS.y, SIZE, SIZE));
    m_sprite.setScale(4,3);

    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.pauseMusic();

    // Add Pause sounds
}

void PauseScene::onExit()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.resumeMusic();
}
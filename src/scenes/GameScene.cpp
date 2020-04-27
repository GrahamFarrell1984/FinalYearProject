#include "GameScene.h"

#include "AudioManager.h"
#include "Mummy.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Zombie.h"

GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
{
}

void GameScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::P, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::PAUSE);
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::D, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::GAMEOVER);
    }

    m_player.processInput(keyboard);
}

void GameScene::update(const sf::Time deltaTime)
{
    m_player.update();
    m_entityManager.update();
}

void GameScene::render(sf::RenderWindow& window)
{
    m_player.render(window);
    m_entityManager.render(window);
}

void GameScene::onEnter()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();

    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;

    m_player.setup(sf::Vector2f(0, 0),textureHolder.getResource(Assets::Texture::PLAYER.id));
    m_entityManager.create<Mummy>(sf::Vector2f(50.f, 50.f), textureHolder.getResource(Assets::Texture::MUMMY.id));
    m_entityManager.create<Zombie>(sf::Vector2f(150.f, 150.f), textureHolder.getResource(Assets::Texture::ZOMBIE.id));
}

void GameScene::onExit()
{
}
#include "GameScene.h"

#include "Mummy.h"
#include "Player.h"
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
}

void GameScene::update(const sf::Time deltaTime)
{
    m_entityManager.update();
}

void GameScene::render(sf::RenderWindow& window)
{
    m_entityManager.render(window);
}

void GameScene::onEnter()
{
    m_entityManager.create<Mummy>();
    m_entityManager.create<Zombie>();
}

void GameScene::onExit()
{
}
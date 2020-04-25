#include "GameScene.h"

GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
{
}

void GameScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::PAUSE);
    }
}

void GameScene::update(const sf::Time deltaTime)
{
}

void GameScene::render(sf::RenderWindow& window)
{
}

void GameScene::onEnter()
{
}

void GameScene::onExit()
{
}
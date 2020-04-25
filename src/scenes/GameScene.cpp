#include "GameScene.h"

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

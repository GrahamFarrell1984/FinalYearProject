#include "TestScene.h"

#include "AudioManager.h"
#include "ResourceManager.h"

TestScene::TestScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_text   { }
        , m_sprite { }
{
}

void TestScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::B, State::PRESS)) {
        requestSceneChange(Scene::Action::POP);
    }
}

void TestScene::update(const sf::Time deltaTime)
{
}

void TestScene::render(sf::RenderWindow& window)
{
}

void TestScene::onEnter()
{
}

void TestScene::onExit()
{
}

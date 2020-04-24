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
    if (keyboard.checkKeyAndState(sf::Keyboard::Left, State::HOLD)) {
        m_sprite.move(-1, 0);
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Right, State::HOLD)) {
        m_sprite.move(1, 0);
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Up, State::HOLD)) {
        m_sprite.move(0, -1);
    } else if (keyboard.checkKeyAndState(sf::Keyboard::Down, State::HOLD)) {
        m_sprite.move(0, 1);
    }

    if (keyboard.checkKeyAndState(sf::Keyboard::Enter, State::PRESS)) {
        AudioManager& audioManager = getSharedContext().audioManager;
        audioManager.playSound(Assets::Sfx::Test.index);
    }
}

void TestScene::update(const sf::Time deltaTime)
{
}

void TestScene::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    window.draw(m_text);
}

void TestScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::Player.index));

    const ResourceManager<sf::Font>& fontHolder = getSharedContext().fontHolder;
    m_text.setFont(*fontHolder.getResource(Assets::Font::EBB.index));
    m_text.setString("Testing");
    m_text.setPosition(sf::Vector2f(100, 100));
}

void TestScene::onExit()
{
}
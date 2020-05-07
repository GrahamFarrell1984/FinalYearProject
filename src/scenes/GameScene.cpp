#include "GameScene.h"

#include "AudioManager.h"
#include "Bullet.h"
#include "Civilian.h"
#include "CollisionManager.h"
#include "Mummy.h"
#include "Player.h"
#include "ResourceManager.h"
#include "TextureData.h"
#include "Zombie.h"

GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_camera { WORLDSIZE, VIEWSIZE }
        , m_level  { getSharedContext().textureHolder.getResource(Assets::Texture::LEVEL.id) }
        , m_sprite { }
{
}

void GameScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::P, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::PAUSE);
    }
    m_player->processInput(keyboard);
}

void GameScene::update()
{
    if (m_player->checkHasFired()) {
        m_entityManager.create<Bullet>(m_player->getPos(), m_player->getDir(), getSharedContext().textureHolder.getResource(Assets::Texture::PLAYER.id));
        m_player->setHasFired(false);
    }

    ClsnManager::update(m_entityManager);
    m_entityManager.update(m_camera.getBounds());
    m_entityManager.cleanup();

    if (m_player->isDead()) {
        requestSceneChange(Scene::Action::POPANDADD, Scene::Name::GAMEOVER);
    }
}

void GameScene::render(sf::RenderWindow& window)
{
    window.setView(m_camera.update(m_player->getPos()));
    m_level.render(window, m_camera.getBounds());
    m_entityManager.render(window);
    window.setView(window.getDefaultView());

    m_sprite.setPosition(10, 10);
    m_sprite.setTextureRect(sf::IntRect(BIG_HEART_WHITE_BORDER_SRC_RECT.x, BIG_HEART_WHITE_BORDER_SRC_RECT.y, BIG_HEART_WHITE_BORDER_SRC_RECT.w, BIG_HEART_WHITE_BORDER_SRC_RECT.h));

    for (int i = 0; i < m_player->getHealth(); i++) {
        m_sprite.setPosition(40 * i + 10, 18);
        window.draw(m_sprite);
    }

    // Draw the zombie head counter
    m_sprite.setPosition(static_cast<float>((VIEWSIZE.x / 2) - (ZOMBIE_HEAD_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(ZOMBIE_HEAD_SRC_RECT.x, ZOMBIE_HEAD_SRC_RECT.y, ZOMBIE_HEAD_SRC_RECT.w, ZOMBIE_HEAD_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the civilian head counter
    m_sprite.setPosition(static_cast<float>(((VIEWSIZE.x / 4) * 3) - (CIVILIAN_HEAD_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(CIVILIAN_HEAD_SRC_RECT.x, CIVILIAN_HEAD_SRC_RECT.y, CIVILIAN_HEAD_SRC_RECT.w, CIVILIAN_HEAD_SRC_RECT.h));
    window.draw(m_sprite);

    m_zombiesKilledCountText.setString(std::to_string(m_player->getZombiesKilledCount()));
    window.draw(m_zombiesKilledCountText);

    m_civiliansRescuedCountText.setString(std::to_string(m_player->getCiviliansRescuedCount()));
    window.draw(m_civiliansRescuedCountText);

}

void GameScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    const ResourceManager<sf::Font>& fontHolder = getSharedContext().fontHolder;

    AudioManager& audioManager = Singleton<AudioManager>::getInstance();
    audioManager.stopMusic();
    audioManager.stopAllSounds();

    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));

    m_player = m_entityManager.create<Player>(sf::Vector2f(100, 100), textureHolder.getResource(Assets::Texture::PLAYER.id));

    for (int i = 0; i < 100; ++i) {
        m_entityManager.create<Zombie>(sf::Vector2f(rand() % 75 * (i + 0.3), rand() % 75 * (i + 0.5)), m_player->getPos(), textureHolder.getResource(Assets::Texture::PLAYER.id));
    }

    for (int i = 0; i < 25; ++i) {
        m_entityManager.create<Civilian>(sf::Vector2f(rand() % 25 * (i + 0.1), rand() % 250 * (i + 0.1)), textureHolder.getResource(Assets::Texture::PLAYER.id));
    }

    m_zombiesKilledCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_zombiesKilledCountText.setCharacterSize(24);
    m_zombiesKilledCountText.setColor(sf::Color::White);
    m_zombiesKilledCountText.setPosition(static_cast<float>((VIEWSIZE.x / 2) - (ZOMBIE_HEAD_SRC_RECT.w / 2) + 60), static_cast<float>(20));

    m_civiliansRescuedCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_civiliansRescuedCountText.setCharacterSize(24);
    m_civiliansRescuedCountText.setColor(sf::Color::White);
    m_civiliansRescuedCountText.setPosition(static_cast<float>(((VIEWSIZE.x / 4) * 3) - (CIVILIAN_HEAD_SRC_RECT.w / 2) + 60), static_cast<float>(20));

}

void GameScene::onExit()
{
}
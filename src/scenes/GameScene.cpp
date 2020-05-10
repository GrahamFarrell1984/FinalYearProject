#include "AudioManager.h"
#include "Bullet.h"
#include "Cheerleader.h"
#include "CollisionManager.h"
#include "GameScene.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Soldier.h"
#include "TextureData.h"
#include "Zombie.h"

GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_camera { WORLD_SIZE, VIEW_SIZE }
        , m_level  { getSharedContext().textureHolder.getResource(Assets::Texture::LEVEL.id), VIEW_SIZE }
        , m_sprite { }
        , m_bulletCountText { }
        , m_zombiesKilledCountText { }
        , m_cheerleadersRescuedCountText { }
        , m_soldiersRescuedCountText { }
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
        if (!m_player->getBulletCount() == 0) {
            m_entityManager.create<Bullet>(m_player->getPos(), m_player->getDir(), getSharedContext().textureHolder.getResource(Assets::Texture::ENTITIES.id));
            Singleton<AudioManager>::getInstance().playSound(Assets::Sfx::SFXD.id);
            m_player->setHasFired(false);
        }
    }

    CollisionManager::update(m_entityManager);
    m_entityManager.update(m_camera.getBounds());
    m_entityManager.cleanup();

    if (m_player->isDead()) {
        requestSceneChange(Scene::Action::POP_AND_ADD, Scene::Name::GAME_OVER);
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

    // Draw the hearts for the players health
    for (int i = 0; i < m_player->getHealth(); i++) {
        m_sprite.setPosition(40 * i + 10, 18);
        window.draw(m_sprite);
    }

    // Draw the bullet counter
    m_sprite.setPosition(static_cast<float>((VIEW_SIZE.x / 2) - (MEDIUM_GUN_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(MEDIUM_GUN_SRC_RECT.x, MEDIUM_GUN_SRC_RECT.y, MEDIUM_GUN_SRC_RECT.w, MEDIUM_GUN_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the zombie head counter
    m_sprite.setPosition(static_cast<float>(((VIEW_SIZE.x / 4) * 3) - (ZOMBIE_HEAD_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(ZOMBIE_HEAD_SRC_RECT.x, ZOMBIE_HEAD_SRC_RECT.y, ZOMBIE_HEAD_SRC_RECT.w, ZOMBIE_HEAD_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the cheerleader head counter
    m_sprite.setPosition(static_cast<float>(VIEW_SIZE.x - (CHEERLEADER_HEAD_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(CHEERLEADER_HEAD_SRC_RECT.x, CHEERLEADER_HEAD_SRC_RECT.y, CHEERLEADER_HEAD_SRC_RECT.w, CHEERLEADER_HEAD_SRC_RECT.h));
    window.draw(m_sprite);

    // Draw the soldier head counter
    m_sprite.setPosition(static_cast<float>((VIEW_SIZE.x + (VIEW_SIZE.x / 4)) - (SOLDIER_HEAD_SRC_RECT.w / 2)), static_cast<float>(10));
    m_sprite.setTextureRect(sf::IntRect(SOLDIER_HEAD_SRC_RECT.x, SOLDIER_HEAD_SRC_RECT.y, SOLDIER_HEAD_SRC_RECT.w, SOLDIER_HEAD_SRC_RECT.h));
    window.draw(m_sprite);

    // Set and draw the bullet counter value
    m_bulletCountText.setString(std::to_string(m_player->getBulletCount()));
    window.draw(m_bulletCountText);

    // Set and draw the zombie head counter value
    m_zombiesKilledCountText.setString(std::to_string(m_player->getZombiesKilledCount()));
    window.draw(m_zombiesKilledCountText);

    // Set and draw the cheerleader head counter value
    m_cheerleadersRescuedCountText.setString(std::to_string(m_player->getCheerleadersRescuedCount()));
    window.draw(m_cheerleadersRescuedCountText);

    // Set and draw the soldier head counter value
    m_soldiersRescuedCountText.setString(std::to_string(m_player->getSoldiersRescuedCount()));
    window.draw(m_soldiersRescuedCountText);

}

void GameScene::onEnter()
{
    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    const ResourceManager<sf::Font>& fontHolder = getSharedContext().fontHolder;

    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::SCENES.id));

    m_player = m_entityManager.create<Player>(sf::Vector2f(100, 100), sf::Vector2f(WORLD_SIZE.x, WORLD_SIZE.y), textureHolder.getResource(Assets::Texture::ENTITIES.id));

    for (int i = 0; i < 100; ++i) {
        m_entityManager.create<Zombie>(sf::Vector2f(rand() % (WORLD_SIZE.x - 50), rand() % (WORLD_SIZE.y - 125)), m_player->getPos(), textureHolder.getResource(Assets::Texture::ENTITIES.id));
    }

    for (int i = 0; i < 100; ++i) {
        m_entityManager.create<Cheerleader>(sf::Vector2f(rand() % (WORLD_SIZE.x - 50), rand() % (WORLD_SIZE.y - 125)), textureHolder.getResource(Assets::Texture::ENTITIES.id));
    }

    for (int i = 0; i < 100; ++i) {
        m_entityManager.create<Soldier>(sf::Vector2f(rand() % (WORLD_SIZE.x - 50), rand() % (WORLD_SIZE.y - 125)), textureHolder.getResource(Assets::Texture::ENTITIES.id));
    }

    m_bulletCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_bulletCountText.setCharacterSize(24);
    m_bulletCountText.setColor(sf::Color::White);
    m_bulletCountText.setPosition(static_cast<float>((VIEW_SIZE.x / 2) - (MEDIUM_GUN_SRC_RECT.w / 2) + 60), static_cast<float>(20));

    m_zombiesKilledCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_zombiesKilledCountText.setCharacterSize(24);
    m_zombiesKilledCountText.setColor(sf::Color::White);
    m_zombiesKilledCountText.setPosition(static_cast<float>(((VIEW_SIZE.x / 4) * 3) - (ZOMBIE_HEAD_SRC_RECT.w / 2) + 60), static_cast<float>(20));

    m_cheerleadersRescuedCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_cheerleadersRescuedCountText.setCharacterSize(24);
    m_cheerleadersRescuedCountText.setColor(sf::Color::White);
    m_cheerleadersRescuedCountText.setPosition(static_cast<float>(VIEW_SIZE.x - (CHEERLEADER_HEAD_SRC_RECT.w / 2) + 60), static_cast<float>(20));

    m_soldiersRescuedCountText.setFont(*fontHolder.getResource(Assets::Font::FONTA.id));
    m_soldiersRescuedCountText.setCharacterSize(24);
    m_soldiersRescuedCountText.setColor(sf::Color::White);
    m_soldiersRescuedCountText.setPosition(static_cast<float>((VIEW_SIZE.x + (VIEW_SIZE.x / 4)) - (SOLDIER_HEAD_SRC_RECT.w / 2) + 60), static_cast<float>(20));
}

void GameScene::onExit()
{
}
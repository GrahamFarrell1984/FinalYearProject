#include "GameScene.h"

#include "AudioManager.h"
#include "CollisionManager.h"
#include "Mummy.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Zombie.h"
#include "Bullet.h"


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

//    if (keyboard.checkKeyAndState(sf::Keyboard::Space, State::PRESS)) {
//        m_entityManager.create<Bullet>(sf::Vector2f(50, 50), sf::Vector2f(5, 0));
//    }
//
    m_entityManager.getEntityGroup<Player>().front()->processInput(keyboard);
}

void GameScene::update()
{
    // Firing bullet
    Player* player = m_entityManager.getEntityGroup<Player>().front();
    if (player->checkHasFired()) {
        m_entityManager.create<Bullet>(player->getPos(), player->getVel());
        player->setHasFired(false);
    }

    m_entityManager.update();

    ClsnManager::pzClsn(m_entityManager.getEntityGroup<Player>(), m_entityManager.getEntityGroup<Zombie>());
    ClsnManager::bzClsn(m_entityManager.getEntityGroup<Bullet>(), m_entityManager.getEntityGroup<Zombie>());

    // Clean up any entities that are destroyed.
    m_entityManager.cleanup();
}

void GameScene::render(sf::RenderWindow& window)
{
    m_entityManager.render(window);
}

void GameScene::onEnter()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();

    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;

    m_entityManager.create<Player>(sf::Vector2f(0, 0), textureHolder.getResource(Assets::Texture::PLAYER.id));
    m_entityManager.create<Mummy>(sf::Vector2f(50.f, 50.f), textureHolder.getResource(Assets::Texture::MUMMY.id));
    m_entityManager.create<Zombie>(sf::Vector2f(150.f, 150.f), textureHolder.getResource(Assets::Texture::ZOMBIE.id));
}

void GameScene::onExit()
{
}
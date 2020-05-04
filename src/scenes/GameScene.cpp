#include "GameScene.h"

#include "AudioManager.h"
#include "CollisionManager.h"
#include "Mummy.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Civilian.h"


GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_camera { WORLDSIZE, VIEWSIZE }
{
}

void GameScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::P, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::PAUSE);
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
        m_entityManager.create<Bullet>(player->getPos(), player->getDir(), getSharedContext().textureHolder.getResource(Assets::Texture::PLAYER.id));
        player->setHasFired(false);
    }

    ClsnManager::pzClsn(m_entityManager.getEntityGroup<Player>(), m_entityManager.getEntityGroup<Zombie>());
    ClsnManager::bzClsn(m_entityManager.getEntityGroup<Bullet>(), m_entityManager.getEntityGroup<Zombie>());
    ClsnManager::playerCivilianCollision(m_entityManager.getEntityGroup<Player>(), m_entityManager.getEntityGroup<Civilian>());


    m_entityManager.update();

    // Clean up any entities that are destroyed.
    m_entityManager.cleanup();

    if (player->isDead()) {
        requestSceneChange(Scene::Action::POPANDADD, Scene::Name::GAMEOVER);
    }

}

void GameScene::render(sf::RenderWindow& window)
{
    window.setView(m_camera.update(m_entityManager.getEntityGroup<Player>().front()->getPos()));
    m_entityManager.render(window);
    window.setView(window.getDefaultView());
}

void GameScene::onEnter()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();

    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;

    m_entityManager.create<Player>(sf::Vector2f(100, 100), textureHolder.getResource(Assets::Texture::PLAYER.id));
    m_entityManager.create<Mummy>(sf::Vector2f(50.f, 50.f), textureHolder.getResource(Assets::Texture::MUMMY.id));
    m_entityManager.create<Zombie>(sf::Vector2f(150.f, 150.f), textureHolder.getResource(Assets::Texture::ZOMBIE.id));
    m_entityManager.create<Civilian>(sf::Vector2f(250, 250), textureHolder.getResource(Assets::Texture::PLAYER.id));
//    for (int i = 0; i < 10; ++i) {
//        m_entityManager.create<Civilian>(sf::Vector2f(rand() % 250 + 1, rand() % 250 + 1), textureHolder.getResource(Assets::Texture::CIVILIAN.id));
//    }
}

void GameScene::onExit()
{
}
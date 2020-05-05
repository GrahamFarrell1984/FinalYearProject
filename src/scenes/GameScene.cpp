#include "GameScene.h"

#include "AudioManager.h"
#include "CollisionManager.h"
#include "Mummy.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Civilian.h"
#include "TextureData.h"

GameScene::GameScene(SceneManager& sceneManager, const Scene::Name name)
        : BaseScene{ sceneManager, name }
        , m_camera { WORLDSIZE, VIEWSIZE }
        , m_sprite { }
        , m_heartSpritePos { 10, 10 } // Testing player health heart sprite position. Doesn't look good at x,y position of 0,0.
{
}

void GameScene::processInput(const Keyboard& keyboard)
{
    if (keyboard.checkKeyAndState(sf::Keyboard::P, State::PRESS)) {
        requestSceneChange(Scene::Action::PUSH, Scene::Name::PAUSE);
    }
    m_entityManager.getEntityGroup<Player>().front()->processInput(keyboard);
}

void GameScene::update()
{
    if (m_player->checkHasFired()) {
        m_entityManager.create<Bullet>(m_player->getPos(), m_player->getDir(), getSharedContext().textureHolder.getResource(Assets::Texture::PLAYER.id));
        m_player->setHasFired(false);
    }

    ClsnManager::pzClsn(m_entityManager.getEntityGroup<Player>(), m_entityManager.getEntityGroup<Zombie>());
    ClsnManager::bzClsn(m_entityManager.getEntityGroup<Bullet>(), m_entityManager.getEntityGroup<Zombie>());
    ClsnManager::playerCivilianCollision(m_entityManager.getEntityGroup<Player>(), m_entityManager.getEntityGroup<Civilian>());

    m_entityManager.update(m_camera.getBounds());
    m_entityManager.cleanup();

    if (m_player->isDead()) {
        requestSceneChange(Scene::Action::POPANDADD, Scene::Name::GAMEOVER);
    }

}

void GameScene::render(sf::RenderWindow& window)
{
    window.setView(m_camera.update(m_entityManager.getEntityGroup<Player>().front()->getPos()));
    m_entityManager.render(window);
    window.setView(window.getDefaultView());

    m_sprite.setPosition(static_cast<float>(m_heartSpritePos.x), static_cast<float>(m_heartSpritePos.y));

    switch (m_player->getHealth()) {
        case 5:
            m_sprite.setTextureRect(sf::IntRect(FIVE_HEARTS_SRC_RECT.x, FIVE_HEARTS_SRC_RECT.y, FIVE_HEARTS_SRC_RECT.w, FIVE_HEARTS_SRC_RECT.h));
            window.draw(m_sprite);
            break;
        case 4:
            m_sprite.setTextureRect(sf::IntRect(FOUR_HEARTS_SRC_RECT.x, FOUR_HEARTS_SRC_RECT.y, FOUR_HEARTS_SRC_RECT.w, FOUR_HEARTS_SRC_RECT.h));
            window.draw(m_sprite);
            break;
        case 3:
            m_sprite.setTextureRect(sf::IntRect(THREE_HEARTS_SRC_RECT.x, THREE_HEARTS_SRC_RECT.y, THREE_HEARTS_SRC_RECT.w, THREE_HEARTS_SRC_RECT.h));
            window.draw(m_sprite);
            break;
        case 2:
            m_sprite.setTextureRect(sf::IntRect(TWO_HEARTS_SRC_RECT.x, TWO_HEARTS_SRC_RECT.y, TWO_HEARTS_SRC_RECT.w, TWO_HEARTS_SRC_RECT.h));
            window.draw(m_sprite);
            break;
        case 1:
            m_sprite.setTextureRect(sf::IntRect(ONE_HEART_SRC_RECT.x, ONE_HEART_SRC_RECT.y, ONE_HEART_SRC_RECT.w, ONE_HEART_SRC_RECT.h));
            window.draw(m_sprite);
            break;
    }
}

void GameScene::onEnter()
{
    AudioManager& audioManager = getSharedContext().audioManager;
    audioManager.stopMusic();
    audioManager.stopAllSounds();

    const ResourceManager<sf::Texture>& textureHolder = getSharedContext().textureHolder;
    m_sprite.setTexture(*textureHolder.getResource(Assets::Texture::TEXA.id));

    m_player = m_entityManager.create<Player>(sf::Vector2f(100, 100), textureHolder.getResource(Assets::Texture::PLAYER.id));
//    m_entityManager.create<Mummy>(sf::Vector2f(50.f, 50.f), textureHolder.getResource(Assets::Texture::MUMMY.id));
    m_entityManager.create<Zombie>(sf::Vector2f(150.f, 150.f), textureHolder.getResource(Assets::Texture::ZOMBIE.id));

    for (int i = 0; i < 10; ++i) {
        m_entityManager.create<Civilian>(sf::Vector2f(rand() % 250 * (i + 0.1), rand() % 250 * (i + 0.1)), textureHolder.getResource(Assets::Texture::PLAYER.id));
    }
}

void GameScene::onExit()
{
}
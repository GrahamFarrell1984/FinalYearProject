#pragma once

#include "BaseScene.h"
#include "Player.h"
#include "EntityManager.h"

class GameScene final : public BaseScene
{
public:
    GameScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    EntityManager m_entityManager;
};

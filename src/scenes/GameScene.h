#pragma once

#include "BaseScene.h"
#include "Player.h"
#include "EntityManager.h"
#include "Camera.h"

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
    static constexpr Point WORLDSIZE{ 2048, 1536 };
    static constexpr Point VIEWSIZE {  512,  384 };

//    static constexpr Point WORLDSIZE{ 1024, 768 };
//    static constexpr Point VIEWSIZE { 1024, 768  };

    Camera m_camera;
    EntityManager m_entityManager;
};
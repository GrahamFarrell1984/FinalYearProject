#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "BaseScene.h"
#include "Camera.h"
#include "EntityManager.h"
#include "Player.h"

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

    Camera m_camera;
    Player* m_player;
    EntityManager m_entityManager;
    sf::Sprite m_sprite;
    sf::Font m_font;
    sf::Text m_zombiesKilledCountText;
    sf::Text m_civiliansRescuedCountText;
};

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "BaseScene.h"
#include "Camera.h"
#include "EntityManager.h"
#include "Player.h"
#include "Level.h"

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
    static constexpr Point WORLD_SIZE{ 2048, 1536 };
    static constexpr Point VIEW_SIZE {  512,  384 };

    Camera m_camera;
    Level m_level;
    Player* m_player;
    EntityManager m_entityManager;
    sf::Sprite m_sprite;
    sf::Text m_bulletCountText;
    sf::Text m_zombiesKilledCountText;
    sf::Text m_cheerleadersRescuedCountText;
    sf::Text m_soldiersRescuedCountText;
};

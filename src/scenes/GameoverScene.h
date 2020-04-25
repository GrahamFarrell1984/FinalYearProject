#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "BaseScene.h"
#include "Types.h"

class GameoverScene final : public BaseScene
{
public:
    GameoverScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    enum class MENUOPTIONS : sf::Uint8 { MAINMENU = 0, QUIT };

    MENUOPTIONS m_options;
    sf::Sprite m_sprite;
    sf::Vector2i m_cursorPos;
};

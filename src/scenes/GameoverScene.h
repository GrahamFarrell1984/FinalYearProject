#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "BaseScene.h"
#include "Types.h"

class GameoverScene final : public BaseScene
{
public:
    GameoverScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    enum class MENUOPTIONS : uint8_t { MAINMENU = 0, QUIT };

    MENUOPTIONS m_options;
    sf::Sprite m_sprite;
    sf::Vector2i m_cursorPos;
};

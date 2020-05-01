#pragma once
#include "BaseScene.h"

#include <SFML/Graphics/Sprite.hpp>

#include "Types.h"

class PauseScene final : public BaseScene
{
public:
    PauseScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    enum class MENUOPTIONS : uint8_t { RESUME = 0, MAINMENU, QUIT };

    MENUOPTIONS m_options;
    sf::Sprite m_sprite;
    sf::Vector2i m_cursorPos;
};

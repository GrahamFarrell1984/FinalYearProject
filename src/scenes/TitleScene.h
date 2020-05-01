#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "BaseScene.h"

class TitleScene final : public BaseScene
{
public:
    TitleScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    enum class MENUOPTIONS : uint8_t { START = 0, OPTIONS, QUIT };

    MENUOPTIONS m_options;
    sf::Sprite m_sprite;
    sf::Vector2i m_cursorPos;
};

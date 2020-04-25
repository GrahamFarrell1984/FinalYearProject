#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "BaseScene.h"

class TitleScene final : public BaseScene
{
public:
    TitleScene(SceneManager& sceneManager, Scene::Name name);

    void processInput(const Keyboard& keyboard) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    enum class MENUOPTIONS : sf::Uint8 { START = 0, OPTIONS, QUIT };

    MENUOPTIONS m_options;
    sf::Sprite m_sprite;
    sf::Vector2i m_cursorPos;
};

#pragma once

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
};
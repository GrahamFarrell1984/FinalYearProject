#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "BaseScene.h"
#include "SceneTypes.h"
#include "SharedContext.h"

class SceneManager
{
public:
    explicit SceneManager(SharedContext&& sharedContext);

    void processInput(const Keyboard& keyboard) const;
    void update(sf::Time deltaTime) const;
    void render(sf::RenderWindow& window) const;
    void checkForUpdates();

    void requestSceneChange(Scene::Action action, Scene::Name name);
    bool isSceneStackEmpty() const;

    const SharedContext& getSharedContext() const;

private:
    void pushScene();
    void popAndPushScene();
    void popUntilScene();
    void popScene();
    void popAllScenes();
    std::unique_ptr<BaseScene> createScene(Scene::Name name);

    SharedContext m_sharedContext;
    Scene::Request m_sceneRequest;
    std::vector<std::unique_ptr<BaseScene>> m_sceneStack;
};
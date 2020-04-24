#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Keyboard.h"
#include "SceneTypes.h"

class SceneManager;

class BaseScene
{
public:
    BaseScene(SceneManager& sceneManager, Scene::Name name);
    virtual ~BaseScene() = default;

    virtual void processInput(const Keyboard& keyboard) = 0;
    virtual void update(sf::Time deltaTime)             = 0;
    virtual void render(sf::RenderWindow& window)       = 0;
    virtual void onEnter()                              = 0;
    virtual void onExit()                               = 0;

    Scene::Name getName() const;

protected:
    void requestSceneChange(Scene::Action action, Scene::Name name = Scene::Name::NONE) const;

private:
    Scene::Name m_name;
    SceneManager& m_sceneManager;
};
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Keyboard.h"
#include "SceneTypes.h"
#include "SharedContext.h"

class SceneManager;

class BaseScene
{
public:
    BaseScene(SceneManager& sceneManager, Scene::Name name, bool isTransparent = false);
    virtual ~BaseScene() = default;

    virtual void processInput(const Keyboard& keyboard) = 0;
    virtual void update()                               = 0;
    virtual void render(sf::RenderWindow& window)       = 0;
    virtual void onEnter()                              = 0;
    virtual void onExit()                               = 0;

    bool isTransparent();
    Scene::Name getName() const;

protected:
    const SharedContext& getSharedContext() const;
    void requestSceneChange(Scene::Action action, Scene::Name name = Scene::Name::NONE) const;

private:
    bool m_isTransparent;
    Scene::Name m_name;
    SceneManager& m_sceneManager;
};

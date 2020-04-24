#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "Keyboard.h"
#include "SceneManager.h"

class App
{
public:
    App();
    bool setup();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void lateUpdate();

    bool m_initialised;
    sf::Time m_timePerFrame;
    sf::RenderWindow m_window;
    SceneManager m_sceneManager;
    Keyboard m_keyboard;
};
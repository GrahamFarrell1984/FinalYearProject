#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"
#include "Keyboard.h"

class Player
{
public:
    void processInput(const Keyboard& keyboard);
    void update();
    void render(sf::RenderWindow& window);

private:
};
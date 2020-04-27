#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"
#include "Keyboard.h"


class Player
{
public:
    Player();

    void setup(sf::Vector2f position, const sf::Texture* texture);
    void processInput(const Keyboard& keyboard);
    void update();
    void render(sf::RenderWindow& window);

private:
    enum class Direction { UP = 0, DOWN, LEFT, RIGHT };
    Direction m_dir;
    sf::Sprite m_sprite;
};
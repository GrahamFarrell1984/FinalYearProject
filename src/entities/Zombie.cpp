#include "Zombie.h"

#include <SFML/Graphics/Texture.hpp>


Zombie::Zombie(sf::Vector2f position, const sf::Texture* texture)
{
    m_sprite.setTexture(*texture);
    m_sprite.setPosition(position);
}

void Zombie::update()
{
}

void Zombie::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

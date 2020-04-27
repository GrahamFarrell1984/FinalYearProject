#include "Mummy.h"

Mummy::Mummy(sf::Vector2f position, const sf::Texture* texture)
{
    m_sprite.setTexture(*texture);
    m_sprite.setPosition(position);
}

void Mummy::update()
{
}

void Mummy::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

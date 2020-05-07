#pragma once

#include "BaseEntity.h"

class Mummy : public BaseEntity
{
public:
    Mummy(sf::Vector2f position, const sf::Texture* texture);

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Sprite m_sprite;
};

#include "Level.h"

Level::Level(const sf::Texture* texture)
        : m_sprite{ }
{
    m_sprite.setTexture(*texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,TileSize, TileSize));
}

void Level::render(sf::RenderWindow& window, Rect camView)
{
//    int32_t startTileCol = 0;
//    int32_t startTileRow = 0;
//    if (camView.x > camView.w) {
//        startTileCol = camView.x / TileSize;
//    }
//    if (camView.y > camView.h) {
//        startTileRow = camView.y / TileSize;
//    }

    for (int32_t row = 0; row <Row; row++) {
        const int32_t tilePosY = row * TileSize;
        for (int32_t col = 0; col < Col; col++) {
            const int32_t tilePosX = col * TileSize;
            //Set texture rect based on index on [col][row]
            if (LevelData[row][col] != 0) {
                m_sprite.setPosition(tilePosX, tilePosY);
            }
            window.draw(m_sprite);
        }
    }
}
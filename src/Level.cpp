#include "Level.h"

Level::Level(const sf::Texture* texture, Point viewSize)
        : m_sprite{ }
        , m_viewSize(viewSize)
{
    m_sprite.setTexture(*texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,TileSize, TileSize));
}

void Level::render(sf::RenderWindow& window, Rect camView)
{
    // Only draw the exact amount of tiles needed to cover the screen.
    // Difference is (9 * 7) draw calls vs (32 * 24) draw calls
    int32_t startTileCol = camView.x / TileSize;
    int32_t endTileCol   = (camView.x != 0 || camView.x != m_viewSize.x) ? startTileCol + MaxColRender : startTileCol + MaxColRender -1;
    int32_t startTileRow = camView.y / TileSize;
    int32_t endTileRow   = (camView.y != 0 || camView.y != m_viewSize.y) ? startTileRow + MaxRowRender : startTileRow + MaxRowRender -1;

    for (int32_t row = startTileRow; row < endTileRow; row++) {
        const int32_t tilePosY = row * TileSize;
        for (int32_t col = startTileCol; col < endTileCol; col++) {
            const int32_t tilePosX = col * TileSize;
            //Set texture rect based on index on [col][row]
            if (LevelData[row][col] != 0) {
                m_sprite.setPosition(tilePosX, tilePosY);
            }
            window.draw(m_sprite);
        }
    }
}

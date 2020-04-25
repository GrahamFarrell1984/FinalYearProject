#pragma once

struct Data
{
    sf::Uint8 id;
    const char* filepath;
};

// NOTE : Make sure indexes are unique.
namespace Assets {
    namespace Texture {
        static constexpr Data TEXA{ 0, "assets/texture/TEX_A.png" };
    }  // namespace Texture

    namespace Font {
        static constexpr Data FONTA{ 0, "assets/font/FONT_A.ttf" };
    }  // namespace Font

    namespace Sfx {
        static constexpr Data SFXA{ 0, "assets/sfx/SFX_A.wav" };
    }  // namespace Sfx

    namespace Music {
        static constexpr Data MUSICA{ 0, "assets/music/MUSIC_A.ogg" };
    }  // namespace Sfx


}  // namespace Assets
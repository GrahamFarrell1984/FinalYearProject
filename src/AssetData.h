#pragma once

struct Data
{
    uint8_t id;
    const char* filepath;
};

// NOTE : Make sure indexes are unique.
namespace Assets {
    namespace Texture {
        static constexpr Data TEXA   { 0, "assets/texture/TEX_A.png" };
        static constexpr Data PLAYER { 1, "assets/texture/player1.png" };
        static constexpr Data ZOMBIE { 2, "assets/texture/zombie.png" };
        static constexpr Data MUMMY  { 3, "assets/texture/mummy.png" };
        static constexpr Data LEVEL  { 4, "assets/texture/level.png" };
    }  // namespace Texture

    namespace Font {
        static constexpr Data FONTA{ 0, "assets/font/Minecraft.ttf" };
    }  // namespace Font

    namespace Sfx {
        static constexpr Data SFXA{ 0, "assets/sfx/SFX_A.wav" };
        static constexpr Data SFXB{ 1, "assets/sfx/rescue.ogg" };
    }  // namespace Sfx

    namespace Music {
        static constexpr Data MUSICA{ 0, "assets/music/MUSIC_A.ogg" };
    }  // namespace Sfx


}  // namespace Assets
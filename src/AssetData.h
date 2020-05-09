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
        static constexpr Data PLAYER { 1, "assets/texture/player.png" };
        static constexpr Data MUMMY  { 2, "assets/texture/mummy.png" };
        static constexpr Data LEVEL  { 3, "assets/texture/level.png" };
    }  // namespace Texture

    namespace Font {
        static constexpr Data FONTA{ 0, "assets/font/Minecraft.ttf" };
    }  // namespace Font

    namespace Sfx {
        static constexpr Data SFXA{ 0, "assets/sfx/SFX_A.wav" };
        static constexpr Data SFXB{ 1, "assets/sfx/rescue.ogg" };
        static constexpr Data SFXC{ 2, "assets/sfx/explosion.ogg" };
        static constexpr Data SFXD{ 3, "assets/sfx/shoot.ogg" };
        static constexpr Data SFXE{ 4, "assets/sfx/bump.ogg" };
    }  // namespace Sfx

    namespace Music {
        static constexpr Data MUSICA{ 0, "assets/music/MUSIC_A.ogg" };
        static constexpr Data MUSICB{ 1, "assets/music/killing-zombies-loop.ogg" };
    }  // namespace Sfx


}  // namespace Assets
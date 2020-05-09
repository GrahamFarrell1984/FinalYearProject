#pragma once

struct Data
{
    uint8_t id;
    const char* filepath;
};

// NOTE : Make sure indexes are unique.
namespace Assets {
    namespace Texture {
        static constexpr Data SCENES   { 0, "assets/texture/scenes.png" };
        static constexpr Data ENTITIES { 1, "assets/texture/entities.png" };
        static constexpr Data LEVEL    { 2, "assets/texture/level.png" };
    }  // namespace Texture

    namespace Font {
        static constexpr Data FONTA { 0, "assets/font/game-font.ttf" };
    }  // namespace Font

    namespace Sfx {
        static constexpr Data SFXA { 0, "assets/sfx/select.ogg" };
        static constexpr Data SFXB { 1, "assets/sfx/rescue.ogg" };
        static constexpr Data SFXC { 2, "assets/sfx/explosion.ogg" };
        static constexpr Data SFXD { 3, "assets/sfx/shoot.ogg" };
        static constexpr Data SFXE { 4, "assets/sfx/bump.ogg" };
    }  // namespace Sfx

    namespace Music {
        static constexpr Data MUSICA { 0, "assets/music/killing-zombies.ogg" };
        static constexpr Data MUSICB { 1, "assets/music/main-title.ogg" };
    }  // namespace Sfx


}  // namespace Assets
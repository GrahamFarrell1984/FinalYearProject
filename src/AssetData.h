#pragma once

struct Data
{
    uint8_t id;
    const char* filepath;
};

// NOTE : Make sure indexes are unique.
namespace Assets {
    namespace Texture {
        static constexpr Data Player{ 0, "assets/texture/player.png" };
    }  // namespace Texture

    namespace Font {
        static constexpr Data EBB{ 0, "assets/font/EBB.ttf" };
    }  // namespace Font

    namespace Sfx {
        static constexpr Data Test{ 0, "assets/sfx/test.wav" };
    }  // namespace Sfx

    namespace Music {
        static constexpr Data Test{ 0, "assets/music/test.ogg" };
    }  // namespace Sfx


}  // namespace Assets
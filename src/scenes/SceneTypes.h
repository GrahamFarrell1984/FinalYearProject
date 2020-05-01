#pragma once
#include <SFML/Config.hpp>

namespace Scene {
    // Inc when adding new scenes. NONE is not added.
    static constexpr uint8_t SCENECOUNT = 6;

    enum class Name : uint8_t
    {
        NONE = 0,
        TITLE,
        OPTIONS,
        GAME,
        PAUSE,
        GAMEOVER,
        TEST
    };

    enum class Action : uint8_t
    {
        NONE,
        PUSH,
        POP,
        POPUNTIL,
        POPANDADD,
        POPALL
    };

    struct Request
    {
        Action action;
        Name name;
    };
}  // namespace Scene

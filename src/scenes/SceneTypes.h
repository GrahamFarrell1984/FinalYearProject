#pragma once
#include <SFML/Config.hpp>

namespace Scene {
    // Inc when adding new scenes. NONE is not added.
    static constexpr uint8_t SCENE_COUNT = 6;

    enum class Name : uint8_t
    {
        NONE = 0,
        TITLE,
        OPTIONS,
        GAME,
        PAUSE,
        GAME_OVER,
        TEST
    };

    enum class Action : uint8_t
    {
        NONE,
        PUSH,
        POP,
        POP_UNTIL,
        POP_AND_ADD,
        POP_ALL
    };

    struct Request
    {
        Action action;
        Name name;
    };
}  // namespace Scene

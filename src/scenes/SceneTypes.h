#pragma once
#include <SFML/Config.hpp>

namespace Scene {
    // Inc when adding new scenes. NONE is not added.
    static constexpr sf::Uint8 SCENECOUNT = 5;

    enum class Name : sf::Uint8
    {
        NONE = 0,
        TITLE,
        GAME,
        PAUSE,
        GAMEOVER,
        TEST
    };

    enum class Action : sf::Uint8
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

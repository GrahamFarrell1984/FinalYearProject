#pragma once

namespace Entity {
    enum class Direction : uint8_t {
        Up, Down, Left, Right
    };

    enum class State
    {
        NONE = 0,
        STANDING,
        MOVING,
        SHOOTING,
        HIT,
        DYING,
        DEAD,
    };
} // NS Entity
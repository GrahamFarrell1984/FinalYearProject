#pragma once

namespace Entity {
    enum class Direction : uint8_t {
        Up, Down, Left, Right
    };

    enum class State
    {
        NONE = 0,
        STANDFACINGUP,
        STANDFACINGDOWN,
        STANDFACINGLEFT,
        STANDFACINGRIGHT,
        MOVEUP,
        MOVEDOWN,
        MOVELEFT,
        MOVERIGHT,
        DIE,
        SHOOT
    };
} // NS Entity

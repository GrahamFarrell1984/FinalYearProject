#pragma once

namespace Entity {
    enum class State
    {
        NONE = 0,
        STANDUP,
        STANDDOWN,
        STANDLEFT,
        STANDRIGHT,
        MOVEUP,
        MOVEDOWN,
        MOVELEFT,
        MOVERIGHT,
        DIE,
        SHOOT
    };
} // NS Entity
#pragma once

namespace Anim {

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
        SHOOTDOWN,
        SHOOTRIGHT,
        SHOOTUP,
        SHOOTLEFT,
        HITFACINGDOWN,
        HITFACINGRIGHT,
        HITFACINGLEFT,
        HITFACINGUP,
        DYING,
        DEAD
    };
} // NS Anim
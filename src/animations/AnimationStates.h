#pragma once

namespace Anim {

    enum class State
    {
        NONE = 0,
        STAND_FACING_UP,
        STAND_FACING_DOWN,
        STAND_FACING_LEFT,
        STAND_FACING_RIGHT,
        MOVE_UP,
        MOVE_DOWN,
        MOVE_LEFT,
        MOVE_RIGHT,
        SHOOT_DOWN,
        SHOOT_RIGHT,
        SHOOT_UP,
        SHOOT_LEFT,
        HIT_FACING_DOWN,
        HIT_FACING_RIGHT,
        HIT_FACING_LEFT,
        HIT_FACING_UP,
        DYING,
        DEAD,
        BULLET_UP,
        BULLET_DOWN,
        BULLET_LEFT,
        BULLET_RIGHT,
        BULLET_DYING_UP,
        BULLET_DYING_DOWN,
        BULLET_DYING_LEFT,
        BULLET_DYING_RIGHT,
        JUMPING,
        ZOMBIE_SPAWNING,
        ZOMBIE_MOVING_DOWN,
        ZOMBIE_MOVING_UP,
        ZOMBIE_MOVING_LEFT,
        ZOMBIE_MOVING_RIGHT,
        ZOMBIE_EXPLODING,
        LOOKING_AROUND
    };
} // NS Anim
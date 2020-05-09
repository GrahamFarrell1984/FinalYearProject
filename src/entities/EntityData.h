#pragma once

#include <array>

#include "AnimationStates.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<TexSrc>;
using AnimData  = std::unordered_map<Anim::State, Animation>;

static const FrameData SpriteData{
        { // Source
        { 0, 0, 26, 42 },  // Index [0] - TexSrc for player facing down
        { 26, 0, 26, 42 },  // Index [1] - TexSrc for player moving down
        { 52, 0, 26, 42 },  // Index [2] - TexSrc for player moving down
        { 78, 0, 26, 42 },  // Index [3] - TexSrc for player moving down
        { 104, 0, 26, 42 },  // Index [4] - TexSrc for player moving down
        { 130, 0, 26, 42 },  // Index [5] - TexSrc for player firing gun down
        { 156, 0, 26, 42 },  // Index [6] - TexSrc for player aiming fire extinguisher down

        { 0, 42, 26, 42 },  // Index [7] - TexSrc for player facing left
        { 26, 42, 26, 42 },  // Index [8] - TexSrc for player moving left
        { 52, 42, 26, 42 },  // Index [9] - TexSrc for player moving left
        { 78, 42, 26, 42 },  // Index [10] - TexSrc for player moving left
        { 104, 42, 26, 42 },  // Index [11] - TexSrc for player moving left
        { 130, 42, 32, 42 },  // Index [12] - TexSrc for player firing gun left
        { 156, 42, 38, 42 },  // Index [13] - TexSrc for player aiming fire extinguisher left

        { 0, 84, 26, 42 },  // Index [14] - TexSrc for player facing right
        { 26, 84, 25, 42 },  // Index [15] - TexSrc for player moving right
        { 52, 84, 25, 42 },  // Index [16] - TexSrc for player moving right
        { 78, 84, 25, 42 },  // Index [17] - TexSrc for player moving right
        { 104, 84, 25, 42 },  // Index [18] - TexSrc for player moving right
        { 130, 84, 32, 42 },  // Index [19] - TexSrc for player firing gun right
        { 156, 84, 38, 42 },  // Index [20] - TexSrc for player aiming fire extinguisher right

        { 0, 126, 26, 42 },  // Index [21] - TexSrc for player facing up
        { 26, 126, 26, 42 },  // Index [22] - TexSrc for player moving up
        { 52, 126, 26, 42 },  // Index [23] - TexSrc for player moving up
        { 78, 126, 26, 42 },  // Index [24] - TexSrc for player moving up
        { 104, 126, 26, 42 },  // Index [25] - TexSrc for player moving up
        { 130,126,26,42 },  // Index [26] - TexSrc for player firing up - it is used for both the gun and the fire extinguisher

        { 0, 168, 39, 45 },  // Index [27] - TexSrc for player dying
        { 39, 168, 39, 45 },  // Index [28] - TexSrc for player dying
        { 78, 168, 39, 45 },  // Index [29] - TexSrc for player dying
        { 117, 168, 39, 45 },  // Index [30] - TexSrc for player dying
        { 156, 168, 39, 45 },  // Index [31] - TexSrc for player dying
        { 0, 213, 39, 45 },  // Index [32] - TexSrc for player dying
        { 39, 213, 39, 45 },  // Index [33] - TexSrc for player dying
        { 78, 213, 39, 45 },  // Index [34] - TexSrc for player dying
        { 117, 213, 39, 45 },  // Index [35] - TexSrc for player dying
        { 156, 213, 39, 45 },  // Index [36] - TexSrc for player dying
        { 0, 258, 39, 45 },  // Index [37] - TexSrc for player dying
        { 39, 258, 39, 45 },  // Index [38] - TexSrc for player dying
        { 78, 258, 39, 45 },  // Index [39] - TexSrc for player dying
        { 117, 258, 39, 45 },  // Index [40] - TexSrc for player dying
        { 156, 258, 39, 45 },  // Index [41] - TexSrc for player dying
        { 0, 303, 39, 45 },  // Index [42] - TexSrc for player dying
        { 39, 303, 39, 45 },  // Index [43] - TexSrc for player dying
        { 78, 303, 39, 45 },  // Index [44] - TexSrc for player dying
        { 117, 303, 39, 45 },  // Index [45] - TexSrc for player dying

        { 0, 348, 41, 60 },  // Index [46] - TexSrc for player hit
        { 41, 348, 41, 60 },  // Index [47] - TexSrc for player hit
        { 82, 348, 41, 60 },  // Index [48] - TexSrc for player hit
        { 123, 348, 41, 60 },  // Index [49] - TexSrc for player hit
        { 0, 408, 41, 60 },  // Index [50] - TexSrc for player hit
        { 41, 408, 41, 60 },  // Index [51] - TexSrc for player hit
        { 82, 408, 41, 60 },  // Index [52] - TexSrc for player hit
        { 123, 408, 41, 60 },  // Index [53] - TexSrc for player hit
        { 82, 348, 41, 60 },  // Index [54] - TexSrc for player hit

        { 171, 136, 7, 16 },  // Index [55] - TexSrc for bullet up
        { 164, 136, 7, 16 },  // Index [56] - TexSrc for bullet down
        { 164, 157, 18, 5 },  // Index [57] - TexSrc for bullet left
        { 164, 152, 18, 5 },  // Index [58] - TexSrc for bullet right
        { 182, 152, 15, 13 },  // Index [59] - TexSrc for bullet splash1
        { 178, 136, 16, 16 },  // Index [60] - TexSrc for bullet splash2

        { 0, 468, 45, 70 },  // Index [61] - Frame for cheerleader jumping
        { 46, 468, 45, 70 },  // Index [62] - Frame for cheerleader jumping
        { 92, 468, 45, 70 },  // Index [63] - Frame for cheerleader jumping
        { 138, 468, 45, 70 },  // Index [64] - Frame for cheerleader jumping
        { 184, 468, 45, 70 },  // Index [65] - Frame for cheerleader jumping

        { 0, 536, 44, 63 },  // Index [66] - Frame for zombie spawning
        { 44, 536, 44, 63 },  // Index [67] - Frame for zombie spawning
        { 88, 536, 44, 63 },  // Index [68] - Frame for zombie spawning
        { 132, 536, 44, 63 },  // Index [69] - Frame for zombie spawning
        { 176, 536, 44, 63 },  // Index [70] - Frame for zombie spawning
        { 220, 536, 44, 63 },  // Index [71] - Frame for zombie spawning

        { 0, 599, 44, 63 },  // Index [72] - Frame for zombie walking down
        { 44, 599, 44, 63 },  // Index [73] - Frame for zombie walking down
        { 88, 599, 44, 63 },  // Index [74] - Frame for zombie walking down
        { 132, 599, 44, 63 },  // Index [75] - Frame for zombie walking down

        { 0, 662, 44, 63 },  // Index [76] - Frame for zombie walking right
        { 44, 662, 44, 63 },  // Index [77] - Frame for zombie walking right
        { 88, 662, 44, 63 },  // Index [78] - Frame for zombie walking right
        { 132, 662, 44, 63 },  // Index [79] - Frame for zombie walking right

        { 0, 725, 44, 63 },  // Index [80] - Frame for zombie walking left
        { 44, 725, 44, 63 },  // Index [81] - Frame for zombie walking left
        { 88, 725, 44, 63 },  // Index [82] - Frame for zombie walking left
        { 132, 725, 44, 63 },  // Index [83] - Frame for zombie walking left

        { 0, 788, 44, 63 },  // Index [84] - Frame for zombie walking up
        { 44, 788, 44, 63 },  // Index [85] - Frame for zombie walking up
        { 88, 788, 44, 63 },  // Index [86] - Frame for zombie walking up
        { 132, 788, 44, 63 },  // Index [87] - Frame for zombie walking up

        { 0, 851, 44, 63 },  // Index [88] - Frame for zombie exploding
        { 44, 851, 44, 63 },  // Index [89] - Frame for zombie exploding
        { 88, 851, 44, 63 },  // Index [90] - Frame for zombie exploding
        { 132, 851, 44, 63 },  // Index [91] - Frame for zombie exploding
        { 176, 851, 44, 63 },  // Index [92] - Frame for zombie exploding

        { 0, 914, 44, 63 },  // Index [93] - Frame for zombie exploding
        { 44, 914, 44, 63 },  // Index [94] - Frame for zombie exploding
        { 88, 914, 44, 63 },  // Index [95] - Frame for zombie exploding
        { 132, 914, 44, 63 },  // Index [96] - Frame for zombie exploding

        { 0, 978, 36, 49 },  // Index [97] - Frame for soldier looking around
        { 36, 978, 36, 49 },  // Index [98] - Frame for soldier looking around
        { 72, 978, 36, 49 } }  // Index [99] - Frame for soldier looking around
};

static const AnimData SpriteAnimation{
        // State,                         // loop,            // loopFrame,         // frameIdx[]
        { Anim::State::STAND_FACING_DOWN, { true, 0, { { 0, 0, { 0, 0 } } } } },
        { Anim::State::STAND_FACING_LEFT, { true, 0, { { 0, 7, { 0, 0 } } } } },
        { Anim::State::STAND_FACING_RIGHT, { true, 0, { { 0, 14, { 0, 0 } } } } },
        { Anim::State::STAND_FACING_UP, { true, 0, { { 0, 21, { 0, 0 } } } } },

        { Anim::State::MOVE_DOWN,{ true, 0, { { 10, 1, { 0, 0 } }, { 10, 2, { 0, 0 } }, { 10, 3, { 0, 0 } }, { 10, 4, { 0, 0 } } } } },
        { Anim::State::MOVE_LEFT,{ true, 0, { { 10, 8, { 0, 0 } }, { 10, 9, { 0, 0 } }, { 10, 10, { 0, 0 } }, { 10, 11, { 0, 0 } } } } },
        { Anim::State::MOVE_RIGHT,{ true, 0, { { 10, 15, { 0, 0 } }, { 10, 16, { 0, 0 } }, { 10, 17, { 0, 0 } }, { 10, 18, { 0, 0 } } } } },
        { Anim::State::MOVE_UP,{ true, 0, { { 10, 22, { 0, 0 } }, { 10, 23, { 0, 0 } }, { 10, 24, { 0, 0 } }, { 10, 25, { 0, 0 } } } } },

        { Anim::State::SHOOT_DOWN, { true, 0, { { 0, 5, { 0, 0 } } } } },
        { Anim::State::SHOOT_LEFT, { true, 0, { { 0, 12, { -6, 0 } } } } },
        { Anim::State::SHOOT_RIGHT, { true, 0, { { 0, 19, { 0, 0 } } } } },
        { Anim::State::SHOOT_UP, { true, 0, { { 0, 26, { 0, 0 } } } } },

        { Anim::State::HIT_FACING_DOWN, { false, 0, { { 10, 46, { -8, -15 } }, { 10, 47, { -8, -15 } } } } },
        { Anim::State::HIT_FACING_RIGHT, { false, 0, { { 10, 48, { -8, -15 } }, { 10, 49, { -8, -15 } } } } },
        { Anim::State::HIT_FACING_LEFT, { false, 0, { { 10, 50, { -8, -15 } }, { 10, 51, { -8, -15 } } } } },
        { Anim::State::HIT_FACING_UP, { false, 0, { { 10, 52, { -8, -15 } }, { 10, 53, { -8, -15 } } } } },

        { Anim::State::DYING,{ false, 0,{ { 10, 27, { -10, 2 } }, { 10, 28, { -10, 2 } }, { 10, 29, { -10, 2 } }, { 10, 30, { -10, 2 } }, { 10, 31, { -10, 2 } }, { 10, 32, { -10, 2 } }, { 10, 33, { -10, 2 } }, { 10, 34, { -10, 2 } }, { 10, 35, { -10, 2 } }, { 10, 36, { -10, 2 } }, { 10, 37, { -10, 2 } }, { 10, 38, { -10, 2 } }, { 10, 39, { -10, 2 } }, { 10, 40, { -10, 2 } }, { 10, 41, { -10, 2 } }, { 10, 42, { -10, 2 } }, { 10, 43, { -10, 2 } }, { 10, 44, { -10, 2 } }, { 10, 45, { -10, 2 } } } } },

        { Anim::State::BULLET_DOWN, { true, 0, { { 0, 56, { 9, 24 } } } } },
        { Anim::State::BULLET_LEFT, { true, 0, { { 0, 57, { -16, 12 } } } } },
        { Anim::State::BULLET_RIGHT, { true, 0, { { 0, 58, { 24, 12 } } } } },
        { Anim::State::BULLET_UP, { true, 0, { { 0, 55, { 9, -4 } } } } },

        { Anim::State::BULLET_DYING_DOWN, { false, 0, { { 5, 59, { 5, 34 } }, { 10, 60, { 5, 34 } } } } },
        { Anim::State::BULLET_DYING_LEFT, { false, 0, { { 5, 59, { -24, 8 } }, { 10, 60, { -24, 8 } } } } },
        { Anim::State::BULLET_DYING_RIGHT, { false, 0, { { 5, 59, { 34, 8 } }, { 10, 60, {  34, 8 } } } } },
        { Anim::State::BULLET_DYING_UP, { false, 0, { { 5, 59, { 5, -10 } }, { 10, 60, { 5, -10 } } } } },

        { Anim::State::JUMPING, { true, 0, { { 10, 61, {0,0} }, { 10, 62, {0,0} }, { 10, 63, {0,0} }, { 10, 64, {0,0} }, { 10, 65, {0,0} }, { 10, 64, {0,0} }, { 10, 63, {0,0} }, { 10, 62, {0,0} } } } },

        { Anim::State::ZOMBIE_SPAWNING, { false, 0, { { 20, 66, {0,0} }, { 20, 67, {0,0} }, { 20, 68, {0,0} }, { 20, 69, {0,0} }, { 20, 70, {0,0} }, { 20, 71, {0,0} } } } },
        { Anim::State::ZOMBIE_MOVING_DOWN, { true, 0, { { 20, 72, {0,0} }, { 20, 73, {0,0} }, { 20, 74, {0,0} }, { 20, 75, {0,0} } } } },
        { Anim::State::ZOMBIE_MOVING_LEFT, { true, 0, { { 20, 80, {0,0} }, { 20, 81, {0,0} }, { 20, 82, {0,0} }, { 20, 83, {0,0} } } } },
        { Anim::State::ZOMBIE_MOVING_RIGHT, { true, 0, { { 20, 76, {0,0} }, { 20, 77, {0,0} }, { 20, 78, {0,0} }, { 20, 79, {0,0} } } } },
        { Anim::State::ZOMBIE_MOVING_UP, { true, 0, { { 20, 84, {0,0} }, { 20, 85, {0,0} }, { 20, 86, {0,0} }, { 20, 87, {0,0} } } } },
        { Anim::State::ZOMBIE_EXPLODING, { false, 0, { { 10, 88, {0,0} }, { 10, 89, {0,0} }, { 10, 90, {0,0} }, { 10, 91, {0,0} }, { 10, 92, {0,0} }, { 10, 93, {0,0} }, { 10, 94, {0,0} }, { 30, 95, {0,0} }, { 30, 96, {0,0} } } } },

        { Anim::State::LOOKING_AROUND, { true, 0, { { 60, 97, {0,0} }, { 120, 98, {0,0} }, { 60, 99, {0,0} }, { 120, 98, {0,0} } } } }
};

static const AnimData CivilianAnimation{
        // State,                  // loop,            // loopFrame,         // frameIdx[]
        { Anim::State::JUMPING,  { true, 0, { { 10, 61, {0,0} }, { 10, 62, {0,0} }, { 10, 63, {0,0} }, { 10, 64, {0,0} }, { 10, 65, {0,0} }, { 10, 64, {0,0} }, { 10, 63, {0,0} }, { 10, 62, {0,0} } } } }
};

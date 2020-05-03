#pragma once

#include <array>

#include "AnimationStates.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<Frame>;
using AnimData  = std::unordered_map<Anim::State, Animation>;

static const FrameData PlayerSpriteData{ {
     // Origin,                            Source
     { { 0, 0 }, { 0, 0, 26, 42 } },                // Index [0] - Frame for player facing down
     { { 0, 0 }, { 26, 0, 26, 42 } },               // Index [1] - Frame for player moving down
     { { 0, 0 }, { 52, 0, 26, 42 } },               // Index [2] - Frame for player moving down
     { { 0, 0 }, { 78, 0, 26, 42 } },               // Index [3] - Frame for player moving down
     { { 0, 0 }, { 104, 0, 26, 42 } },              // Index [4] - Frame for player moving down
     { { 0, 0 }, { 130, 0, 26, 42 } },              // Index [5] - Frame for player firing gun down
     { { 0, 0 }, { 156, 0, 26, 42 } },              // Index [6] - Frame for player aiming fire extinguisher down

     { { 0, 0 }, { 0, 42, 26, 42 } },               // Index [7] - Frame for player facing left
     { { 0, 0 }, { 26, 42, 26, 42 } },              // Index [8] - Frame for player moving left
     { { 0, 0 }, { 52, 42, 26, 42 } },              // Index [9] - Frame for player moving left
     { { 0, 0 }, { 78, 42, 26, 42 } },              // Index [10] - Frame for player moving left
     { { 0, 0 }, { 104, 42, 26, 42 } },             // Index [11] - Frame for player moving left
     { { -6, 0 }, { 130, 42, 32, 42 } },            // Index [12] - Frame for player firing gun left
     { { -12, 0 }, { 156, 42, 38, 42 } },           // Index [13] - Frame for player aiming fire extinguisher left

     { { 0, 0 }, { 0, 84, 26, 42 } },               // Index [14] - Frame for player facing right
     { { 0, 0 }, { 26, 84, 26, 42 } },              // Index [15] - Frame for player moving right
     { { 0, 0 }, { 52, 84, 26, 42 } },              // Index [16] - Frame for player moving right
     { { 0, 0 }, { 78, 84, 26, 42 } },              // Index [17] - Frame for player moving right
     { { 0, 0 }, { 104, 84, 26, 42 } },             // Index [18] - Frame for player moving right
     { { 0, 0 }, { 130, 84, 32, 42 } },             // Index [19] - Frame for player firing gun right
     { { 0, 0 }, { 156, 84, 38, 42 } },             // Index [20] - Frame for player aiming fire extinguisher right

     { { 0, 0 }, { 0, 126, 26, 42 } },              // Index [21] - Frame for player facing up
     { { 0, 0 }, { 26, 126, 26, 42 } },             // Index [22] - Frame for player moving up
     { { 0, 0 }, { 52, 126, 26, 42 } },             // Index [23] - Frame for player moving up
     { { 0, 0 }, { 78, 126, 26, 42 } },             // Index [24] - Frame for player moving up
     { { 0, 0 }, { 104, 126, 26, 42 } },            // Index [25] - Frame for player moving up
     { { 0, 0 }, { 130, 126, 26, 42 } },            // Index [26] - Frame for player firing up - it is used for both the gun and the fire extinguisher

     { { -10, 2 }, { 0, 168, 39, 45 } },            // Index [27] - Frame for player dying
     { { -10, 2 }, { 39, 168, 39, 45 } },           // Index [28] - Frame for player dying
     { { -10, 2 }, { 78, 168, 39, 45 } },           // Index [29] - Frame for player dying
     { { -10, 2 }, { 117, 168, 39, 45 } },          // Index [30] - Frame for player dying
     { { -10, 2 }, { 156, 168, 39, 45 } },          // Index [31] - Frame for player dying
     { { -10, 2 }, { 0, 213, 39, 45 } },            // Index [32] - Frame for player dying
     { { -10, 2 }, { 39, 213, 39, 45 } },           // Index [33] - Frame for player dying
     { { -10, 2 }, { 78, 213, 39, 45 } },           // Index [34] - Frame for player dying
     { { -10, 2 }, { 117, 213, 39, 45 } },          // Index [35] - Frame for player dying
     { { -10, 2 }, { 156, 213, 39, 45 } },          // Index [36] - Frame for player dying
     { { -10, 2 }, { 0, 258, 39, 45 } },            // Index [37] - Frame for player dying
     { { -10, 2 }, { 39, 258, 39, 45 } },           // Index [38] - Frame for player dying
     { { -10, 2 }, { 78, 258, 39, 45 } },           // Index [39] - Frame for player dying
     { { -10, 2 }, { 117, 258, 39, 45 } },          // Index [40] - Frame for player dying
     { { -10, 2 }, { 156, 258, 39, 45 } },          // Index [41] - Frame for player dying
     { { -10, 2 }, { 0, 303, 39, 45 } },            // Index [42] - Frame for player dying
     { { -10, 2 }, { 39, 303, 39, 45 } },           // Index [43] - Frame for player dying
     { { -10, 2 }, { 78, 303, 39, 45 } },           // Index [44] - Frame for player dying
     { { -10, 2 }, { 117, 303, 39, 45 } },          // Index [45] - Frame for player dying

     { { -8, -15 }, { 0, 348, 41, 60 } },           // Index [46] - Frame for player dying
     { { -8, -15 }, { 41, 348, 41, 60 } },          // Index [47] - Frame for player dying
     { { -8, -15 }, { 82, 348, 41, 60 } },          // Index [48] - Frame for player dying
     { { -8, -15 }, { 123, 348, 41, 60 } },         // Index [49] - Frame for player dying
     { { -8, -15 }, { 0, 408, 41, 60 } },           // Index [50] - Frame for player dying
     { { -8, -15 }, { 41, 408, 41, 60 } },          // Index [51] - Frame for player dying
     { { -8, -15 }, { 82, 408, 41, 60 } },          // Index [52] - Frame for player dying
     { { -8, -15 }, { 123, 408, 41, 60 } } }        // Index [53] - Frame for player dying

};

static const AnimData PlayerAnimation{
    // State,                       loop,          loopframe,            frameIdx[]
    { Anim::State::STANDFACINGDOWN, { true, 0, { { 0, 0 } } } },

    { Anim::State::STANDFACINGLEFT,   { true, 0, { { 0, 7 } } } },

    { Anim::State::STANDFACINGRIGHT, { true, 0, { { 0, 14 } } } },

    { Anim::State::STANDFACINGUP,   { true, 0, { { 0, 21 } } } },

    { Anim::State::MOVEDOWN,  { true, 0, { { 10, 1 }, { 10, 2 }, { 10, 3 }, { 10, 4 } } } },

    { Anim::State::MOVELEFT,    { true, 0, { { 10, 8 }, { 10, 9 }, { 10, 10 }, { 10, 11 } } } },

    { Anim::State::MOVERIGHT,    { true, 0, { { 10, 15 }, { 10, 16 }, { 10, 17 }, { 10, 18 } } } },

    { Anim::State::MOVEUP,  { true, 0, { { 10, 22 }, { 10, 23 }, { 10, 24 }, { 10, 25 } } } },

    { Anim::State::SHOOTDOWN,  { true, 0, { { 0, 5 } } } },

    { Anim::State::SHOOTLEFT,  { true, 0, { { 0, 12 } } } },

    { Anim::State::SHOOTRIGHT,  { true, 0, { { 0, 19 } } } },

    { Anim::State::SHOOTUP,  { true, 0, { { 0, 26 } } } },

    { Anim::State::HITFACINGDOWN,  {false, 0, { { 10, 46 }, { 10, 47 } } } },

    { Anim::State::HITFACINGRIGHT,  { false, 0, { { 10, 48 }, { 10, 49 } } } },

    { Anim::State::HITFACINGLEFT,  { false, 0, { { 10, 50 }, { 10, 51 } } } },

    { Anim::State::HITFACINGUP,  { false, 0, { { 10, 52 }, { 10, 53 } } } },

    { Anim::State::DYING,  { false, 0, { { 10, 27 }, { 10, 28 }, { 10, 29 }, { 10, 30 }, { 10, 31 }, { 10, 32 }, { 10, 33 }, { 10, 34 }, { 10, 35 }, { 10, 36 }, { 10, 37 }, { 10, 38 }, { 10, 39 }, { 10, 40 }, { 10, 41 }, { 10, 42 }, { 10, 43 }, { 10, 44 }, { 10, 45 } } } }

};

#pragma once

#include <array>

#include "AnimationStates.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<TexSrc>;
using AnimData  = std::unordered_map<Anim::State, Animation>;

static const FrameData PlayerSpriteData{
        { // Origin,                            Source
                { { 0, 0, 26, 42 } },  // Index [0] - TexSrc for player facing down
                { { 26, 0, 26, 42 } },  // Index [1] - TexSrc for player moving down
                { { 52, 0, 26, 42 } },  // Index [2] - TexSrc for player moving down
                { { 78, 0, 26, 42 } },  // Index [3] - TexSrc for player moving down
                { { 104, 0, 26, 42 } },  // Index [4] - TexSrc for player moving down
                { { 130, 0, 26, 42 } },  // Index [5] - TexSrc for player firing gun down
                { { 156, 0, 26, 42 } },  // Index [6] - TexSrc for player aiming fire extinguisher down
                { { 0, 42, 26, 42 } },  // Index [7] - TexSrc for player facing left
                { { 26, 42, 26, 42 } },  // Index [8] - TexSrc for player moving left
                { { 52, 42, 26, 42 } },  // Index [9] - TexSrc for player moving left
                { { 78, 42, 26, 42 } },  // Index [10] - TexSrc for player moving left
                { { 104, 42, 26, 42 } },  // Index [11] - TexSrc for player moving left
                { { 130, 42, 32, 42 } },  // Index [12] - TexSrc for player firing gun left
                { { 156, 42, 38, 42 } },  // Index [13] - TexSrc for player aiming fire extinguisher left
                { { 0, 84, 26, 42 } },  // Index [14] - TexSrc for player facing right
                { { 26, 84, 26, 42 } },  // Index [15] - TexSrc for player moving right
                { { 52, 84, 26, 42 } },  // Index [16] - TexSrc for player moving right
                { { 78, 84, 26, 42 } },  // Index [17] - TexSrc for player moving right
                { { 104, 84, 26, 42 } },  // Index [18] - TexSrc for player moving right
                { { 130, 84, 32, 42 } },  // Index [19] - TexSrc for player firing gun right
                { { 156, 84, 38, 42 } },  // Index [20] - TexSrc for player aiming fire extinguisher right
                { { 0, 126, 26, 42 } },  // Index [21] - TexSrc for player facing up
                { { 26, 126, 26, 42 } },  // Index [22] - TexSrc for player moving up
                { { 52, 126, 26, 42 } },  // Index [23] - TexSrc for player moving up
                { { 78, 126, 26, 42 } },  // Index [24] - TexSrc for player moving up
                { { 104, 126, 26, 42 } },  // Index [25] - TexSrc for player moving up
                { { 130,126,26,42 } },  // Index [26] - TexSrc for player firing up - it is used for both the gun and the fire extinguisher
                { { 0, 168, 39, 45 } },  // Index [27] - TexSrc for player dying
                { { 39, 168, 39, 45 } },  // Index [28] - TexSrc for player dying
                { { 78, 168, 39, 45 } },  // Index [29] - TexSrc for player dying
                { { 117, 168, 39, 45 } },  // Index [30] - TexSrc for player dying
                { { 156, 168, 39, 45 } },  // Index [31] - TexSrc for player dying
                { { 0, 213, 39, 45 } },  // Index [32] - TexSrc for player dying
                { { 39, 213, 39, 45 } },  // Index [33] - TexSrc for player dying
                { { 78, 213, 39, 45 } },  // Index [34] - TexSrc for player dying
                { { 117, 213, 39, 45 } },  // Index [35] - TexSrc for player dying
                { { 156, 213, 39, 45 } },  // Index [36] - TexSrc for player dying
                { { 0, 258, 39, 45 } },  // Index [37] - TexSrc for player dying
                { { 39, 258, 39, 45 } },  // Index [38] - TexSrc for player dying
                { { 78, 258, 39, 45 } },  // Index [39] - TexSrc for player dying
                { { 117, 258, 39, 45 } },  // Index [40] - TexSrc for player dying
                { { 156, 258, 39, 45 } },  // Index [41] - TexSrc for player dying
                { { 0, 303, 39, 45 } },  // Index [42] - TexSrc for player dying
                { { 39, 303, 39, 45 } },  // Index [43] - TexSrc for player dying
                { { 78, 303, 39, 45 } },  // Index [44] - TexSrc for player dying
                { { 117, 303, 39, 45 } },  // Index [45] - TexSrc for player dying
                { { 0, 348, 41, 60 } },  // Index [46] - TexSrc for player hit
                { { 41, 348, 41, 60 } },  // Index [47] - TexSrc for player hit
                { { 82, 348, 41, 60 } },  // Index [48] - TexSrc for player hit
                { { 123, 348, 41, 60 } },  // Index [49] - TexSrc for player hit
                { { 0, 408, 41, 60 } },  // Index [50] - TexSrc for player hit
                { { 41, 408, 41, 60 } },  // Index [51] - TexSrc for player hit
                { { 82, 408, 41, 60 } },  // Index [52] - TexSrc for player hit
                { { 123, 408, 41, 60 } },  // Index [53] - TexSrc for player hit
                { { 82, 348, 41, 60 } },  // Index [54] - TexSrc for player hit
                { { 171, 136, 7, 16 } },  // Index [55] - TexSrc for bullet up
                { { 164, 136, 7, 16 } },  // Index [56] - TexSrc for bullet down
                { { 164, 157, 18, 5 } },  // Index [57] - TexSrc for bullet left
                { { 164, 152, 18, 5 } },  // Index [58] - TexSrc for bullet right
                { { 182, 152, 15, 13 } },  // Index [59] - TexSrc for bullet splash1
                { { 178, 136, 16, 16 } } }  // Index [60] - TexSrc for bullet splash2
};

static const AnimData PlayerAnimation{
        // State,                       loop,          loopframe,            frameIdx[]
        { Anim::State::STANDFACINGDOWN, { true, 0, { { 0, 0, { 0, 0 } } } } },
        { Anim::State::STANDFACINGLEFT, { true, 0, { { 0, 7, { 0, 0 } } } } },
        { Anim::State::STANDFACINGRIGHT, { true, 0, { { 0, 14, { 0, 0 } } } } },
        { Anim::State::STANDFACINGUP, { true, 0, { { 0, 21, { 0, 0 } } } } },
        { Anim::State::MOVEDOWN,{ true, 0, { { 10, 1, { 0, 0 } }, { 10, 2, { 0, 0 } }, { 10, 3, { 0, 0 } }, { 10, 4, { 0, 0 } } } } },
        { Anim::State::MOVELEFT,{ true, 0, { { 10, 8, { 0, 0 } }, { 10, 9, { 0, 0 } }, { 10, 10, { 0, 0 } }, { 10, 11, { 0, 0 } } } } },
        { Anim::State::MOVERIGHT,{ true, 0, { { 10, 15, { 0, 0 } }, { 10, 16, { 0, 0 } }, { 10, 17, { 0, 0 } }, { 10, 18, { 0, 0 } } } } },
        { Anim::State::MOVEUP,{ true, 0, { { 10, 22, { 0, 0 } }, { 10, 23, { 0, 0 } }, { 10, 24, { 0, 0 } }, { 10, 25, { 0, 0 } } } } },
        { Anim::State::SHOOTDOWN, { true, 0, { { 0, 5, { 0, 0 } } } } },
        { Anim::State::SHOOTLEFT, { true, 0, { { 0, 12, { -6, 0 } } } } },
        { Anim::State::SHOOTRIGHT, { true, 0, { { 0, 19, { 0, 0 } } } } },
        { Anim::State::SHOOTUP, { true, 0, { { 0, 26, { 0, 0 } } } } },
        { Anim::State::HITFACINGDOWN, { false, 0, { { 10, 46, { -8, -15 } }, { 10, 47, { -8, -15 } } } } },
        { Anim::State::HITFACINGRIGHT, { false, 0, { { 10, 48, { -8, -15 } }, { 10, 49, { -8, -15 } } } } },
        { Anim::State::HITFACINGLEFT, { false, 0, { { 10, 50, { -8, -15 } }, { 10, 51, { -8, -15 } } } } },
        { Anim::State::HITFACINGUP, { false, 0, { { 10, 52, { -8, -15 } }, { 10, 53, { -8, -15 } } } } },
        { Anim::State::DYING,{ false, 0,{ { 10, 27, { -10, 2 } },{ 10, 28, { -10, 2 } },{ 10, 29, { -10, 2 } },{ 10, 30, { -10, 2 } },{ 10, 31, { -10, 2 } },{ 10, 32, { -10, 2 } },{ 10, 33, { -10, 2 } },{ 10, 34, { -10, 2 } },{ 10, 35, { -10, 2 } },{ 10, 36, { -10, 2 } },{ 10, 37, { -10, 2 } },{ 10, 38, { -10, 2 } },{ 10, 39, { -10, 2 } },{ 10, 40, { -10, 2 } },{ 10, 41, { -10, 2 } },{ 10, 42, { -10, 2 } },{ 10, 43, { -10, 2 } },{ 10, 44, { -10, 2 } },{ 10, 45, { -10, 2 } } } } },
        { Anim::State::BULLETUP, { true, 0, { { 0, 55, { 9, -4 } } } } },
        { Anim::State::BULLETDOWN, { true, 0, { { 0, 56, { 9, 24 } } } } },
        { Anim::State::BULLETLEFT, { true, 0, { { 0, 57, { -16, 15 } } } } },
        { Anim::State::BULLETRIGHT, { true, 0, { { 0, 58, { 24, 15 } } } } },
        { Anim::State::BULLETDYINGUP, { false, 0, { { 5, 59, { 5, -10 } }, { 10, 60, { 0, 0 } } } } },
        { Anim::State::BULLETDYINGDOWN, { false, 0, { { 5, 59, { 5, 34 } }, { 10, 60, { 0, 0 } } } } },
        { Anim::State::BULLETDYINGLEFT, { false, 0, { { 5, 59, { -24, 10 } }, { 10, 60, { 0, 0 } } } } },
        { Anim::State::BULLETDYINGRIGHT, { false, 0, { { 5, 59, { 34, 10 } }, { 10, 60, { 0, 0 } } } } }
};
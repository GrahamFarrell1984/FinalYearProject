#pragma once

#include <array>

#include "EntityTypes.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<Frame>;
using AnimData  = std::unordered_map<Entity::State, Animation>;

static const FrameData PlayerSpriteData{ {
         // Origin,                            Source
         { { 0, 0 }, { 0, 0, 26, 42 } },            // Index [0] - Frame for player facing down
         { { 0, 0 }, { 26, 0, 26, 42 } },           // Index [1] - Frame for player moving down
         { { 0, 0 }, { 52, 0, 26, 42 } },           // Index [2] - Frame for player moving down
         { { 0, 0 }, { 78, 0, 26, 42 } },           // Index [3] - Frame for player moving down
         { { 0, 0 }, { 104, 0, 26, 42 } },          // Index [4] - Frame for player moving down
         { { 0, 0 }, { 130, 0, 26, 42 } },          // Index [5] - Frame for player firing gun down
         { { 0, 0 }, { 156, 0, 26, 42 } },          // Index [6] - Frame for player aiming fire extinguisher down

         { { 0, 0 }, { 0, 42, 26, 42 } },           // Index [7] - Frame for player facing left
         { { 0, 0 }, { 26, 42, 26, 42 } },          // Index [8] - Frame for player moving left
         { { 0, 0 }, { 52, 42, 26, 42 } },          // Index [9] - Frame for player moving left
         { { 0, 0 }, { 78, 42, 26, 42 } },          // Index [10] - Frame for player moving left
         { { 0, 0 }, { 104, 42, 26, 42 } },         // Index [11] - Frame for player moving left
         { { -6, 0 }, { 130, 42, 32, 42 } },        // Index [12] - Frame for player firing gun left
         { { -12, 0 }, { 156, 42, 38, 42 } },       // Index [13] - Frame for player aiming fire extinguisher left

         { { 0, 0 }, { 0, 84, 26, 42 } },           // Index [14] - Frame for player facing right
         { { 0, 0 }, { 26, 84, 26, 42 } },          // Index [15] - Frame for player moving right
         { { 0, 0 }, { 52, 84, 26, 42 } },          // Index [16] - Frame for player moving right
         { { 0, 0 }, { 78, 84, 26, 42 } },          // Index [17] - Frame for player moving right
         { { 0, 0 }, { 104, 84, 26, 42 } },         // Index [18] - Frame for player moving right
         { { 0, 0 }, { 130, 84, 32, 42 } },         // Index [19] - Frame for player firing gun right
         { { 0, 0 }, { 156, 84, 38, 42 } },         // Index [20] - Frame for player aiming fire extinguisher right

         { { 0, 0 }, { 0, 126, 26, 42 } },          // Index [21] - Frame for player facing up
         { { 0, 0 }, { 26, 126, 26, 42 } },         // Index [22] - Frame for player moving up
         { { 0, 0 }, { 52, 126, 26, 42 } },         // Index [23] - Frame for player moving up
         { { 0, 0 }, { 78, 126, 26, 42 } },         // Index [24] - Frame for player moving up
         { { 0, 0 }, { 104, 126, 26, 42 } },        // Index [25] - Frame for player moving up
         { { 0, 0 }, { 130, 126, 26, 42 } },        // Index [26] - Frame for player firing gun up
         { { 0, 0 }, { 156, 126, 26, 42 } } }       // Index [27] - Frame for player aiming fire extinguisher up

};

static const AnimData PlayerAnimation{
        // State,                       loop,          loopframe,            frameIdx[]
        { Entity::State::STANDFACINGDOWN, { true, 0, { { 0, 0 } } } },

        { Entity::State::STANDFACINGLEFT,   { true, 0, { { 0, 7 } } } },

        { Entity::State::STANDFACINGRIGHT, { true, 0, { { 0, 14 } } } },

        { Entity::State::STANDFACINGUP,   { true, 0, { { 0, 21 } } } },

        { Entity::State::MOVEDOWN,  { true, 0, { { 10, 1 }, { 10, 2 }, { 10, 3 }, { 10, 4 } } } },

        { Entity::State::MOVELEFT,    { true, 0, { { 10, 8 }, { 10, 9 }, { 10, 10 }, { 10, 11 } } } },

        { Entity::State::MOVERIGHT,    { true, 0, { { 10, 15 }, { 10, 16 }, { 10, 17 }, { 10, 18 } } } },

        { Entity::State::MOVEUP,  { true, 0, { { 10, 22 }, { 10, 23 }, { 10, 24 }, { 10, 25 } } } },

        { Entity::State::SHOOTDOWN,  { true, 0, { { 0, 5 } } } },

        { Entity::State::SHOOTLEFT,  { true, 0, { { 0, 12 } } } },

        { Entity::State::SHOOTRIGHT,  { true, 0, { { 0, 19 } } } },

        { Entity::State::SHOOTUP,  { true, 0, { { 0, 26 } } } },

};
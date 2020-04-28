#pragma once

#include <array>

#include "EntityTypes.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<Frame>;
using AnimData  = std::unordered_map<Entity::State, Animation>;

static const FrameData PlayerSpriteData{ {
     // Origin,                            Source
     { { 0, 0 }, { 0, 0, 26, 25 } },         // Index [0] - Frame for facing player down
     { { 0, 0 }, { 27, 0, 26, 25 } },        // Index [1] - Frame for moving player down
     { { 0, 0 }, { 54, 0, 26, 25 } },        // Index [2] - Frame for moving player down

     { { 0, 0 }, { 0, 26, 26, 25 } },        // Index [3] - Frame for facing player up
     { { 0, 0 }, { 27, 26, 26, 25 } },       // Index [4] - Frame for moving player up
     { { 0, 0 }, { 54, 26, 26, 25 } },       // Index [5] - Frame for moving player up

     { { 0, 0 }, { 0, 52, 26, 26 } },        // Index [6] - Frame for facing player left
     { { 0, 0 }, { 27, 52, 26, 26 } },       // Index [7] - Frame for moving player left
     { { 0, 0 }, { 54, 52, 26, 26 } },       // Index [8] - Frame for moving player left

     { { 0, 0 }, { 0, 79, 26, 26 } },        // Index [9] - Frame for facing player right
     { { 0, 0 }, { 27, 79, 26, 26 } },       // Index [10] - Frame for moving player right
     { { 0, 0 }, { 54, 79, 26, 26 } } }      // Index [11] - Frame for moving player right

};

static const AnimData PlayerAnimation{
    // State,                       loop,            loopframe,            frameIdx[]
    { Entity::State::STANDFACINGDOWN, { true, 0, { { 0, 0 } } } },

    { Entity::State::STANDFACINGUP,   { true, 0, { { 0, 3 } } } },

    { Entity::State::STANDFACINGLEFT, { true, 0, { { 0, 6 } } } },

    { Entity::State::STANDFACINGRIGHT,   { true, 0, { { 0, 11 } } } },

    { Entity::State::MOVEDOWN,  { true, 0, { { 5, 1 }, { 5, 0 }, { 5, 2 }, { 5, 0 } } } },

    { Entity::State::MOVEUP,    { true, 0, { { 5, 4 }, { 5, 3 }, { 5, 5 }, { 5, 3 } } } },

    { Entity::State::MOVELEFT,  { true, 0, { { 5, 7 }, { 5, 6 }, { 5, 8 }, { 5, 6 } } } },

    { Entity::State::MOVERIGHT,    { true, 0, { { 5, 10 }, { 5, 9 }, { 5, 11 }, { 5, 9 } } } }

};
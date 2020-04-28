#pragma once

#include <array>

#include "EntityTypes.h"
#include "Types.h"

// Player Sprite Data - Maybe move to texture data
using FrameData = std::vector<Frame>;
using AnimData  = std::unordered_map<Entity::State, Animation>;

static const FrameData PSD{ {
                                    // Origin,   Source
                                    { { 0, 0 }, { 1, 1, 26, 25 } },     // [0]
                                    { { 0, 0 }, { 28, 1, 26, 25 } },    // [1]
                                    { { 0, 0 }, { 55, 1, 26, 25 } },
                                    { { 0, 0 }, { 1, 27, 25, 25 } },
                                    { { 0, 0 }, { 29, 27, 25, 25 } },
                                    { { 0, 0 }, { 56, 27, 25, 25 } } }
};

static const AnimData PANIM{ // State, loop, loopframe, frameIdx[]
        { Entity::State::STANDDOWN, { true, 0, { { 0, 0 } } } },
        { Entity::State::STANDUP,   { true, 0, { { 0, 3 } } } },
        { Entity::State::MOVEDOWN,  { true, 0, { { 5, 1 }, { 5, 0 }, { 5, 2 }, { 5, 0 } } } },
        { Entity::State::MOVEUP,    { true, 0, { { 5, 3 }, { 5, 4 }, { 5, 3 }, { 5, 5 } } } }
};
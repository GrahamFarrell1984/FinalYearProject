#pragma once

#include <stdint.h>
#include <vector>

struct Point
{
    int32_t x, y;
};

struct Rect
{
    int32_t x, y, w, h;
};

struct Frame
{
    Point origin;
    Rect src;
};

struct AnimFrame
{
    uint8_t tick;
    uint8_t index;
};

struct Animation
{
    bool looping;
    uint8_t loopFrameIndex;
    std::vector<AnimFrame> frames;
};
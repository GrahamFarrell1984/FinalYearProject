#pragma once

struct Point
{
    sf::Int32 x, y;
};

struct Rect
{
    sf::Int32 x, y, w, h;
};

struct Frame
{
    Point origin;
    Rect src;
};

struct AnimFrame
{
    sf::Uint8 tick;
    sf::Uint8 index;
};

struct Animation
{
    bool looping;
    sf::Uint8 loopFrameIndex;
    std::vector<AnimFrame> frames;
};
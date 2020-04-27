#pragma once

#include "Types.h"

// POS              = position on screen
// SRCPOS / SRCRECT = position / Rectangle on Texture

// Texture Menu data
static constexpr auto MAXROW       = 3;
static constexpr auto MAXCOL       = 5;
static constexpr auto OFFSETX      = -128;
static constexpr auto CURSOROFFSET = 64;

static constexpr auto SIZE = 256;

static constexpr Type::Point WSKULLPOS { 384, 256 };
static constexpr Type::Point TEXTPOS   { 384, 512 };
static constexpr Type::Point TITLEPOS  { 128,   0 };
static constexpr Type::Point CONTROLTEXTPOS  { 128,   192 };

static constexpr Type::Point FONTSRCPOS  {   0, 256 };
static constexpr Type::Point FONT1SRCPOS  { 256, 256 };
static constexpr Type::Point SKULL0SRCPOS {   0,   0 };
static constexpr Type::Point SKULL1SRCPOS { 256,   0 };
static constexpr Type::Point SKULL2SRCPOS {   512,   0 };

static constexpr Type::Rect  OPTIONSRCRECT {   0, 1024,  256, 256 };
static constexpr Type::Rect  CURSORSRCRECT{ 512, 256,  32,   32 };
static constexpr Type::Rect  CONTROLSTEXTSRCRECT { 0, 1792, 768, 384 };

// Title Source Rectangles
static constexpr Type::Rect  MAINTITLESRCRECT {   0, 512,  768, 256 };
static constexpr Type::Rect  OPTIONSTITLESRCRECT { 0, 1536, 768, 256 };
static constexpr Type::Rect  PAUSEDTITLESRCRECT { 0, 1280, 768, 256 };
static constexpr Type::Rect  GAMEOVERTITLESRCRECT {   0, 768,  768, 256 };

// Player
static constexpr Type::Rect  PUP    { 42, 0,  20, 44 };
static constexpr Type::Rect  PDOWN  { 0, 0,  20, 44 };
static constexpr Type::Rect  PLEFT  { 21, 0, 20, 44 };
static constexpr Type::Rect  PRIGHT { 63, 0, 20, 44 };
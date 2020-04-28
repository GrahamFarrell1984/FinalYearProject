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

static constexpr Point WSKULLPOS { 384, 256 };
static constexpr Point TEXTPOS   { 384, 512 };
static constexpr Point TITLEPOS  { 128,   0 };
static constexpr Point CONTROLTEXTPOS  { 128,   192 };

static constexpr Point FONTSRCPOS  {   0, 256 };
static constexpr Point FONT1SRCPOS  { 256, 256 };
static constexpr Point SKULL0SRCPOS {   0,   0 };
static constexpr Point SKULL1SRCPOS { 256,   0 };
static constexpr Point SKULL2SRCPOS {   512,   0 };

static constexpr Rect  OPTIONSRCRECT {   0, 1024,  256, 256 };
static constexpr Rect  CURSORSRCRECT{ 512, 256,  32,   32 };
static constexpr Rect  CONTROLSTEXTSRCRECT { 0, 1792, 768, 384 };

// Title Source Rectangles
static constexpr Rect  MAINTITLESRCRECT {   0, 512,  768, 256 };
static constexpr Rect  OPTIONSTITLESRCRECT { 0, 1536, 768, 256 };
static constexpr Rect  PAUSEDTITLESRCRECT { 0, 1280, 768, 256 };
static constexpr Rect  GAMEOVERTITLESRCRECT {   0, 768,  768, 256 };

// Player
static constexpr Rect  PUP    { 42, 0,  20, 44 };
static constexpr Rect  PDOWN  { 0, 0,  20, 44 };
static constexpr Rect  PLEFT  { 21, 0, 20, 44 };
static constexpr Rect  PRIGHT { 63, 0, 20, 44 };

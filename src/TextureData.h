#pragma once

#include "Types.h"

// POS              = position on screen
// SRC_POS / SRC_RECT = position / rectangle on texture

// Texture menu data
static constexpr auto MAXROW       = 3;
static constexpr auto MAXCOL       = 5;
static constexpr auto OFFSETX      = -128;
static constexpr auto CURSOROFFSET = 64;

static constexpr auto SIZE = 256;

static constexpr Rect BIG_HEART_WHITE_BORDER_SRC_RECT {0,1408,32,32 };

static constexpr Rect MEDIUM_GUN_SRC_RECT {128,1408,48,48 };
static constexpr Rect ZOMBIE_HEAD_SRC_RECT {32,1408,48,48 };
static constexpr Rect CHEERLEADER_HEAD_SRC_RECT {80,1408,48,48 };
static constexpr Rect SOLDIER_HEAD_SRC_RECT {272,1406,48,48 };

// Source rectangle of big grey skull on texture
static constexpr Rect BIG_GREY_SKULL_SRC_RECT {0,0,224,256 };

// Position of title in each scene
static constexpr Point TITLE_POS  {128,32 }; // Title widths are 768. Heights are 192

// Source rectangles of main, options, paused and game over titles
static constexpr Rect  MAIN_TITLE_SRC_RECT {0,256,768,192 };
static constexpr Rect  OPTIONS_TITLE_SRC_RECT {0,448,768,192 };
static constexpr Rect  PAUSED_TITLE_SRC_RECT {0,640,768,192 };
static constexpr Rect  GAME_OVER_TITLE_SRC_RECT {0,832,768,192 };

// Position of big white skull in title scene
static constexpr Point BIG_WHITE_SKULL_POS {384,256 };

// Source position of big white skull
static constexpr Point BIG_WHITE_SKULL_SRC_POS {256,0 };

// Source position of transparent skull
static constexpr Point BIG_TRANSPARENT_SKULL_SRC_POS {512,0 };

// Position of menu in title scene
static constexpr Point MAIN_TITLE_MENU_POS {384,544 };

// Position of menu in options and game over scenes
static constexpr Point OPTIONS_AND_GAME_OVER_MENU_POS {384,608 };

// Position of menu in paused scene
static constexpr Point PAUSED_MENU_POS {384,544 };

// Source rectangles of main, options, paused and game over menus
static constexpr Rect  MAIN_TITLE_MENU_SRC_RECT {0,1024,256,192 };
static constexpr Rect  OPTIONS_AND_GAME_OVER_MENU_SRC_RECT {0,1280,256,120 };
static constexpr Rect  PAUSED_MENU_SRC_RECT {0,1216,256,184 };

// Source rectangle of small white skull used for cursor
static constexpr Rect  CURSOR_SRC_RECT {224,0,32,32 };

// Position of game controls text used in options scene
static constexpr Point GAME_CONTROLS_TEXT_POS {256,192 };

// Source rectangle of game controls text used in options scene
static constexpr Rect  GAME_CONTROLS_TEXT_SRC_RECT {256,1024,512,376 };

// Player
static constexpr Rect  PUP    {42,0,20,44 };
static constexpr Rect  PDOWN  { 0,0,20,44 };
static constexpr Rect  PLEFT  {21,0,20,44 };
static constexpr Rect  PRIGHT {63,0,20,44 };

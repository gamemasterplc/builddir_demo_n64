#pragma once

//Required includes
#include <ultra64.h>
#include <build_constants.h>

//Defines for background tile size
#define BG_TILE_WIDTH 32
#define BG_TILE_HEIGHT 32

//Expose one of two background tile textures
#if USE_PLC_BG
extern u16 bg_plc[BG_TILE_WIDTH*BG_TILE_HEIGHT];
#else
extern u16 bg_64[BG_TILE_WIDTH*BG_TILE_HEIGHT];
#endif
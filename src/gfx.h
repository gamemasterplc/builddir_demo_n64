#pragma once

//Required includes
#include <ultra64.h>

//Defines
#define CFB_COUNT 3
#define GLIST_LEN 2048

//Functions
void GfxInit();
void GfxStartFrame();
void GfxClear(u8 r, u8 g, u8 b);
void GfxEndFrame();

//Extern variables
extern Gfx *glistp;
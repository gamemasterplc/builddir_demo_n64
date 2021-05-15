#include "bg.h"

//Define this background tile if USE_PLC_BG is defined

#if USE_PLC_BG

u16 bg_plc[BG_TILE_WIDTH*BG_TILE_HEIGHT] __attribute__((aligned(8))) = {
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0295, 0x056B, 0x0631, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0631, 0x056B, 0x0295, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 0x0001, 
    0x0001, 0x00C7, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x00C7, 0x0001, 
    0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 
    0x0001, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x1F39, 0x1F39, 0x1F39, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x2EB5, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x26F7, 0x3673, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0001, 
    0x0295, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xF801, 0xF801, 0xF801, 0xE0C7, 0x64E7, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x64E7, 0xF043, 0xF801, 0xF801, 0xE885, 0x83DF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0295, 
    0x056B, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xD909, 0x07FF, 0x0FBD, 0x7C21, 0xF801, 0x4DAD, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x5D29, 0xF801, 0x7C21, 0x177B, 0x07FF, 0x556B, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x056B, 
    0x0631, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xD909, 0x07FF, 0x07FF, 0x07FF, 0xF043, 0x7C21, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xD909, 0x935B, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0631, 
    0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xD909, 0x07FF, 0x07FF, 0x07FF, 0xE885, 0x7463, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x3673, 0xF801, 0x2EB5, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 
    0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xD909, 0x07FF, 0x177B, 0x7C21, 0xF801, 0x3E31, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x5D29, 0xF801, 0x0FBD, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 
    0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xAA95, 0xF801, 0xF801, 0xF801, 0xD14B, 0x556B, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x5D29, 0xF801, 0x0FBD, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 
    0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xA2D7, 0xD14B, 0x3E31, 0x1F39, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x3E31, 0xF801, 0x2EB5, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 
    0x0631, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xA2D7, 0xC98D, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0FBD, 0xE0C7, 0x935B, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0631, 
    0x056B, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xA2D7, 0xC1CF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0x3673, 0x3673, 0x3673, 0x3673, 0x07FF, 0x7463, 0xF801, 0x7C21, 0x2EB5, 0x1F39, 0x64E7, 0xF801, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x056B, 
    0x0295, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0xA2D7, 0xC1CF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x64E7, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x07FF, 0x07FF, 0x64E7, 0xD909, 0xF801, 0xF801, 0xD14B, 0x6CA5, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0295, 
    0x0001, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0FBD, 0x0FBD, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x177B, 0x177B, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0001, 
    0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 
    0x0001, 0x00C7, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x00C7, 0x0001, 
    0x0001, 0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0739, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0739, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x00C7, 0x0463, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0463, 0x00C7, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0295, 0x056B, 0x0631, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0631, 0x056B, 0x0295, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
};

#endif
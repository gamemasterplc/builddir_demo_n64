#pragma once

#define USE_PLC_BG 1

#define CFB_32_BIT 0

#define SCREEN_WD 424
#define SCREEN_HT 240

#if CFB_32_BIT
#define CFB_SIZE (((SCREEN_WD*SCREEN_HT*4)+63) & 0xFFFFFFC0)
#else
#define CFB_SIZE (((SCREEN_WD*SCREEN_HT*2)+63) & 0xFFFFFFC0)
#endif
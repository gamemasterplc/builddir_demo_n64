#include <build_constants.h>
#include "gfx.h"
#include "bg.h"
#include "main.h"
#include "stage.h"

//Declare variables
static float scroll_x, scroll_y;
static float zoom;

//Forward declarations
static void DrawBG();

void StageInit()
{
	scroll_x = scroll_y = 0;
	zoom = 1.0f;
}

void StageUpdate()
{
	float zoom_change = 0;
	nuContDataGetExAll(contdata);
	//Calculate zoom change from Z and R triggers
	if(contdata[0].button & Z_TRIG) {
		//Zoom out
		zoom_change -= ZOOM_SPEED*zoom;
	}
	if(contdata[0].button & R_TRIG) {
		//Zoom in
		zoom_change += ZOOM_SPEED*zoom;
	}
	//Apply zoom change
	zoom += zoom_change;
	//Clamp zoom
	if(zoom < ZOOM_MIN) {
		zoom = ZOOM_MIN;
	}
	if(zoom > ZOOM_MAX) {
		zoom = ZOOM_MAX;
	}
	//Scroll background with analog stick
	if(contdata[0].stick_x > SCROLL_DEADZONE || contdata[0].stick_x < -SCROLL_DEADZONE) {
		scroll_x += contdata[0].stick_x*SCROLL_SPEED;
	}
	if(contdata[0].stick_y > SCROLL_DEADZONE || contdata[0].stick_y < -SCROLL_DEADZONE) {
		scroll_y -= contdata[0].stick_y*SCROLL_SPEED;
	}
}

void StageDraw()
{
	GfxStartFrame();
	GfxClear(0, 0, 0);
	DrawBG();
	GfxEndFrame();
}

static Gfx bg_init[] = {
	//Initialize background render settings
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF),
	gsDPSetDepthSource(G_ZS_PIXEL),
	gsDPSetTexturePersp(G_TP_NONE),
	gsDPSetPrimColor(0 ,0, 255, 255, 255, 255),
	gsDPSetCombineMode(G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM),
	gsDPSetTextureLUT(G_TT_NONE),
	//Load background texture
	#if USE_PLC_BG
	gsDPLoadTextureBlock(bg_plc, G_IM_FMT_RGBA, G_IM_SIZ_16b, BG_TILE_WIDTH, BG_TILE_HEIGHT, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
	#else
	gsDPLoadTextureBlock(bg_64, G_IM_FMT_RGBA, G_IM_SIZ_16b, BG_TILE_WIDTH, BG_TILE_HEIGHT, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
	#endif
	//Return to caller
	gsSPEndDisplayList(),
};
	
static void DrawBG()
{
	float texcoord_x, texcoord_y;
	//Calculate texture pixel offset for zoom from center
	texcoord_x = scroll_x-((SCREEN_WD/2)/zoom);
	texcoord_y = scroll_y-((SCREEN_HT/2)/zoom);
	gSPDisplayList(glistp++, bg_init);
	//Render background
    gSPTextureRectangle(glistp++, 0, 0, SCREEN_WD << 2, SCREEN_HT << 2, G_TX_RENDERTILE,
		texcoord_x*32.0f, texcoord_y*32.0f, 1024.0f/zoom, 1024.0f/zoom);
	gDPPipeSync(glistp++);
}
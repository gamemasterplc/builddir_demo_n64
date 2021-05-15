//Required includes
#include <nusys.h>
#include <build_constants.h>
#include <string.h>
#include "gfx.h"

//Static variable declarations
static void *cfb_base;
static void *cfb_list[CFB_COUNT];
static Gfx glist[GLIST_LEN];

//Static data declarations
static Vp viewport = {
  SCREEN_WD * 2, SCREEN_HT * 2, G_MAXZ / 2, 0,
  SCREEN_WD * 2, SCREEN_HT * 2, G_MAXZ / 2, 0,
};

// Initialize the RSP
static Gfx rspinit_dl[] = {
	gsSPViewport(&viewport),
	gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH |
		G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD),
	gsSPTexture(0, 0, 0, 0, G_OFF),
	gsSPEndDisplayList(),
};

// Initialize the RDP
static Gfx rdpinit_dl[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPPipelineMode(G_PM_1PRIMITIVE),
	gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WD, SCREEN_HT),
	gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
	gsDPSetCombineKey(G_CK_NONE),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
	gsDPSetColorDither(G_CD_DISABLE),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsDPSetTextureConvert(G_TC_FILT),
	gsDPSetTexturePersp(G_TP_NONE),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

//Global variables
Gfx *glistp;

//Required prototypes
static void SetCFBPointers();
static void SetVIModeResolution(OSViMode *mode, int width, int height);
static void InitVIMode();

void GfxInit()
{
	//Initialize nusys graphics
	nuGfxInit();
	//Resize nusys framebuffer
	InitVIMode();
	SetCFBPointers();
	//Turn on screen
	nuGfxDisplayOn();
}

void GfxStartFrame()
{
	glistp = glist;
	//Reset segment pointers
	gSPSegment(glistp++, 0, 0);
	//RCP Initialization
	gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rspinit_dl));
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rdpinit_dl));
}

void GfxClear(u8 r, u8 g, u8 b)
{
    gDPPipeSync(glistp++);
	gDPSetDepthImage(glistp++, nuGfxZBuffer);
	//Clear Z Buffer
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, nuGfxZBuffer);
    gDPSetFillColor(glistp++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);
	//Clear Frame Buffer
	#if CFB_32_BIT
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_32b, SCREEN_WD, nuGfxCfb_ptr);
    gDPSetFillColor(glistp++, (r << 24)|(g << 16)|(b << 8)|0xFF);
	#else
	gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, nuGfxCfb_ptr);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
	#endif
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);
}

void GfxEndFrame()
{
	//End the Display List
	gDPFullSync(glistp++);
	gSPEndDisplayList(glistp++);
	//Send GFX Task
	nuGfxTaskStart(glist, (u32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX2, NU_SC_SWAPBUFFER);
}

static void SetCFBPointers()
{
	//Put CFBs at End of RAM
	cfb_base = OS_PHYSICAL_TO_K0(osMemSize-(CFB_SIZE*CFB_COUNT));
	for(int i=0; i<CFB_COUNT; i++) {
		cfb_list[i] = ((u8 *)cfb_base)+(CFB_SIZE*i);
		//Fill Framebuffer with Black
		#if CFB_32_BIT
		for(int j=0; j<CFB_SIZE/4; j++) {
			((u8 *)cfb_list[i])[j*4] = 0x00;
			((u8 *)cfb_list[i])[(j*4)+1] = 0x00;
			((u8 *)cfb_list[i])[(j*4)+2] = 0x00;
			((u8 *)cfb_list[i])[(j*4)+3] = 0xFF;
		}
		#else
		for(int j=0; j<CFB_SIZE/2; j++) {
			((u8 *)cfb_list[i])[j*2] = 0x00;
			((u8 *)cfb_list[i])[(j*2)+1] = 0x01;
		}
		#endif
	}
	//Notify nusys of new CFB list
	nuGfxSetCfb((u16 **)cfb_list, CFB_COUNT);
}

static void InitVIMode()
{
	static OSViMode vi_mode; //Must be static to stay in RAM
	#if CFB_32_BIT
	//Copy 32-bit VI mode
	switch(osTvType) {
		case OS_TV_PAL:
			memcpy(&vi_mode, &osViModeFpalLpn2, sizeof(OSViMode));
			break;
			
		case OS_TV_NTSC:
			memcpy(&vi_mode, &osViModeNtscLpn2, sizeof(OSViMode));
			break;
			
		case OS_TV_MPAL:
			memcpy(&vi_mode, &osViModeMpalLpn2, sizeof(OSViMode));
			break;
	}
	#else
	//Copy 16-bit VI mode
	switch(osTvType) {
		case OS_TV_PAL:
			memcpy(&vi_mode, &osViModeFpalLpn1, sizeof(OSViMode));
			break;
			
		case OS_TV_NTSC:
			memcpy(&vi_mode, &osViModeNtscLpn1, sizeof(OSViMode));
			break;
			
		case OS_TV_MPAL:
			memcpy(&vi_mode, &osViModeMpalLpn1, sizeof(OSViMode));
			break;
	}
	#endif
	//Initialize VI mode
	SetVIModeResolution(&vi_mode, SCREEN_WD, SCREEN_HT);
	osViSetMode(&vi_mode);
	osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
	//Scale screen for PAL
	if(osTvType == OS_TV_PAL) {
		osViSetYScale(0.833);
	}
}

static void SetVIModeResolution(OSViMode *mode, int width, int height)
{
	//Initialize VI Horizontal Settings
	mode->comRegs.width = width;
	mode->comRegs.xScale = (width*512)/320;
	if(height > 240) {
		mode->comRegs.ctrl |= 0x40; //Forces Serrate Bit On
		//Calculate Interlaced Framebuffer Origin
		//Odd Fields are 1 Line Below Even Fields
		#if CFB_32_BIT
		mode->fldRegs[0].origin = width*4;
		mode->fldRegs[1].origin = width*8;
		#else
		mode->fldRegs[0].origin = width*2;
		mode->fldRegs[1].origin = width*4;
		#endif
		//Use Correct Interlaced Y Scale
		mode->fldRegs[0].yScale = 0x2000000|((height*1024)/240);
		mode->fldRegs[1].yScale = 0x2000000|((height*1024)/240);
		//Correct Field Vertical Start
		mode->fldRegs[0].vStart = mode->fldRegs[1].vStart-0x20002;
	} else {
		//Calculate Non-Interlaced Framebuffer Origin
		#if CFB_32_BIT
		mode->fldRegs[1].origin = mode->fldRegs[0].origin = width*4;
		#else
		mode->fldRegs[1].origin = mode->fldRegs[0].origin = width*2;
		#endif
		//Calculate Y Scale
		mode->fldRegs[0].yScale = ((height*1024)/240);
		mode->fldRegs[1].yScale = ((height*1024)/240);
		//Correct Field Vertical Start
		mode->fldRegs[0].vStart = mode->fldRegs[1].vStart;
	}
}
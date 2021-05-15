#include <nusys.h>
#include "gfx.h"
#include "stage.h"

//Forward declare nusys graphics function
static void VSyncFunc(u32 task_count);

//Define controller data
NUContData contdata[NU_CONT_MAXCONTROLLERS];

void mainproc()
{
	//Initialize
	nuContInit();
	GfxInit();
	nuGfxFuncSet((NUGfxFunc)VSyncFunc);
	StageInit();
	//Suspend this thread forever
	while(1);
}

static void VSyncFunc(u32 task_count)
{
	//Only execute if no tasks remain
	if(task_count == 0) {
		StageUpdate();
		StageDraw();
	}
}
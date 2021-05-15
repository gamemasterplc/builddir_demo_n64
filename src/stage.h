#pragma once

#define ZOOM_MIN 0.25f
#define ZOOM_MAX 4.0f
#define ZOOM_SPEED 0.01f
#define SCROLL_DEADZONE 16
#define SCROLL_SPEED (1/64.0f)

void StageInit();
void StageUpdate();
void StageDraw();
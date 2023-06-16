/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102

	SAMPLE 05 - SCENCE MANAGER

	This sample illustrates how to:

		1/ Implement a scence manager
		2/ Load scene from "database", add/edit/remove scene without changing code
		3/ Dynamically move between scenes without hardcode logic

================================================================ */
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Supper Mario Bros 3"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(181, 235, 242)
#define SCREEN_WIDTH 334 
#define SCREEN_HEIGHT 292

#define MAX_FRAME_RATE 120

CGame* game;
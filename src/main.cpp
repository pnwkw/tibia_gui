#include <windows.h>
#include <string>
#include "hook_functions.h"
#include "gui_class.h"
#include "structs.h"
#include "static_class_functions.h"

#ifdef TIBIA_8_6_1
#define CREATE_NEW_INSTANCE_FUNC_ADDR 0x56BDF2
#define DO_SEND_CANCEL_FUNC_ADDR 0x53FE40
#define PRINT_TEXT_FUNC_ADDR 0x4B0F70
#endif

#ifdef TIBIA_8_7_0
#define CREATE_NEW_INSTANCE_FUNC_ADDR 0x571DA3
#endif

typedef void *__cdecl _tCreateNewInstance(DWORD type);
_tCreateNewInstance *tCreateNewInstance = (_tCreateNewInstance *)CREATE_NEW_INSTANCE_FUNC_ADDR;

typedef void _tDoSendCancel(char *text, int type);
static _tDoSendCancel *tDoSendCancel = (_tDoSendCancel *)DO_SEND_CANCEL_FUNC_ADDR;

typedef void _PrintText(int nSurface, int nX, int nY, int nFont, int nRed, int nGreen, int nBlue, char *lpText, int nAlign);
static _PrintText *PrintText = (_PrintText *)PRINT_TEXT_FUNC_ADDR;

void *_cdecl operator new(size_t cbSize)
{
  void *p = tCreateNewInstance(cbSize);
  return p;
}

#define MAIN_WINDOW_ADDR 0x6723F0

// 004905F2  |. E8 E9A4FEFF    CALL Tibia.0047AAE0                      ; \Tibia.0047AAE0
// BIG BUTTON

GUIMainWindow *Main = (GUIMainWindow *)*(int *)MAIN_WINDOW_ADDR;
GUIContainerWindow *containers = NULL;
GUIEvent *event = NULL;

void CreateBotWindow()
{
  int height = 50;
  GUISkillBody *body = new GUISkillBody();

  GUIIconBox *icon = new GUIIconBox(0x96);
  GUIContainerBox *content_box = new GUIContainerBox(30, body, 1, 1);

  GUINameBox *name = new GUINameBox(1, 0x90, 0x90, 0x90, 0, "Bot Menu");
  GUIMiniButtonBox *minimise = new GUIMiniButtonBox(0, 0, 0x92, 0x93, content_box, 9, "Maximise or minimise window", 0);
  GUIMiniButtonBox *close = new GUIMiniButtonBox(0, 0, 0x90, 0x91, content_box, 0xA, "Close this window", 0);

  containers->RegisterChild(content_box);
  containers->ShowChild(content_box, 0, 0, containers->width, height);

  content_box->RegisterCloseButton(close);
  content_box->RegisterMinimiseButton(minimise);
  content_box->RegisterIcon(icon);
  content_box->RegisterNamePlate(name);

  GUICheckBox *checkbox = new GUICheckBox("Enable ManaBar", event, 0x21);
  body->RegisterChild(checkbox);
  body->SetChildPos(checkbox, 50, 20);

  body->ShowChild(checkbox, 4, 2, 120, 20);
}

// 004C19B9  |. FF52 70        CALL DWORD PTR DS:[EDX+70]

bool patch = true;

void PrintFpsPatched(int nSurface, int nX, int nY, int nFont, int nRed, int nGreen, int nBlue, char *lpText, int nAlign)
{
  if (Main != NULL)
  {
    containers = (GUIContainerWindow *)Main->containersWindow;
    if (containers != NULL)
    {
      if (patch)
      {
        CreateBotWindow();
        Main->onGUIResize();
        patch = false;
      }
    }
  }

  return;
}

// HP Bar
#define CURRENT_HP_BAR_DRAWING_CREATURE (0x12E108 - 0x30)

#define EXPERIENCE 0x637C4C
#define SELFID (EXPERIENCE + 12)
#define SELFMANA (EXPERIENCE - 20)
#define SELFMAXMANA (EXPERIENCE - 24)

// HP Bar patches
#define PRINT_NAME_PATCH_ADDR 0x4F14F3

#define PLACE_BLACK_BAR_CALL 0x4F1405
#define FIX_BLACK_BAR_CALL 0x4F140B

#define PLACE_COLOR_BAR_CALL 0x4F14B3
#define FIX_COLOR_BAR_CALL 0x4F14B9

void PrintNamePatched(int nSurface, int nX, int nY, int nFont, int nRed, int nGreen, int nBlue, char *lpText, int nAlign)
{
  int selfID = *(int *)SELFID;

  int creatureID = *(int *)(lpText - 4);

  if (selfID == creatureID && event->clicked)
  {
    PrintText(nSurface, nX, nY - 6, nFont, nRed, nGreen, nBlue, lpText, nAlign); // print name higher than usual (make some space for mana bar)
    return;
  }
  PrintText(nSurface, nX, nY, nFont, nRed, nGreen, nBlue, lpText, nAlign); // print name normally
}

// Black rectangle: W 27, H 4

void __stdcall DrawBlackBarPatched(int nSurface, int X, int Y, int W, int H, int nRed, int nGreen, int nBlue)
{
  __asm {mov ECX, DWORD PTR SS:[EBP-130]}

  int selfID = *(int *)SELFID;

  int creaturePointer = *(int *)CURRENT_HP_BAR_DRAWING_CREATURE;
  int creatureID = *(int *)(creaturePointer);

  // Draw two black backgrounds if the character is ours, otherwise just one
  if (selfID == creatureID && event->clicked)
    DrawRect(nSurface, X, Y - 6, W, H, nRed, nGreen, nBlue);

  DrawRect(nSurface, X, Y, W, H, nRed, nGreen, nBlue);
}

#define COL_BLUE_80 39, 64, 139
#define COL_BLUE_60 58, 95, 205
#define COL_BLUE_40 72, 118, 255
#define COL_BLUE_20 100, 149, 237

// Color rectangle: W 25, H 2

void __stdcall DrawColorBarPatched(int nSurface, int X, int Y, int W, int H, int nRed, int nGreen, int nBlue)
{
  __asm {MOV ECX, DWORD PTR SS:[EBP - 0x19C]}

  int selfID = *(int *)SELFID; // Again...

  int creaturePointer = *(int *)CURRENT_HP_BAR_DRAWING_CREATURE;
  int creatureID = *(int *)(creaturePointer);

  DrawRect(nSurface, X, Y, W, H, nRed, nGreen, nBlue); // draw hp bar normally

  if (selfID == creatureID && event->clicked)
  {
    DrawRect(nSurface, X, Y, W, H, 0, 0, 0); //"erase" what call above drew

    DrawRect(nSurface, X, Y - 6, W, H, nRed, nGreen, nBlue); // draw hp bar higher then usual

    int currentMana = *(int *)SELFMANA;
    int maxMana = *(int *)SELFMAXMANA;

    int width = (25 * currentMana) / maxMana;    // Full bar is 25 pixels long, simple calculation
    int percent = (100 * currentMana) / maxMana; // Only for visual effect. Bar changes color when your mana drops under specified percent.

    // Draw mana bar
    if (percent >= 80)
      DrawRect(nSurface, X, Y, width, H, COL_BLUE_80);
    else if (percent >= 60 && percent < 80)
      DrawRect(nSurface, X, Y, width, H, COL_BLUE_60);
    else if (percent >= 40 && percent < 60)
      DrawRect(nSurface, X, Y, width, H, COL_BLUE_40);
    else if (percent < 40)
      DrawRect(nSurface, X, Y, width, H, COL_BLUE_20);
  }
}

void ManaBarHooks()
{
  HookCall(PRINT_NAME_PATCH_ADDR, (DWORD)&PrintNamePatched);

  HookCall(PLACE_BLACK_BAR_CALL, (DWORD)&DrawBlackBarPatched);
  Nop(FIX_BLACK_BAR_CALL - 1, 4);

  HookCall(PLACE_COLOR_BAR_CALL, (DWORD)&DrawColorBarPatched);
  Nop(FIX_COLOR_BAR_CALL - 1, 4);
}

#define NOP_FPS_PATCH 0x4586B4
#define PRINT_FPS_FUNC_PATCH 0x458778

extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch (dwReason)
  {
  case DLL_PROCESS_ATTACH:
  {
    HWND hWnd = FindWindow("TibiaClient", "Tibia");
    DWORD dwPid;
    GetWindowThreadProcessId(hWnd, &dwPid);

    if (GetCurrentProcessId() == dwPid)
    {
      event = new GUIEvent();

      HookCall(PRINT_FPS_FUNC_PATCH, (DWORD)&PrintFpsPatched);
      Nop(NOP_FPS_PATCH, 6);

      ManaBarHooks();
    }
  }
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return 1;
}

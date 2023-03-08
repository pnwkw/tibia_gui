#include "static_class_functions.h"

#ifdef TIBIA_8_6_1

DWORD DRAW_GUI_ITEM_FUNC_ADDR = 0x4BCA40;
DWORD SHOW_GUI_ITEM_FUNC_ADDR = 0x4BFEF0;
DWORD SET_CHILD_POS_FUNC_ADDR = 0x4C03D0;

DWORD CREATE_EDITBOX_FUNC_ADDR = 0x46D0F0;
DWORD CREATE_NAMEBOX_FUNC_ADDR = 0x479890;
DWORD CREATE_MINIBUTTONBOX_FUNC_ADDR = 0x47A760;
DWORD CREATE_CONTAINERBOX_FUNC_ADDR = 0x4A3FD0;
DWORD CREATE_CONTAINERBODY_FUNC_ADDR = 0x448D20; // was 0x444E60, Skill body
DWORD CREATE_ICONBOX_FUNC_ADDR = 0x4696F0;
DWORD CREATE_CHECKBOX_FUNC_ADDR = 0x47B410;
DWORD CREATE_BUTTONBOX_FUNC_ADDR = 0x47AAE0;
DWORD CREATE_BODY_FUNC_ADDR = 0x4BC7C0;
DWORD CREATE_BODY2_FUNC_ADDR = 0x4B3630;
DWORD CREATE_SCROLLER_FUNC_ADDR = 0x47DD40;

DWORD WINDOW_REG_CLOSE = 0x4A5F90;
DWORD WINDOW_REG_MINIMISE = 0x4A6180;
DWORD WINDOW_REG_ICON = 0x4A6370;
DWORD WINDOW_REG_NAME = 0x4A6580;

#endif

#ifdef TIBIA_8_7_0

int DRAW_GUI_ITEM_FUNC_ADDR = 0x4BCA40;
int SHOW_GUI_ITEM_FUNC_ADDR = 0x4BFEF0;
int SET_CHILD_POS_FUNC_ADDR = 0x4C03D0;

int CREATE_EDITBOX_FUNC_ADDR = 0x46D0F0;
int CREATE_NAMEBOX_FUNC_ADDR = 0x47D0A0;       //
int CREATE_MINIBUTTONBOX_FUNC_ADDR = 0x47DF70; //
int CREATE_CONTAINERBOX_FUNC_ADDR = 0x4A7DB0;  //
int CREATE_CONTAINERBODY_FUNC_ADDR = 0x448D20; // was 0x444E60, Skill body
int CREATE_ICONBOX_FUNC_ADDR = 0x46CEF0;       //
int CREATE_CHECKBOX_FUNC_ADDR = 0x47B410;
int CREATE_BUTTONBOX_FUNC_ADDR = 0x47AAE0;
int CREATE_BODY_FUNC_ADDR = 0x4BC7C0;
int CREATE_BODY2_FUNC_ADDR = 0x4B3630;
int CREATE_SCROLLER_FUNC_ADDR = 0x47DD40;

int WINDOW_REG_CLOSE = 0x4A9D70;    //
int WINDOW_REG_MINIMISE = 0x4A9F60; //
int WINDOW_REG_ICON = 0x4AA150;     //
int WINDOW_REG_NAME = 0x4AA360;     //

#endif

__declspec(naked) void _cdecl draw_gui_item(void *parent, void *instance)
{
    __asm {
        push ebp
        mov ebp, esp
        push ecx
        push dword ptr[ebp + 12]
        mov ecx, dword ptr[ebp + 8]
        mov eax, DRAW_GUI_ITEM_FUNC_ADDR
        call eax
        pop ecx
        pop ebp
        ret
    }
}

__declspec(naked) void _cdecl show_gui_item(void *parent, void *instance, DWORD x, DWORD y, DWORD width, DWORD height)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 28]
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, SHOW_GUI_ITEM_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) int _cdecl create_editbox(void *instance, DWORD max_len, DWORD start_len)
{
    __asm {
        push ebp
        mov ebp, esp
        push ecx
        push dword ptr[ebp + 16]
        push dword ptr[ebp + 12]
        mov ecx, dword ptr[ebp + 8]
        mov eax, CREATE_EDITBOX_FUNC_ADDR
        call eax
        pop ecx
        pop ebp
        ret
    }
}

__declspec(naked) void _cdecl create_namebox(void *instance, int font, int nRed, int nBlue, int nGreen, int algin, char *name)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 32]
        push DWORD PTR[EBP + 28]
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_NAMEBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_iconbox(void *instance, int icon)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_ICONBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_containerbox(void *instance, int identifier, void *body, int resizeable, int arg4)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_CONTAINERBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_checkbox(void *instance, char *label, int arg2, int arg3)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_CHECKBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_minibuttonbox(void *instance, int unk1, int unk2, int image_notclicked, int image_clicked, int unk5, int unk6, char *description, int unk8)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 40]
        push DWORD PTR[EBP + 36]
        push DWORD PTR[EBP + 32]
        push DWORD PTR[EBP + 28]
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_MINIBUTTONBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_containerbody(void *instance)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_CONTAINERBODY_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_buttonbox(void *instance, int arg1, int arg2, char *label, int arg3, int arg4, void *component, int arg5, char *description)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 40]
        push DWORD PTR[EBP + 36]
        push DWORD PTR[EBP + 32]
        push DWORD PTR[EBP + 28]
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_BUTTONBOX_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_body(void *instance, int arg1, int arg2)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_BODY_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_body2(void *instance)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_BODY2_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl create_scroller(void *instance, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 44]
        push DWORD PTR[EBP + 40]
        push DWORD PTR[EBP + 36]
        push DWORD PTR[EBP + 32]
        push DWORD PTR[EBP + 28]
        push DWORD PTR[EBP + 24]
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, CREATE_SCROLLER_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl window_reg_close(void *instance, void *arg)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, WINDOW_REG_CLOSE
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl window_reg_minimise(void *instance, void *arg)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, WINDOW_REG_MINIMISE
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl window_reg_icon(void *instance, void *arg)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, WINDOW_REG_ICON
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl window_reg_name(void *instance, void *arg)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, WINDOW_REG_NAME
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

__declspec(naked) void _cdecl set_child_pos(void *instance, void *arg, int arg1, int arg2)
{
    __asm {
        push EBP
        mov EBP, ESP
        push ECX
        push DWORD PTR[EBP + 20]
        push DWORD PTR[EBP + 16]
        push DWORD PTR[EBP + 12]
        mov ECX, DWORD PTR[EBP + 8]
        mov EAX, SET_CHILD_POS_FUNC_ADDR
        call EAX
        pop ECX
        pop EBP
        ret
    }
}

#define DRAW_RECT_DX5_FUNC_ADDR 0x51FE10
#define DRAW_RECT_DX9_FUNC_ADDR 0x529350
#define DRAW_RECT_OGL_FUNC_ADDR 0x5372F0
#define PREPARE_DRAW_RECT_FUNC_ADDR 0x51DE40
#define GRAPHIC_ENGINE_MODE_ADDR 0x7BF130

DWORD DrawRectAddress;

#define DX5 0
#define OGL 1
#define DX9 2

void GetActualGraphicEngine()
{
    int actualGraphicEngine = *(int *)GRAPHIC_ENGINE_MODE_ADDR;
    switch (actualGraphicEngine)
    {
    case DX5:
    {
        DrawRectAddress = DRAW_RECT_DX5_FUNC_ADDR;
    }
    break;

    case OGL:
    {
        DrawRectAddress = DRAW_RECT_OGL_FUNC_ADDR;
    }
    break;

    case DX9:
    {
        DrawRectAddress = DRAW_RECT_DX9_FUNC_ADDR;
    }
    break;
    }
}

DWORD PrepareDrawRectAddress = PREPARE_DRAW_RECT_FUNC_ADDR;

__declspec(naked) void DrawRectangle(int nSurface, int X, int Y, int W, int H, int nRed, int nGreen, int nBlue)
{
    __asm {
           mov EAX, PrepareDrawRectAddress
           call EAX
           mov ECX, EAX

           push nBlue
           push nGreen
           push nRed
           push H
           push W
           push Y
           push X
           push nSurface
           mov EAX, DrawRectAddress
           call EAX
           ret
    }
}

void DrawRect(int nSurface, int X, int Y, int W, int H, int nRed, int nGreen, int nBlue)
{
    GetActualGraphicEngine();
    DrawRectangle(nSurface, X, Y, W, H, nRed, nGreen, nBlue);
}

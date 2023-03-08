#ifndef STATIC_CLASS_FUNCS
#define STATIC_CLASS_FUNCS

#include <windows.h>

void _cdecl draw_gui_item(void *parent, void *instance);
void _cdecl show_gui_item(void *parent, void *instance, DWORD x, DWORD y, DWORD width, DWORD height);
void _cdecl set_child_pos(void *instance, void *arg, int arg1, int arg2);

int _cdecl create_editbox(void *instance, DWORD max_len, DWORD start_len);
void _cdecl create_namebox(void *instance, int font, int nRed, int nBlue, int nGreen, int algin, char *name);
void _cdecl create_iconbox(void *instance, int icon);
void _cdecl create_containerbox(void *instance, int identifier, void *body, int resizeable, int arg4);
void _cdecl create_checkbox(void *instance, char *label, int arg2, int arg3);
void _cdecl create_minibuttonbox(void *instance, int unk1, int unk2, int image_notclicked, int image_clicked, int unk5, int unk6, char *description, int unk8);
void _cdecl create_containerbody(void *instance);
void _cdecl create_buttonbox(void *instance, int arg1, int arg2, char *label, int arg3, int arg4, void *component, int arg5, char *description);
void _cdecl create_body(void *instance, int arg1, int arg2);
void _cdecl create_body2(void *instance);
void _cdecl create_scroller(void *instance, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);
void _cdecl window_reg_close(void *instance, void *arg);
void _cdecl window_reg_minimise(void *instance, void *arg);
void _cdecl window_reg_icon(void *instance, void *arg);
void _cdecl window_reg_name(void *instance, void *arg);

void DrawRect(int nSurface, int X, int Y, int W, int H, int nRed, int nGreen, int nBlue);

#endif

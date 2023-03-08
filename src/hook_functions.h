#ifndef HOOK_FUNCTIONS
#define HOOK_FUNCTONS

#include <windows.h>

void Nop(DWORD dwAddress, int size);
DWORD HookCall(DWORD dwAddress, DWORD dwFunction);

#endif
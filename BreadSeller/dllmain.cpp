#include "pch.h"
#include "BreadSeller.h"

// Entry point for the DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {

    HANDLE thread = nullptr;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        
        thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)hookFunction, NULL, 0, NULL);
    }
    case DLL_PROCESS_DETACH:
        thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)unHookFunction, NULL, 0, NULL);
        break;
    }
    return TRUE;
}
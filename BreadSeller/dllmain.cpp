#include "pch.h"
#include "BreadSellerDll.h"

// Entry point for the DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {

    HANDLE thread = nullptr;
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
        {
            thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)test, NULL, 0, NULL);
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
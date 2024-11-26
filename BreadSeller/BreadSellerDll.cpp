#include "pch.h"
#include "framework.h"
#include "BreadSellerDll.h"

BOOL hookFunction() {

    std::cout << "helo";
    return TRUE;
    //HMODULE hModule = nullptr;
    //DisableThreadLibraryCalls(hModule);

    //// Initialize MinHook
    //if (MH_Initialize() != MH_OK) {
    //    std::cerr << "Failed to initialize MinHook.\n";
    //    return FALSE;
    //}

    //// Get the function name to hook from the parameter (in real use, this could be passed in a different way)
    //std::string functionToHook = "SetThreadContext"; // Example: hard-coded for now

    //try {
    //    BreadSeller::hookFunction(functionToHook, (LPVOID)Detour_SetThreadContext);
    //    std::cout << "Hooked " << functionToHook << " successfully.\n";
    //    return TRUE;
    //}
    //catch (const HookException& e) {
    //    std::cerr << "Error: " << e.what() << "\n";
    //    return FALSE;
    //}
}

BOOL test() {
    std::cout << "helo";
    return TRUE;
}

//void unHookFunction() {
//    BreadSeller::unhookAll();
//    MH_Uninitialize(); // Uninitialize MinHook
//}
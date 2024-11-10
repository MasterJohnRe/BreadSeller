#include "pch.h"
#include "BreadSeller.h"
#include "exceptions.h"
#include <iostream>

std::vector<BreadSeller::HookInfo> BreadSeller::hooks;
static auto logger = spdlog::basic_logger_mt("file_logger", "logfile.txt");

void BreadSeller::hookFunction(const std::string& funcName, LPVOID pDetour) {
    HMODULE hModule = GetModuleHandleA("kernel32.dll");
    if (!hModule) {
        throw ModuleHandleException("kernel32.dll");
    }

    LPVOID pFunction = GetProcAddress(hModule, funcName.c_str());
    if (!pFunction) {
        throw FunctionAddressException(funcName);
    }

    if (MH_CreateHook(pFunction, pDetour, &pFunction) != MH_OK) {
        throw HookCreationException(funcName);
    }

    if (MH_EnableHook(pFunction) != MH_OK) {
        throw HookEnableException(funcName);
    }

    hooks.push_back({ funcName, pFunction, pDetour });
}

void BreadSeller::unhookAll() {
    for (const auto& hook : hooks) {
        MH_DisableHook(hook.originalFunction);
    }
    hooks.clear();
}

LPVOID BreadSeller::getOriginalFunction(const std::string& funcName) {
    for (const auto& hook : hooks) {
        if (hook.functionName == funcName) {
            return hook.originalFunction;
        }
    }
    return nullptr;
}

// Example detour function for SetThreadContext
BOOL WINAPI Detour_SetThreadContext(HANDLE hThread, const CONTEXT* lpContext) {
    // Add any custom logic here
    spdlog::set_default_logger(logger);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
    logger->info("SetThreadContext called, hooking in action!\n");
    // Call the original function (you need to cast it back to the correct type)
    auto originalFunc = (BOOL(WINAPI*)(HANDLE, const CONTEXT*))BreadSeller::getOriginalFunction("SetThreadContext");
    return originalFunc ? originalFunc(hThread, lpContext) : FALSE;
}

bool hookFunction() {
    HMODULE hModule = nullptr;
    DisableThreadLibraryCalls(hModule);

    // Initialize MinHook
    if (MH_Initialize() != MH_OK) {
        std::cerr << "Failed to initialize MinHook.\n";
        return FALSE;
    }

    // Get the function name to hook from the parameter (in real use, this could be passed in a different way)
    std::string functionToHook = "SetThreadContext"; // Example: hard-coded for now

    try {
        BreadSeller::hookFunction(functionToHook, (LPVOID)Detour_SetThreadContext);
        std::cout << "Hooked " << functionToHook << " successfully.\n";
    }
    catch (const HookException& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return FALSE;
    }
}

void unHookFunction() {
    BreadSeller::unhookAll();
    MH_Uninitialize(); // Uninitialize MinHook
}
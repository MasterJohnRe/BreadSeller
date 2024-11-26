#include <Windows.h>
#include <vector>
#include <string>
#include "exceptions.h"
#include "MinHook.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

//class BreadSeller {
//public:
//    struct HookInfo {
//        std::string functionName;
//        LPVOID originalFunction;
//        LPVOID detourFunction;
//    };
//
//    static void hookFunction(const std::string& funcName, LPVOID pDetour);
//    static void unhookAll();
//
//    // Helper function to get the original function pointer from the hooks vector
//    static LPVOID getOriginalFunction(const std::string& funcName);
//
//private:
//    static std::vector<HookInfo> hooks;
//};


// Example detour function declaration
BOOL WINAPI Detour_SetThreadContext(HANDLE hThread, const CONTEXT* lpContext);
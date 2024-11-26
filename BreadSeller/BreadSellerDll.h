//is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HARDWAREBPHOOKDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HARDWAREBPHOOKDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#ifdef BREADSELLER_EXPORTS
#define BREADSELLER_API __declspec(dllexport)
#else
#define BREADSELLER_API __declspec(dllimport)
#endif

#include <iostream>
#include <TlHelp32.h>
#include <sstream>
#include <winternl.h>
#include "Windows.h"
//#include <spdlog/spdlog.h>
//#include <spdlog/sinks/basic_file_sink.h>

BREADSELLER_API BOOL hookFunction();
BREADSELLER_API BOOL test();
//BREADSELLER_API void unHookFunction();
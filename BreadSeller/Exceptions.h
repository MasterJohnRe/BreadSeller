#pragma once
#include <exception>
#include <string>

// Base exception class for hook-related errors
class HookException : public std::exception {
public:
    explicit HookException(const std::string& message) : msg_(message) {}

    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

// Derived exception classes for specific hook errors
class ModuleHandleException : public HookException {
public:
    ModuleHandleException(const std::string& moduleName)
        : HookException("Failed to get module handle for " + moduleName + ".") {}
};

class FunctionAddressException : public HookException {
public:
    FunctionAddressException(const std::string& functionName)
        : HookException("Failed to find function " + functionName + ".") {}
};

class HookCreationException : public HookException {
public:
    HookCreationException(const std::string& functionName)
        : HookException("Failed to create hook for function " + functionName + ".") {}
};

class HookEnableException : public HookException {
public:
    HookEnableException(const std::string& functionName)
        : HookException("Failed to enable hook for function " + functionName + ".") {}
};
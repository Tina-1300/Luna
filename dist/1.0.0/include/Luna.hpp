#pragma once

#include <windows.h>

namespace Luna{

    bool AddKeyRegister(const WCHAR * NameKey, const WCHAR * FilePath, const wchar_t * Register);
    bool DeletKeyRegister(const WCHAR * NameKey, const wchar_t * Register);
    
};
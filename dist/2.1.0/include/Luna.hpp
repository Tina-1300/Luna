#pragma once

#include <windows.h>
#include <string>
#include <stdexcept> 

class RegReadException : public std::runtime_error{
    public:
        explicit RegReadException(const std::string& message);
};

namespace Luna{

    bool AddKeyRegister(HKEY rootKey, const WCHAR * NameKey, const WCHAR * FilePath, const wchar_t * Register);
    bool DeletKeyRegister(HKEY rootKey, const WCHAR * NameKey, const wchar_t * Register);
    std::string ReadKeyRegister(HKEY rootKey, const wchar_t *Register, const WCHAR *NameKey); 
    
    bool AddKeyRegisterRegDWORD(HKEY rootKey, const WCHAR * NameKey, const DWORD * value, const wchar_t * Register);
    bool AddKeyRegisterRegQWORD(HKEY rootKey, const WCHAR *NameKey, const unsigned long long *value, const wchar_t *regPath);
    bool AddKeyRegisterRegBinary(HKEY rootKey, const WCHAR *nameKey, const BYTE *value, DWORD dataSize, const wchar_t *regPath);
    bool DoesKeyExist(HKEY rootKey, const wchar_t *regPath, const wchar_t *nameKey);
    std::string Version();

};
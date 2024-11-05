#include <iostream>
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    if (Luna::AddKeyRegister(NameKey, FilePath, Register) == true){
        std::cout << "La cle a bien ete ajouter" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }

    return 0;
}

// ou 

/*
#include <iostream>
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    if (Luna::DeletKeyRegister(NameKey, Register) == true){
        std::cout << "La cle a bien ete suprimmer" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }

    return 0;
}

*/
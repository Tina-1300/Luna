#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    if (Luna::AddKeyRegister(HKEY_CURRENT_USER ,NameKey, FilePath, Register) == true){
        std::cout << "La cle a bien ete ajouter" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }

    return 0;
}

// ou 

/*

---------------------------------- SUPRESSION D'UNE CLE --------------------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    if (Luna::DeletKeyRegister(HKEY_CURRENT_USER, NameKey, Register) == true){
        std::cout << "La cle a bien ete suprimmer" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }

    return 0;
}


------------------------------------------------- Lecture d'une cle qui a une valeur REG_SZ -------------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){

    try{
        std::string value = Luna::ReadKeyRegister(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", L"OneDrive");
        std::cout << "Valeur : " << value << std::endl;

    }catch(const RegReadException& e){
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}


*/
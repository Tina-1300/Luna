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



----------------------------------------------------- Ajout d'une clé de registre de type DWORD ----------------------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    const wchar_t * regPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"test";
    DWORD value = 12345;  // Valeur à ajouter sous forme de DWORD

    bool success = Luna::AddKeyRegisterRegDWORD(HKEY_CURRENT_USER, NameKey, &value, regPath);

    if (success){
        std::cout << "La valeur a été ajoutée avec succès." << std::endl;
    }else{
        std::cout << "Une erreur est survenue lors de l'ajout de la valeur." << std::endl;
    }

    return 0;
}



---------------------------------------------------------- Ajouter une cle de registre de type QDWORD -------------------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    const wchar_t *regPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR *nameKey = L"MyQWORD";
    unsigned long long value = 1234567890123456789ULL;

    bool success = Luna::AddKeyRegisterRegQWORD(HKEY_CURRENT_USER, nameKey, &value, regPath);

    if (success){
        std::cout << "La valeur a été ajoutée avec succès." << std::endl;
    }else{
        std::cout << "Une erreur est survenue lors de l'ajout de la valeur." << std::endl;
    }

    return 0;
}




----------------------------------------------------------- Ajouter une cle de registre avec un type REG_BINARY ---------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    const wchar_t *regPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR *nameKey = L"MyQWORD";
    BYTE binaryData[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    DWORD dataSize = sizeof(binaryData);

    bool success = Luna::AddKeyRegisterRegBinary(HKEY_CURRENT_USER, nameKey, binaryData, dataSize, regPath);

    if (success){
        std::cout << "Valeur REG_BINARY ajoutee avec succes dans le registre." << std::endl;
    }else{
        std::cout << "Erreur lors de l'ajout de la valeur REG_BINARY." << std::endl;
    }

    return 0;
}


------------------------------------------------------- Vérifier si une cle existe -----------------------------------------------

#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    const wchar_t *regPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR *nameKey = L"OneDrivee";

    bool exists = Luna::DoesKeyExist(HKEY_CURRENT_USER, regPath, nameKey);
    
    if (exists == true){
        std::cout << "La cle existe deja." << std::endl;
    }else{
        std::cout << "La cle n'existe pas." << std::endl;
    }

    return 0;
}

*/
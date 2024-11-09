# Luna 2.1.0

## Notes de version
- Ajout de nouvelles fonctionnalités.

## Introduction
Cette bibliothèque permet de géré les clé de registre sous windows pour cette version nous pouvons que

- Crée une clé de registre 
- Suprimmer une clé de registre 
- Lire la valeur que stock une cle de registre 

## Nouveauter de la 2.1.0 :

- [AddKeyRegisterRegDWORD()](#addkeyregisterregdword)
- [AddKeyRegisterRegQWORD()](#a)
- [AddKeyRegisterRegBinary()](#b)
- [DoesKeyExist()](#c)


## Compilation :

````bash
g++ -o main.exe main.cpp -lLuna
````


# dans le Namespace Luna ce trouve :

- [AddKeyRegister()](#addkeyregister)
- [DeletKeyRegister()](#deletkeyregister)
- [ReadKeyRegister()](#ReadKeyRegister)
- [AddKeyRegisterRegDWORD()](#addkeyregisterregdword)
- [AddKeyRegisterRegQWORD()](#a)
- [AddKeyRegisterRegBinary()](#b)
- [DoesKeyExist()](#c)
- [Version()]() - Permet de savoir la version que vous avez installer vous retourne un std::string disponible à partire des version 2.1.0 

---


#### [AddKeyRegister()](#addkeyregister)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const WCHAR * NameKey` : Le nom de la clé de registre à créer.
  - `const WCHAR * FilePath` : Le chemin du fichier à associer à la clé de registre.
  - `const WCHAR * Register` : Le chemin de la clé de registre à ouvrir.

- **Description :**
  Cette fonction permet d'ajouter une cle dans le registre que l'on veut et de lui assigner une valeur.
  en REG_SZ

- **Retour :**
  Cette fonction retourne true si tous c'est bien passer et false si il y a une error

- **Exemple de Code :**

````cpp
#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    if (Luna::AddKeyRegister(HKEY_CURRENT_USER, NameKey, FilePath, Register) == true){
        std::cout << "La cle a bien ete ajouter" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }

    return 0;
}
````

---

#### [DeletKeyRegister()](#deletkeyregister)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const WCHAR * NameKey` : Le nom de la clé de registre à suprimmer.
  - `const WCHAR * Register` : Le chemin de la clé de registre à ouvrir.

- **Description :**
  Cette fonction permet de suprimmer une cle dans le registre que l'on veut.

- **Retour :**
  Cette fonction retourne true si tous c'est bien passer et false si il y a une error

- **Exemple de Code :**

````cpp
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
````

---

#### [ReadKeyRegister()](#readkeyregister)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const wchar_t *Register` : Le chemin de la clé de registre à ouvrir.
  - `const WCHAR *NameKey` : Le nom de la cle situer dans le chemin du registe.

- **Description :**
  Cette fonction permet de récupéré la valeur d'une cle prend en charge que REG_SZ.

- **Retour :**
  Cette fonction retourne un std::string contenant la valeur de la cle, et une exeption si il y a une error.

- **Exemple de Code :**

````cpp
#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>
#include <Luna.hpp>

int main(){
    const wchar_t * Register = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const WCHAR * NameKey = L"Ytyueusdfjsdhsdwxx";
    //const WCHAR * FilePath = L"C:\\YouTube.exe"; 

    try{
        std::string value = Luna::ReadKeyRegister(HKEY_CURRENT_USER, Register, NameKey);
        std::cout << "Registry Value : " << value << std::endl;
    }catch(const RegReadException& e){
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
````

---


#### [AddKeyRegisterRegDWORD()](#addkeyregisterregdword)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const WCHAR * NameKey` : Le Nom de la cle de registre à ajoutter .
  - `const DWORD * value` : La valeur stocker dans la cle.
  - `const wchar_t * Register` : Le chemin vers le registre. 

- **Description :**
  Cette fonction permet de d'ajouter une cle de registre type DWORD.

- **Retour :**
  Cette fonction retourne un bool true si tout c'est bien passer et false si il y a eu une error.

- **Exemple de Code :**

````cpp
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
````

---

#### [AddKeyRegisterRegQWORD()](#a)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const WCHAR *NameKey` : Le Nom de la cle de registre à ajoutter .
  - `const unsigned long long *value` : La valeur stocker dans la cle.
  - `const wchar_t *regPath` : Le chemin vers le registre. 

- **Description :**
  Cette fonction permet de d'ajouter une cle de registre type QDWORD.

- **Retour :**
  Cette fonction retourne un bool true si tout c'est bien passer et false si il y a eu une error.

- **Exemple de Code :**

````cpp
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
````

---



#### [AddKeyRegisterRegBinary()](#b)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const WCHAR *nameKey` : Le Nom de la cle de registre à ajoutter .
  - `const BYTE *value` : La valeur à stocker dans la cle.
  - `DWORD dataSize` : La taille des donné à stocker dans la cle.
  - `const wchar_t *regPath` : Le chemin vers le registre. 

- **Description :**
  Cette fonction permet de d'ajouter une cle de registre type REG_BINARY.

- **Retour :**
  Cette fonction retourne un bool true si tout c'est bien passer et false si il y a eu une error.

- **Exemple de Code :**

````cpp
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
````

---


#### [DoesKeyExist()](#c)

- **Paramètres :**
  - `HKEY rootKey` : Le chemin rootKey.
  - `const wchar_t *regPath` : Le chemin vers le registre ou l'on va vérifier si la cle existe.
  - `const wchar_t *nameKey` : Le nom de la cle à vérifier.

- **Description :**
  Cette fonction permet de vérifier si une cle existe.

- **Retour :**
  Cette fonction retourne un bool true si la clé existe bien et false si la clé n'existe pas.

- **Exemple de Code :**

````cpp
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
````

---

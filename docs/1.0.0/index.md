# Luna 1.0.0

## Notes de version
- Ajout de nouvelles fonctionnalités.

## Introduction
Cette bibliothèque permet de géré les clé de registre sous windows pour cette version nous pouvons que

- Crée une clé de registre 
- Suprimmer une clé de registre 

## Compilation :

````bash
g++ -o main.exe main.cpp -lLuna
````


# dans le Namespace Luna ce trouve :

- [AddKeyRegister()](#addkeyregister)
- [DeletKeyRegister()](#deletkeyregister)


---


#### [AddKeyRegister()](#addkeyregister)

- **Paramètres :**
  - `const WCHAR * NameKey` : Le nom de la clé de registre à créer.
  - `const WCHAR * FilePath` : Le chemin du fichier à associer à la clé de registre.
  - `const WCHAR * Register` : Le chemin de la clé de registre à ouvrir.

- **Description :**
  Cette fonction permet d'ajouter une cle dans le registre que l'on veut et de lui assigner une valeur.

- **Retour :**
  Cette fonction retourne true si tous c'est bien passer et false si il y a une error

- **Exemple de Code :**

````cpp
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
````

---

#### [DeletKeyRegister()](#deletkeyregister)

- **Paramètres :**
  - `const WCHAR * NameKey` : Le nom de la clé de registre à suprimmer.
  - `const WCHAR * Register` : Le chemin de la clé de registre à ouvrir.

- **Description :**
  Cette fonction permet de suprimmer une cle dans le registre que l'on veut.

- **Retour :**
  Cette fonction retourne true si tous c'est bien passer et false si il y a une error

- **Exemple de Code :**

````cpp
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
````
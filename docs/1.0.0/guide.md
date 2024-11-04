# Guide d'Utilisation

Ce guide vous aidera à démarrer avec Luna.

## Installation
Pour installer la bibliothèque, suivez ces étapes :

1. Clonez le dépôt :
   ````bash
   git clone git clone https://github.com/Tina-1300/Luna.git
   ````

2. Configuration et Installation sous mingw :

    La library et compiler, elle et disponible dans dist/ le numéro de version / include & lib
    Vous devez mettre le contenu du fichiers include dans ..\mingw64\x86_64-w64-mingw32\include
    Vous devez mettre le contenu du fichiers lib dans ..\mingw64\x86_64-w64-mingw32\lib

3. Compilation :

    ````bash 
    g++ -o main.exe main.cpp -lLuna
    ````

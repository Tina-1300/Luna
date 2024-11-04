@echo off
REM Créer un dossier pour les fichiers objets si ce n'est pas déjà fait
if not exist obj (
    mkdir obj
)

REM Créer le dossier de distribution si ce n'est pas déjà fait
if not exist dist\1.0.0\include (
    mkdir dist\1.0.0\include
)

REM Compiler chaque fichier source en fichier objet
for %%f in (src\*.cpp) do (
    g++ -c "%%f" -I./include -o "obj\%%~nf.o"
)

REM Créer la bibliothèque statique à partir des fichiers objets
ar rcs dist\1.0.0\lib\libLuna.a obj\*.o

REM Copier les fichiers d'en-tête vers le dossier de distribution
xcopy /E /Y include\*.hpp dist\1.0.0\include\

REM Nettoyer les fichiers objets (facultatif)
REM del obj\*.o

echo Compilation terminée. La bibliothèque est disponible dans dist\1.0.0\lib\libLuna.a.
pause

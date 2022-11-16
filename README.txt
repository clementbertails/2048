Ce projet a ete realise par Bertails Clement, Longuet Maxime, et Maurer Pierrick.

Organisation :
    - Dans le dossier bin se trouvent les executables ainsi que les DLL, et des licenses de l'extension
       SDL2_image (extension de la librairie SDL2)
    - Dans le dossier include se trouvent tout les fichiers a inclure pour le fonctionnement de SDL2
       et SDL2_image
    - Dans le dossier lib se trouvent les librairies SDL2 et SDL2_image
    - Dans le dossier sources se trouvent tous les fichiers que nous avons codés, ainsi qu'un autre
       dossier contenant toutes les images que nous utilisons

Compilation (depuis la racine du projet) :
    - Windows:  Compiler.bat   ou   gcc src/*.c -o bin/2048 -mwindows -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
    - GNU/Linux MacOS  (normalement non supporté) :    gcc src/*.c $(sdl2-config --cflags --libs) -o bin/2048 -lSDl2_image
    - Makefile

Utilisation :
Pour lancer correctement le programme, il faut être dans la racine :
Sous windows, un lanceur est disponible (Launcher.bat), sinon il peut être lancé avec la ligne
de commande : bin\2048.exe

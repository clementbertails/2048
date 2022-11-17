#include "affichage.h"
#include "jeu.h"

/*
Compiler :
  Windows
    >  gcc src/fichiers.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    >  gcc src/fichiers.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows    (n'ouvre pas le terminal en plus, si ca faisait chier qq)
  GNU/Linux MacOS
    > gcc *.c $(sdl2-config --cflags --libs) -o prog
*/

int main (int argc, char** argv)
{
  srand(time(NULL));
  // afficher menu
  // recup click
  //jeu(8);
  SDL_Window *window = creationFenetre(window);
  SDL_Renderer *renderer = creationRendu(window, renderer);
  textures texture = initTextures(texture);

  menuPrincipal(window, renderer, texture);
  return EXIT_SUCCESS;
}
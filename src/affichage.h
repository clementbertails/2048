#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/SDL.h"

// Fenetre
#define LARGEUR 690
#define HAUTEUR 440
#define LARGEUR_CASE 65
#define HAUTEUR_CASE 65
#define MODE_FENETRE 0

// Textes
#define NOM_JEU "2048"

#ifndef STRUCT_TEXTURES
#define STRUCT_TEXTURES
typedef struct textu {  // ADD IMG
    // Cases
    SDL_Texture *case2;
    SDL_Texture *case4;
    SDL_Texture *case8;
    SDL_Texture *case16;
    SDL_Texture *case32;
    SDL_Texture *case64;
    SDL_Texture *case128;
    SDL_Texture *case256;
    SDL_Texture *case512;
    SDL_Texture *case1024;
    SDL_Texture *case2048;
    // Fond
    SDL_Texture *fond;
    SDL_Texture *menu;
    // Panel de droite et infos
    SDL_Texture *panel;
    SDL_Texture *victoire;
    SDL_Texture *defaite;
} textures;
#endif



// Exit/destruction
void SDL_ExitErreur(const char* message);

void destructionTout(SDL_Window *window, SDL_Renderer *renderer, textures texture);

void destructionTextures(textures texture);



// Fenetre et Rendu
SDL_Window* creationFenetre (SDL_Window *window);

SDL_Renderer* creationRendu(SDL_Window *window, SDL_Renderer *renderer);



// Textures
textures initTextures(textures texture);

SDL_Texture* creationTexture(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, textures allTextures, char* chemin);

textures chargerTextures4x4(SDL_Window *window, SDL_Renderer *renderer, textures texture);

textures chargerTextures8x8(SDL_Window *window, SDL_Renderer *renderer, textures texture);

    // Centre l'image si coord < 0
void afficherTexture(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, textures allTextures, int x, int y);



// JEU EN GRAPHIQUE -----------------------------------------------------------------------------------------
void afficherGrille(SDL_Window *window, SDL_Renderer *renderer, textures texture, int **grille, int taille);



#endif
#ifndef JEUTERMINAL_H
#define JEUTERMINAL_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "affichage.h"

/*!
* \fn struct coord
* \brief structure qui définit une variable contenant les coordonnees d'une case
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 2 mai 2020
*/
#ifndef STRUCT_COORD
#define STRUCT_COORD
typedef struct coord
{
  int i;
  int j;
}coord;
#endif

#ifdef linux
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif //definit le sclear en fonction du systeme d'exploitation de la machine

/*!
* \fn int** creationGrille(void)
* \brief fonction qui alloue la memoire pour un tableau d'entiers a deux dimensions, representant la grille de jeu
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \return int** grille : tableau créé
*/
int** creationGrille (int taille);

int grillePleine(int **grille, int taille);

/*!
* \fn void randomCaseVide(int **grille)
* \brief fonction qui fait apparaitre aleatoirement un 2 ou un 4 sur la grille
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void randomCaseVide(int **grille, int taille);


/*!
* \fn void initialiserGrille(int **grille)
* \brief fonction qui remplit la grille de 0, signifiant case vide
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void initialiserGrille(int **grille, int taille);


/*!
* \fn void freeInt2(int **tab)
* \brief fonction qui vide la memoire allouee au tableau a deux dimensions passe en parametre
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **tab : tableau a vider
* \param int taille : taille du tableau
*/
void freeInt2(int** tab, int taille);


/*!
* \fn void deplacementDroit(int **grille)
* \brief fonction qui gere le deplacement vers la droite
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void deplacementDroit(int **grille, int taille);


/*!
* \fn void deplacementGauche(int **grille)
* \brief fonction qui gere le deplacement vers la gauche
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void deplacementGauche(int **grille, int taille);


/*!
* \fn void deplacementHaut(int **grille)
* \brief fonction qui gere le deplacement vers le haut
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void deplacementHaut(int **grille, int taille);


/*!
* \fn void deplacementBas(int **grille)
* \brief fonction qui gere le deplacement vers le bas
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
*/
void deplacementBas(int **grille, int taille);

/*!
* \fn int conditionVictoire(int **grille)
* \brief fonction qui verifie si le joueur a gagne
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
* \return int res : booleen indiquant si le joueur a gagne (1) ou non (0)
*/
int conditionVictoire(int **grille, int taille);


/*!
* \fn void copieGrille(int **grille, int **grilleTmp)
* \brief fonction qui copie la grille actuelle dans un tableau temporaire
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu actuelle, int **grilleTmp : tableau temporaire (copie)
*/
void copieGrille(int **grille, int **grilleTmp, int taille);


/*!
* \fn int comparaisonGrille(int **grille, int **grilleTmp)
* \brief fonction qui verifie si les grilles avant et apres le coup sont egales
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu actuelle, int **grilleTmp : tableau temporaire servant a tester les deplacements
* \return int res : booleen indiquant si les grilles sont egales (1) ou non (0)
*/
int comparaisonGrille(int **grille, int **grilleTmp, int taille);


/*!
* \fn int conditionDefaite(int **grille)
* \brief fonction qui verifie si le joueur a perdu
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
* \return int res : booleen indiquant si le joueur a perdu (1) ou non (0)
*/
int conditionDefaite(int **grille, int taille);


/*!
* \fn void jeu4x4(void)
* \brief fonction qui gere l'ensemble du jeu
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
*/
void jeu(SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille);

void messageFin(SDL_Window *window, SDL_Renderer *renderer, textures texture, int victoire);

textures chargerTextures(SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille);

/*!
* \fn void tour(void)
* \brief fonction qui gere un tour de jeu
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu, SDL_Window *window : fenetre de jeu, SDL_Renderer *renderer : rendu du jeu, textures texture : texture du jeu ( tout cela permet l'affichage)
*/
void tour(int **grille, SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille);

/*!
* \fn int deplacement(int **grille)
* \brief fonction qui effectue les deplacements correspondants a la saisie du joueur (fleche) et retourne un booleen gerant la fermeture du programme
* \author Clement Bertails, Maxime Longuet, Pierrick Maurer
* \date 8 juin 2020
* \param int **grille : grille de jeu
* \return int finProg : booleen indiquant si le joueur a a choisi de quitter le programme (1) ou non (0)
*/
int deplacement(int **grille, int taille);

void menuPrincipal(SDL_Window *window, SDL_Renderer *renderer, textures texture);

#endif // JEUTERMINAL_H

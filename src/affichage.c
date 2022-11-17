#include "affichage.h"
/*
Renderer Flags :

    SDL_RENDERER_SOFTWARE
    SDL_RENDERER_ACCELERATED
    SDL_RENDERER_PRESENTVSYNC
    SDL_RENDERER_TARGETTEXTURE
*/


// Exit/destruction
void SDL_ExitErreur(const char* message)
{
    SDL_Log("ERREUR : %s > %s", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void destructionTout(SDL_Window *window, SDL_Renderer *renderer, textures texture)  // ADD IMG
{
    if (window != NULL) SDL_DestroyWindow(window);
    if (renderer != NULL) SDL_DestroyRenderer(renderer);
    if (texture.fond != NULL) SDL_DestroyTexture(texture.fond);
    if (texture.panel != NULL) SDL_DestroyTexture(texture.panel);
    if (texture.menu != NULL) SDL_DestroyTexture(texture.menu);
    if (texture.victoire != NULL) SDL_DestroyTexture(texture.victoire);
    if (texture.defaite != NULL) SDL_DestroyTexture(texture.defaite);
    if (texture.case2 != NULL) SDL_DestroyTexture(texture.case2);
    if (texture.case4 != NULL) SDL_DestroyTexture(texture.case4);
    if (texture.case8 != NULL) SDL_DestroyTexture(texture.case8);
    if (texture.case16 != NULL) SDL_DestroyTexture(texture.case16);
    if (texture.case32 != NULL) SDL_DestroyTexture(texture.case32);
    if (texture.case64 != NULL) SDL_DestroyTexture(texture.case64);
    if (texture.case128 != NULL) SDL_DestroyTexture(texture.case128);
    if (texture.case256 != NULL) SDL_DestroyTexture(texture.case256);
    if (texture.case512 != NULL) SDL_DestroyTexture(texture.case512);
    if (texture.case1024 != NULL) SDL_DestroyTexture(texture.case1024);
    if (texture.case2048 != NULL) SDL_DestroyTexture(texture.case2048);

    SDL_Quit(); 
}

void destructionTextures(textures texture)
{
    if (texture.fond != NULL) SDL_DestroyTexture(texture.fond);
    if (texture.panel != NULL) SDL_DestroyTexture(texture.panel);
    if (texture.menu != NULL) SDL_DestroyTexture(texture.menu);
    if (texture.victoire != NULL) SDL_DestroyTexture(texture.victoire);
    if (texture.defaite != NULL) SDL_DestroyTexture(texture.defaite);
    if (texture.case2 != NULL) SDL_DestroyTexture(texture.case2);
    if (texture.case4 != NULL) SDL_DestroyTexture(texture.case4);
    if (texture.case8 != NULL) SDL_DestroyTexture(texture.case8);
    if (texture.case16 != NULL) SDL_DestroyTexture(texture.case16);
    if (texture.case32 != NULL) SDL_DestroyTexture(texture.case32);
    if (texture.case64 != NULL) SDL_DestroyTexture(texture.case64);
    if (texture.case128 != NULL) SDL_DestroyTexture(texture.case128);
    if (texture.case256 != NULL) SDL_DestroyTexture(texture.case256);
    if (texture.case512 != NULL) SDL_DestroyTexture(texture.case512);
    if (texture.case1024 != NULL) SDL_DestroyTexture(texture.case1024);
    if (texture.case2048 != NULL) SDL_DestroyTexture(texture.case2048);
}



// Fenetre et rendu
SDL_Window* creationFenetre (SDL_Window *window)
{
    // Init
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {    // Si init fail on ferme le prog et on log l'erreur
        SDL_ExitErreur("SDL_Init");
    }

    // Creation fenetre
    window = SDL_CreateWindow(NOM_JEU,                                          // Nom fenetre
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // Position fenetre (x, y)
                              LARGEUR, HAUTEUR,                                 // Taille fenetre (w, h)
                              MODE_FENETRE);                                    // Mode affichage fenetre

    if (window == NULL) {   // Si fenetre existe pas : on ferme et on log l'erreur
        SDL_ExitErreur("SDL_CreateWindow");
    }
    SDL_Surface *icon = IMG_Load("src/images/2048_4x4.png"); // Charge l'icone de la fenetre
    if (icon == NULL) {
        SDL_ExitErreur("IMG_Load");
    }
    SDL_SetWindowIcon(window, icon);

    return window;
}

SDL_Renderer* creationRendu(SDL_Window *window, SDL_Renderer *renderer)
{
    renderer = SDL_CreateRenderer(window,                   // Fenetre cible
                                  -1,                       // Driver (-1 pour initialiser)
                                  SDL_RENDERER_ACCELERATED);   // Flags Rendu (etait SDL_RENDERER_SOFTWARE)
    if (renderer == NULL) {
        SDL_ExitErreur("SDL_CreateRenderer");
    }
    SDL_RenderPresent(renderer); 

    return renderer;
}



// Textures
textures initTextures(textures texture)
{
    // Cases
    texture.case2 = NULL;
    texture.case4 = NULL;
    texture.case8 = NULL;
    texture.case16 = NULL;
    texture.case32 = NULL;
    texture.case64 = NULL;
    texture.case128 = NULL;
    texture.case256 = NULL;
    texture.case512 = NULL;
    texture.case1024 = NULL;
    texture.case2048 = NULL;
    // Fond
    texture.fond = NULL;
    texture.menu = NULL;
    // Panel de droite et infos
    texture.panel = NULL;
    texture.victoire = NULL;
    texture.defaite = NULL;

    return texture;
}

SDL_Texture* creationTexture(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, textures allTextures, char* chemin)
{
    SDL_Surface *image = NULL;

    image = IMG_Load(chemin);
    if (image == NULL) {        // Charge l'image
        destructionTout(window, renderer, allTextures);
        SDL_ExitErreur("IMG_Load");
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == NULL) {      // Transforme l'image en surface
        destructionTout(window, renderer, allTextures);
        SDL_ExitErreur("SDL_CreateTextureFromSurface");
    }
    SDL_FreeSurface(image);
    
    return texture;
}

textures chargerTextures4x4(SDL_Window *window, SDL_Renderer *renderer, textures texture)   // ADD IMG
{
    /*
    texture.nomTexture = creationTexture(window, renderer, texture.nomTexture, texture, "src/images/image.png"); // a refaire pour chaque image
    */
    texture.fond = creationTexture(window, renderer, texture.fond, texture, "src/images/fond_4x4.png");
    texture.panel = creationTexture(window, renderer, texture.panel, texture, "src/images/panel.png");
    texture.victoire = creationTexture(window, renderer, texture.victoire, texture, "src/images/victoire.png");
    texture.defaite = creationTexture(window, renderer, texture.defaite, texture, "src/images/defaite.png");
    texture.case2 = creationTexture(window, renderer, texture.case2, texture, "src/images/2_4x4.png");
    texture.case4 = creationTexture(window, renderer, texture.case4, texture, "src/images/4_4x4.png");
    texture.case8 = creationTexture(window, renderer, texture.case8, texture, "src/images/8_4x4.png");
    texture.case16 = creationTexture(window, renderer, texture.case16, texture, "src/images/16_4x4.png");
    texture.case32 = creationTexture(window, renderer, texture.case32, texture, "src/images/32_4x4.png");
    texture.case64 = creationTexture(window, renderer, texture.case64, texture, "src/images/64_4x4.png");
    texture.case128 = creationTexture(window, renderer, texture.case128, texture, "src/images/128_4x4.png");
    texture.case256 = creationTexture(window, renderer, texture.case256, texture, "src/images/256_4x4.png");
    texture.case512 = creationTexture(window, renderer, texture.case512, texture, "src/images/512_4x4.png");
    texture.case1024 = creationTexture(window, renderer, texture.case1024, texture, "src/images/1024_4x4.png");
    texture.case2048 = creationTexture(window, renderer, texture.case2048, texture, "src/images/2048_4x4.png");
    return texture;
}

textures chargerTextures8x8(SDL_Window *window, SDL_Renderer *renderer, textures texture)   // ADD IMG
{
    /*
    texture.nomTexture = creationTexture(window, renderer, texture.nomTexture, texture, "src/images/image.png"); // a refaire pour chaque image
    */
    texture.fond = creationTexture(window, renderer, texture.fond, texture, "src/images/fond_8x8.png");
    texture.panel = creationTexture(window, renderer, texture.panel, texture, "src/images/panel.png");
    texture.victoire = creationTexture(window, renderer, texture.victoire, texture, "src/images/victoire.png");
    texture.defaite = creationTexture(window, renderer, texture.defaite, texture, "src/images/defaite.png");
    texture.case2 = creationTexture(window, renderer, texture.case2, texture, "src/images/2_8x8.png");
    texture.case4 = creationTexture(window, renderer, texture.case4, texture, "src/images/4_8x8.png");
    texture.case8 = creationTexture(window, renderer, texture.case8, texture, "src/images/8_8x8.png");
    texture.case16 = creationTexture(window, renderer, texture.case16, texture, "src/images/16_8x8.png");
    texture.case32 = creationTexture(window, renderer, texture.case32, texture, "src/images/32_8x8.png");
    texture.case64 = creationTexture(window, renderer, texture.case64, texture, "src/images/64_8x8.png");
    texture.case128 = creationTexture(window, renderer, texture.case128, texture, "src/images/128_8x8.png");
    texture.case256 = creationTexture(window, renderer, texture.case256, texture, "src/images/256_8x8.png");
    texture.case512 = creationTexture(window, renderer, texture.case512, texture, "src/images/512_8x8.png");
    texture.case1024 = creationTexture(window, renderer, texture.case1024, texture, "src/images/1024_8x8.png");
    texture.case2048 = creationTexture(window, renderer, texture.case2048, texture, "src/images/2048_8x8.png");
    return texture;
}

void afficherTexture(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, textures allTextures, int x, int y)
{
    SDL_Rect rectangle;

    if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) { // Charger la texture
        destructionTout(window, renderer, allTextures);
        SDL_ExitErreur("SDL_QueryTexture");
    }

    if (x < 0) {
        rectangle.x = (LARGEUR - rectangle.w) / 2; 
    } else {
        rectangle.x = x;
    }
    if (y < 0) {
        rectangle.y = (HAUTEUR - rectangle.h) / 2;
    } else {
        rectangle.y = y;
    }

    if (SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) {     // La mettre dans le rendu
        destructionTout(window, renderer, allTextures);
        SDL_ExitErreur("SDL_RenderCopy");
    }
}



// JEU EN GRAPHIQUE -----------------------------------------------------------------------------------------
void afficherGrille(SDL_Window *window, SDL_Renderer *renderer, textures texture, int **grille, int taille)
{
    int i;
    int j;

    int tailleCase = 400 / taille;
    int bordureGrille = 20 + 20/taille;

    // On reprend un rendu vierge
    SDL_RenderClear(renderer);

    // On affiche le fond du jeu et le panel de droite
    afficherTexture(window, renderer, texture.fond, texture, 0, -1);
    afficherTexture(window, renderer, texture.panel, texture, 440, -1);

    // Puis par dessus toute la grille
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            // coord.x = 20 + 100 * i;  20 est le décalage souhaité des bordures
            // coord.y = 20 + 100 * j;  100 est la taille des images (90) + le décalage avec l'image suivante (10)
            switch (grille[i][j])
            {
            case 0:     // Case vide : on affiche rien, permet d'accelerer l'affichage si la case est vide (on ne compare pas avec tt le switch)
                break;
            case 2:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case2, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 4:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case4, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 8:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case8, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 16:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case16, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 32:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case32, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 64:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case64, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 128:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case128, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 256:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case256, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 512:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case512, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 1024:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case1024, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            case 2048:     // Valeur trouvée : on l'affiche
                afficherTexture(window, renderer, texture.case2048, texture, bordureGrille+tailleCase*j, bordureGrille+tailleCase*i);
                break;
            
            default:
                // ERREUR : CASE NON VIDE MAIS VALEUR NON RECONNUE, QUITTER LE PROGRAMME
                destructionTout(window, renderer, texture);
                break;
            }
        }
    }
     
    SDL_RenderPresent(renderer);
}
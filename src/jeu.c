#include "jeu.h"

int** creationGrille (int taille)
{ // creer la grille de jeu
  int **grille = malloc(sizeof(int*) * taille); // allouer le tableau 2 dimensions
  if (grille == NULL) // verifier l'allocation
  {
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < taille; i++) // allouer tout les int* determiner precedemment
  {
    grille[i] = malloc(sizeof(int) * taille);
    if (grille[i] == NULL) // verifier l'allocation
    {
      exit(EXIT_FAILURE);
    }
  }
  initialiserGrille(grille, taille);
  return grille;
}

int grillePleine(int **grille, int taille)
{
  int res = 1;
  for (int i = 0; i < taille; i++)
  {
    for (int j = 0; j < taille; j++)
    {
      if (grille[i][j] == 0)
      {
        res = 0;
      }
    }
  }
  return res;
}

void randomCaseVide(int **grille, int taille) // permet de randomiser la nouvelle case 4 ou 2
{
  int continuer = 1;
  int i;
  int j;
  if (!grillePleine(grille, taille))
  {
    while(continuer)
    {
      i = rand()%(taille);
      j = rand()%(taille);
      if (grille[i][j] == 0) // verifier si la case est vide
      {
        continuer = 0;
      }
    }
    if (rand()%100 < 91) // probabilité d'avoir 2 ou 4
    {
      grille[i][j] = 2;
    }
    else
    {
      grille[i][j] = 4;
    }
  }
}

void initialiserGrille(int **grille, int taille)
{
  for (int i = 0; i < taille; i++) // initialiser la grille de jeu
  {
    for (int j = 0; j < taille; j++)
    {
      grille[i][j] = 0;
    }
  }
  randomCaseVide(grille, taille);
  randomCaseVide(grille, taille);
}

void freeInt2(int** tab, int taille) // liberer un tableau a 2 dimensions
{
    for (int i = 0; i < taille; i++) 
    {
        free(tab[i]);
    }
    free(tab);
}

void deplacementDroit(int **grille, int taille) // mouvement des numeros vers la droite
{
  int nbpiece;
  int tmp;
  int **grilleTmp = creationGrille(taille);
  copieGrille(grille, grilleTmp, taille);
  for (int i = 0; i < taille; i++)
  {
    nbpiece = 1;
    for (int j = taille-1; j > -1; j--)
    {
      if (grille[i][j] != 0 && nbpiece > 1 && grille[i][taille - nbpiece + 1] == grille[i][j] && grilleTmp[i][taille - nbpiece + 1] == grille[i][j]) // deplacement et fusion des cases
      {
        grille[i][taille - nbpiece + 1] *= 2;
        grille[i][j] = 0;

      }
      else if (grille[i][j] != 0) // deplacement uniquement
      {
        tmp = grille[i][j];
        grille[i][j] = 0;
        grilleTmp[i][j] = 0;
        grille[i][taille - nbpiece] = tmp;
        grilleTmp[i][taille - nbpiece] = tmp;
        nbpiece++;
      }
    }
  }
  freeInt2(grilleTmp, taille);
}

void deplacementGauche(int **grille, int taille) // mouvement des numeros vers la gauche
{
  int nbpiece;
  int tmp;
  int **grilleTmp = creationGrille(taille);
  copieGrille(grille, grilleTmp, taille);
  for (int i = 0; i < taille; i++)
  {
    nbpiece = 0;
    for (int j = 0; j < taille; j++)
    {
      if (grille[i][j] != 0 && nbpiece > 0 && grille[i][nbpiece - 1] == grille[i][j] && grilleTmp[i][nbpiece - 1] == grille[i][j]) // deplacement et fusion des cases
      {
        grille[i][nbpiece - 1] *= 2;
        grille[i][j] = 0;
      }
      else if (grille[i][j] != 0) // deplacement uniquement
      {
        tmp = grille[i][j];
        grille[i][j] = 0;
        grilleTmp[i][j] = 0;
        grille[i][nbpiece] = tmp;
        grilleTmp[i][nbpiece] = tmp;
        nbpiece++;
      }
    }
  }
}

void deplacementHaut(int **grille, int taille) // mouvement des numeros vers le haut
{
  int nbpiece;
  int tmp;
  int **grilleTmp = creationGrille(taille);
  copieGrille(grille, grilleTmp, taille);
  for (int j = 0; j < taille; j++)
  {
    nbpiece = 0;
    for (int i = 0; i < taille; i++)
    {
      if (grille[i][j] != 0 && nbpiece > 0 && grille[nbpiece - 1][j] == grille[i][j] && grilleTmp[nbpiece - 1][j] == grille[i][j]) // deplacement et fusion des cases
      {
        grille[nbpiece - 1][j] *= 2;
        grille[i][j] = 0;
      }
      else if (grille[i][j] != 0) // deplacement uniquement
      {
        tmp = grille[i][j];
        grille[i][j] = 0;
        grilleTmp[i][j] = 0;
        grille[nbpiece][j] = tmp;
        grilleTmp[nbpiece][j] = tmp;
        nbpiece++;
      }
    }
  }
  freeInt2(grilleTmp, taille);
}

void deplacementBas(int **grille, int taille) // mouvement des numeros vers le bas
{
  int nbpiece;
  int tmp;
  int **grilleTmp = creationGrille(taille);
  copieGrille(grille, grilleTmp, taille);
  for (int j = 0; j < taille; j++)
  {
    nbpiece = 1;
    for (int i = taille-1; i > -1; i--)
    {
      if (grille[i][j] != 0 && nbpiece > 1 && grille[taille - nbpiece + 1][j] == grille[i][j] && grilleTmp[taille - nbpiece + 1][j] == grille[i][j]) // deplacement et fusion des cases
      {
        grille[taille - nbpiece + 1][j] *= 2;
        grille[i][j] = 0;
      }
      else if (grille[i][j] != 0) // deplacement uniquement
      {
        tmp = grille[i][j];
        grille[i][j] = 0;
        grilleTmp[i][j] = 0;
        grille[taille - nbpiece][j] = tmp;
        grilleTmp[taille - nbpiece][j] = tmp;
        nbpiece++;
      }
    }
  }
  freeInt2(grilleTmp, taille);
}

int conditionVictoire(int **grille, int taille) // 1 = victoire
{
  int res = 0;
  for (int i = 0; i < taille; i++)
  {
    for (int j = 0; j < taille; j++)
    {
      if (grille[i][j] == 2048)
      {
        res = 1; // si il y a un 2048 le joueur a gagner
      }
    }
  }
  return res;
}

void copieGrille(int **grille, int **grilleTmp, int taille)
{
  for (int i = 0; i < taille; i++)
  {
    for (int j = 0; j < taille; j++)
    {
      grilleTmp[i][j] = grille[i][j]; // copier chaque case d'un tableau a 2 dimensions
    }
  }
}

int comparaisonGrille(int **grille, int **grilleTmp, int taille)
{
  int res = 1;
  for (int i = 0; i < taille; i++)
  {
    for (int j = 0; j < taille; j++)
    {
      if (grille[i][j] != grilleTmp[i][j])
      {
        res = 0; // verifier si grille = grille temp pour chaque 
      }
    }
  }
  return res;
}

int conditionDefaite(int **grille, int taille) //1 == defaite 0 == continue
{
  int **grilleTmp = creationGrille(taille);
  int res = 1;
  copieGrille(grille, grilleTmp, taille);
  deplacementDroit(grilleTmp, taille);
  res = comparaisonGrille(grille, grilleTmp, taille);
  if (res == 1)
  {
    copieGrille(grille, grilleTmp, taille);
    deplacementGauche(grilleTmp, taille);
    res = comparaisonGrille(grille, grilleTmp, taille);
  }
  if (res == 1)
  {
    copieGrille(grille, grilleTmp, taille);
    deplacementHaut(grilleTmp, taille);
    res = comparaisonGrille(grille, grilleTmp, taille);
  }
  if (res == 1)
  {
    copieGrille(grille, grilleTmp, taille);
    deplacementBas(grilleTmp, taille);
    res = comparaisonGrille(grille, grilleTmp, taille);
  }
  freeInt2(grilleTmp, taille);
  return (res);
}

void jeu(SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille)
{
  texture = chargerTextures(window, renderer, texture, taille);
  int partie_en_cours = 1;
  int victoire = 0;
  int **grille = creationGrille(taille);

  while(partie_en_cours)
  {
    tour(grille, window, renderer, texture, taille);
    if (conditionVictoire(grille, taille)) 
    {
      partie_en_cours = 0;
      victoire = 1;
    }
    else if (conditionDefaite(grille, taille)) 
    {
      partie_en_cours = 0;
    }
  }
  afficherGrille(window, renderer, texture, grille, taille);
  messageFin(window, renderer, texture, victoire);
  SDL_Delay(2500);
  freeInt2(grille, 4);
  menuPrincipal(window, renderer, texture);
}

textures chargerTextures(SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille)
{
  if (taille == 4)
  {
    texture = chargerTextures4x4(window, renderer, texture);
  }
  else
  {
    texture = chargerTextures8x8(window, renderer, texture);
  }
  return texture;
}

void messageFin(SDL_Window *window, SDL_Renderer *renderer, textures texture, int victoire)
{
  if (victoire)
  {
    afficherTexture(window, renderer, texture.victoire, texture, -1, -1); // On affiche la victoire
    SDL_RenderPresent(renderer);
  }
  else
  {
    afficherTexture(window, renderer, texture.defaite, texture, -1, -1); // On affiche la defaite
    SDL_RenderPresent(renderer);
  }
}

void tour(int **grille, SDL_Window *window, SDL_Renderer *renderer, textures texture, int taille)
{
  int **grilleTmp = creationGrille(taille);
  copieGrille(grille, grilleTmp, taille);
  afficherGrille(window, renderer, texture, grille, taille);
  if(deplacement(grille, taille)) {
      destructionTout(window, renderer, texture);
      freeInt2(grille, taille);
      exit(EXIT_SUCCESS);
  }
  if (!comparaisonGrille(grille, grilleTmp, taille))
  {
    randomCaseVide(grille, taille);
  }
  freeInt2(grilleTmp, taille);
}

int deplacement(int **grille, int taille)
{
    int continuer = 1;
    int finProg = 0;

    while (continuer)
    {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                deplacementHaut(grille, taille);
                continuer = 0;
                break;
            case SDLK_DOWN:
                deplacementBas(grille, taille);
                continuer = 0;
                break;
            case SDLK_LEFT:
                deplacementGauche(grille, taille);
                continuer = 0;
                break;
            case SDLK_RIGHT:
                deplacementDroit(grille, taille);
                continuer = 0;
                break;
            default:
                break;
            }
            break;
        case SDL_QUIT :
            continuer = 0;
            finProg = 1;
            break;
        default:
            break;
        }
    }
    return(finProg);
}

coord recupererClick(void)
{ // recuperer un clique sur la fenetre graphique
  coord coordClick;
  int continuer = 1;
  while (continuer)
  {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
      coordClick.i = event.button.y;
      coordClick.j = event.button.x;
      continuer = 0;
      break;
    
    case SDL_QUIT:
      coordClick.i = -1;
      continuer = 0;
      break;

    default:
      break;
    }
  }
  return coordClick;
}

void menuPrincipal(SDL_Window *window, SDL_Renderer *renderer, textures texture)
{
    destructionTextures(texture);
    texture = initTextures(texture);
    coord click;
    int demanderClick = 1;

    // On charge et affiche le manu
    texture.menu = creationTexture(window, renderer, texture.menu, texture, "src/images/menu_principal.png");
    afficherTexture(window, renderer, texture.menu, texture, -1, -1);
    SDL_RenderPresent(renderer);

    // On recupere le click du joueur
    while (demanderClick) {
      click = recupererClick();
      if (click.i == -1)  // Si il clique sur la croix on ferme le programme
      {
        destructionTout(window, renderer, texture);
        exit(EXIT_SUCCESS);
      }
      if (click.j >= 150 && click.j <= 540) // Si il clique dans la colonne correspondant aux boutons :
      {
        if (click.i >= 250 && click.i <= 300) // Si il clique sur 4x4 :
        {
          jeu(window, renderer, texture, 4);
        }
        if (click.i >= 350 && click.i <= 400) // Si il clique sur 8x8 :
        {
          jeu(window, renderer, texture, 8);
        }
      }
    }    
}
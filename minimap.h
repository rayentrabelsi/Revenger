#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

typedef struct
{
  SDL_Surface *img[3];
  SDL_Rect[3];
}minimap;

void initminimap( minimap * m);
void MAJMinimap(SDL_Rect posJoueur , minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen)
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);


#endif // MINIMAP_H_INCLUDED 

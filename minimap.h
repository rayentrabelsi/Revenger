#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}ennemi;
typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}image;
typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *obs;
}obstacle;
typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}perso;
void initminimap( minimap * m);
void MAJMinimap(SDL_Rect posJoueur , minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen)
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);


#endif // MINIMAP_H_INCLUDED

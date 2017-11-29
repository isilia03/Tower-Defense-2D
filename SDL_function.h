#ifndef SDL_FUNCTION_H_INCLUDED
#define SDL_FUNCTION_H_INCLUDED

#include "SDL_init.h"


typedef struct cases
{
    SDL_Rect position_cases;
    int contenu; // si 0 alors vide sinon occupee par un ennemi ou une tour
    int autorise; // si 0 autorise pour les tours sinon pour les ennemis
}cases;

void pause();
SDL_Rect* init_plateau_jeu();
SDL_Surface** init_jeu(SDL_Rect* position3, SDL_Surface** Surface);
void free_SDL_Surface3(SDL_Surface** Surface);
void free_Sdl(SDL_Surface** Surface,SDL_Rect* position3);



#endif // SDL_FUNCTION_H_INCLUDED

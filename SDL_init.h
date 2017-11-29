#ifndef SDL_INIT_H_INCLUDED
#define SDL_INIT_H_INCLUDED
#include <SDL/SDL.h>


//-----------------------------------

//---------------------------------------
SDL_Rect* init_SDL_Rect();
SDL_Surface** init_SDL_Surface(SDL_Rect* position);
void free_SDL_Surface(SDL_Surface** Surface);

SDL_Surface ** init_SDL_Mode(SDL_Surface **Surface,SDL_Rect *position_mode);
void free_SDL_Mode(SDL_Surface ** mode);
SDL_Rect * init_SDL_position_mode();

void free_Sdl(SDL_Surface ** mode,SDL_Surface** Surface,SDL_Rect* position,SDL_Rect* position_mode);

#endif // SDL_INIT_H_INCLUDED

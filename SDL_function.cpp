#include "SDL_function.h"


//---------------------------------------
void pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

SDL_Rect* init_plateau_jeu()
{
    SDL_Rect* position3=(SDL_Rect*)malloc(sizeof(SDL_Rect)*3);
    position3[0].x = 0;
    position3[0].y = 0;
    position3[1].x = 270;
    position3[1].y = 0;

return position3;
}

SDL_Surface** init_jeu(SDL_Rect* position3, SDL_Surface** Surface)
{

    SDL_Surface** jeu= (SDL_Surface**)malloc(sizeof(SDL_Surface*)*2);

    jeu[0] = SDL_LoadBMP("./img/decor.bmp");
    SDL_BlitSurface(jeu[0], NULL, Surface[0], &position3[0]);
    jeu[1] = SDL_LoadBMP("./img/plateau1.bmp");
    SDL_BlitSurface(jeu[1], NULL, Surface[0], &position3[1]);


  return  Surface;
}

void free_SDL_Surface3(SDL_Surface** Surface)
{
    int i;
    for(i=0;i<2;i++)
    {SDL_FreeSurface(Surface[i]);}
    free(Surface);
}

void free_Sdl(SDL_Surface** Surface,SDL_Rect* position3)
{
    free_SDL_Surface3(Surface);

    free(position3);
}


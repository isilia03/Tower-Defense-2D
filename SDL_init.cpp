#include "SDL_init.h"


//---------------------------------------
SDL_Rect* init_SDL_Rect()
{
    //  0= position     1=position_quitter  2=position_image    3=position_logo     4=position_jouer;


    SDL_Rect* position=(SDL_Rect*)malloc(sizeof(SDL_Rect)*5);
    position[0].x = 425;
    position[0].y = 40;
    position[2].x = 0;
    position[2].y = 0;
    position[3].x = 0;
    position[3].y = 500;
    position[4].x = 465;
    position[4].y = 225;
    position[1].x = 465;
    position[1].y = 390;

return position;
}

SDL_Surface** init_SDL_Surface(SDL_Rect* position)
{
/*0= ecran  1=image_de_fond     2=nom_jeu   3=logo  4=jouer     5=quitter*/
   SDL_Surface** Surface=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*6);

    Surface[0] = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE);
    Surface[1] = SDL_LoadBMP("./img/fond.bmp");
    SDL_BlitSurface(Surface[1], NULL, Surface[0], &position[2]);
    Surface[2] = SDL_LoadBMP("./img/titre.bmp");
    SDL_SetColorKey(Surface[2], SDL_SRCCOLORKEY, SDL_MapRGB(Surface[2]->format, 195, 195, 195));
    SDL_BlitSurface(Surface[2], NULL, Surface[0], &position[0]);
    Surface[3] = SDL_LoadBMP("./img/logo.bmp");
    SDL_SetColorKey(Surface[3], SDL_SRCCOLORKEY, SDL_MapRGB(Surface[3]->format, 255, 255, 255));
    SDL_BlitSurface(Surface[3], NULL, Surface[0], &position[3]);
    Surface[4] = SDL_LoadBMP("./img/jouer.bmp");
    SDL_SetColorKey(Surface[4], SDL_SRCCOLORKEY, SDL_MapRGB(Surface[4]->format, 34, 177, 76));
    SDL_BlitSurface(Surface[4], NULL, Surface[0], &position[4]);
    Surface[5] = SDL_LoadBMP("./img/quitter.bmp");
    SDL_SetColorKey(Surface[5], SDL_SRCCOLORKEY, SDL_MapRGB(Surface[5]->format, 34, 177, 76));
    SDL_BlitSurface(Surface[5], NULL, Surface[0], &position[1]);


  return  Surface;
}

void free_SDL_Surface(SDL_Surface** Surface)
{
    int i;
    for(i=0;i<6;i++)
    {SDL_FreeSurface(Surface[i]);}
    free(Surface);


}


SDL_Surface ** init_SDL_Mode(SDL_Surface **Surface,SDL_Rect *position_mode)
{
    /*0=choix_mode   1=facile   2=moyen     3=difficile */
    SDL_Surface** mode=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*4);

    mode[0] = SDL_LoadBMP("./img/modechoix.bmp");
    SDL_SetColorKey(mode[0], SDL_SRCCOLORKEY, SDL_MapRGB(mode[0]->format, 0, 162, 232));
    SDL_BlitSurface(mode[0], NULL, Surface[0], &position_mode[0]);
    mode[1] = SDL_LoadBMP("./img/facile.bmp");
    SDL_SetColorKey(mode[1], SDL_SRCCOLORKEY, SDL_MapRGB(mode[1]->format, 0, 162, 232));
    SDL_BlitSurface(mode[1], NULL, Surface[0], &position_mode[1]);
    mode[2] = SDL_LoadBMP("./img/moyen.bmp");
    SDL_SetColorKey(mode[2], SDL_SRCCOLORKEY, SDL_MapRGB(mode[2]->format, 0, 162, 232));
    SDL_BlitSurface(mode[2], NULL, Surface[0], &position_mode[2]);
    mode[3] = SDL_LoadBMP("./img/difficile.bmp");
    SDL_SetColorKey(mode[3], SDL_SRCCOLORKEY, SDL_MapRGB(mode[3]->format, 0, 162, 232));
    SDL_BlitSurface(mode[3], NULL, Surface[0], &position_mode[3]);


  return mode;
}
void free_SDL_Mode(SDL_Surface ** mode)
{
    int i;
    for(i=0;i<4;i++)
    {SDL_FreeSurface(mode[i]);}
      free(mode);
}

SDL_Rect * init_SDL_position_mode()
{
    /*0=position_mode   1=position_facile   2=position_moyen    3=position_difficile */

   SDL_Rect* position_mode=(SDL_Rect*)malloc(sizeof(SDL_Rect)*4);
    position_mode[0].x = 425;
    position_mode[0].y = 0;
    position_mode[1].x = 465;
    position_mode[1].y = 140;
    position_mode[2].x = 465;
    position_mode[2].y = 285;
    position_mode[3].x = 465;
    position_mode[3].y = 430;

    return position_mode;
}
void free_Sdl(SDL_Surface ** mode,SDL_Surface** Surface,SDL_Rect* position,SDL_Rect* position_mode)
{
    free_SDL_Mode(mode);
    free_SDL_Surface(Surface);

    free(position);
    free(position_mode);


}







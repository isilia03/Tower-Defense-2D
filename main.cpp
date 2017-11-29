#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "niveau.h"


void choix(int ok, SDL_Surface** Surface)
{
    printf("choix %d\n", ok);
    switch(ok)
    {case 0:niveau_facile(Surface);
            break;
     case 2:niveau_moyen(Surface);
            break;
     case 3:niveau_difficile(Surface);
            break;
     default:niveau_facile(Surface);
            break;
    }
}

/*
fonction a faire

faire une fonction fin du programme


*/





int main ( int argc, char** argv )
{

    fprintf (stderr, "m");
    int continuer = 0;
    SDL_Rect souris={0,0};
    int ok = 1;


    SDL_Rect* position=init_SDL_Rect();
    SDL_Surface **Surface=init_SDL_Surface(position);

    SDL_Rect* position_mode=NULL;
    SDL_Surface ** mode=NULL;

    SDL_Event event; // variable pour gérer les évènements du programme


    SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER);

    SDL_WM_SetCaption("Wolf Defense", NULL);


    SDL_Flip(Surface[0]);

    // fin affichage menu principal
    // saisie réponse de l utilisateur


//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ function a faire a partir du code suivant §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


    do
    {continuer=1;
        while (continuer==1)
        {
            SDL_WaitEvent(&event); // Récupération de l'événement dans event
            switch(event.type) // Test du type d'événement
            {
                case SDL_QUIT:
                    continuer = 2;//par defaut mettre la fonction quitter quand elle sera ok
                    break;
                case SDL_MOUSEBUTTONDOWN: // Clic de la souris
                    souris.x = event.button.x;
                    souris.y = event.button.y;
                    continuer = 0;
                    break;
            }
        }
        // bouton jouer
        if (((souris.x >= 465) && (souris.x <= 956 )) && ((souris.y >= 225) && (souris.y <= 375)))
        {
            ok = 0;
            fprintf (stderr, "bouton jouer :");
        }
        else if ((((souris.x >= 465) && (souris.x <= 956)) && ((souris.y >= 390) && (souris.y <= 540)))||continuer == 2)
        {
            free_SDL_Surface(Surface);
            fprintf (stderr, "bouton quitter :");

            SDL_Quit();
            return EXIT_SUCCESS;
        }
        else// toujour mettre le else
        {

        }

    }while (ok == 1);


    position_mode=init_SDL_position_mode();

    position[1].x = 465;
    position[1].y = 570;

    // affichage menu mode de jeu

    SDL_BlitSurface(Surface[1], NULL, Surface[0], &position[2]);
    SDL_BlitSurface(Surface[5], NULL, Surface[0], &position[1]);
    SDL_BlitSurface(Surface[3], NULL, Surface[0], &position[3]);

    mode=init_SDL_Mode(Surface,position_mode);

    SDL_Flip(Surface[0]);
    ok = 0;

    // fin affichage menu pour les modes de jeu
    // recuperation des coordonnes pour la saisie du choix de monde
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ function a faire a partir du code suivant §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
    do
    {continuer = 1;
        while (continuer )// tu reste ici tt le temp §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ => mettre une sortie sue le mousse
            {
                SDL_WaitEvent(&event); // Récupération de l'événement dans event
                switch(event.type) // Test du type d'événement
                {
                    case SDL_QUIT:
                        continuer = 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN: // Clic de la souris
                        souris.x = event.button.x;
                        souris.y = event.button.y;
                        continuer = 0;
                        break;

                }
            }

            if (((souris.x >= 465) && (souris.x <= 956 )) && ((souris.y >= 140) && (souris.y <= 288)))
            {
                ok = 0;
                fprintf (stderr, "bouton facile :");
            }
            else if (((souris.x >= 465) && (souris.x <= 956 )) && ((souris.y >= 285) && (souris.y <= 433)))
            {
                ok = 2;
                fprintf (stderr, "bouton moyen :");
            }
            else if (((souris.x >= 465) && (souris.x <= 956 )) && ((souris.y >= 570) && (souris.y <= 578)))
            {
                ok = 3;
                fprintf (stderr, "bouton difficile :");
            }
            else if (((souris.x >= 465) && (souris.x <= 956 )) && ((souris.y >= 570) && (souris.y <= 718)))// cela correspond a quoi?
            {
               free_Sdl(mode,Surface, position,position_mode);
               fprintf (stderr, "bouton quitter2 :");
                SDL_Quit();
                return EXIT_SUCCESS;
            }
            else// mettre le cas ou c'est pas dans les autre
            {

            }

    }while (ok == 1);
    /*utiliser une autre varibable que ok (si tu mets dans une fonction tu peux garder) mais sinn mm si
    il ya 0 chance que l'autre utilisation gene faut le faire*/
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


    choix(ok, Surface);

    free_Sdl(mode,Surface, position,position_mode);


    SDL_Quit();
    return EXIT_SUCCESS;
}



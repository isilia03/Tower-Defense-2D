#include "niveau.h"



void niveau_facile (SDL_Surface** Surface)
{

    int continuer = 1;


    SDL_Rect* position3 = init_plateau_jeu();

    SDL_Surface** jeu = init_jeu(position3, Surface);


    SDL_Flip(Surface[0]);

    // plateau
    cases** plateau=new cases*[15];
    for(int i=0;i<=15;i++)
        {
            plateau[i]=new cases[17];
        }

    int i = 0;
    int j = 0;
    int cpt = 0;
    int n = 8;
    int fin = 0;
    fprintf (stderr, "plateau et decor :");


    for (i = 0; i < 15; i ++)
    {
        for (j = 0; j < 17; j ++)
        {
            plateau [i][j].position_cases.x = 293 + (j*2*23);
            plateau [i][j].contenu = 0; // ici vide car initilisation plateau
            plateau [i][j].autorise = 0;
        }
        plateau[i][j].position_cases.y = 23 + (i*2*23);
    }

    // remplissage pour cases pour le parcours des unites ennemies
    niveau_facile_definition_terrain(plateau);

   plateau=niveau_facile_definition_terrain(plateau);

    SDL_Surface* jeu_ennemis[4];
    SDL_Rect position_ennemis[4];
    position_ennemis[0].x = 900;
    position_ennemis[0].y = 50;
    position_ennemis[1].x = 900;
    position_ennemis[1].y = 0;
    position_ennemis[2].x = 900;
    position_ennemis[2].y = 0;
    position_ennemis[3].x = 900;
    position_ennemis[3].y = 0;
    fprintf (stderr, "ennemis :");
    SDL_Flip(Surface[0]);

    jeu_ennemis[0] = SDL_LoadBMP("./img/loup.bmp");
    SDL_BlitSurface(jeu_ennemis[0], NULL, Surface[0], &position_ennemis[0]);
    jeu_ennemis[1] = SDL_LoadBMP("./img/loup.bmp");
    SDL_BlitSurface(jeu_ennemis[1], NULL, Surface[0], &position_ennemis[1]);
    jeu_ennemis[2] = SDL_LoadBMP("./img/loup.bmp");
    SDL_BlitSurface(jeu_ennemis[2], NULL, Surface[0], &position_ennemis[2]);
    jeu_ennemis[3] = SDL_LoadBMP("./img/loup.bmp");
    SDL_BlitSurface(jeu_ennemis[3], NULL, Surface[0], &position_ennemis[3]);
    SDL_Flip(Surface[0]);
    fprintf (stderr, "ennemis 2\n");

    //SDL_Rect souris;
    //int c = 1;
    //SDL_Event event;
    SDL_Rect positionTour;
    positionTour.x = 0;
    positionTour.y = 0;

    SDL_Surface *tour = SDL_LoadBMP("./img/tour1.bmp");
    fprintf (stderr, "step 3\n");
    SDL_BlitSurface(tour, NULL, Surface[0], &positionTour);
    SDL_Flip(Surface[0]);

/*
    fprintf (stderr, "step 4\n");

        while (continuer)
        {
        SDL_WaitEvent(&event); // Récupération de l'événement dans event
        switch(event.type) // Test du type d'événement
        {
            case SDL_QUIT:
            continuer = 0;//par defaut mettre la fonction quitter quand elle sera ok
            break;
            case SDL_MOUSEBUTTONDOWN: // Clic de la souris
            positionTour.x = event.button.x;
            positionTour.y = event.button.y;
            break;
            }
    }
    SDL_FillRect(Surface[0], NULL, SDL_MapRGB(Surface[0]->format, 255, 255, 255));
    SDL_BlitSurface(tour, NULL, Surface[0],&positionTour);
    fprintf (stderr, "tour:");
    SDL_Flip(Surface[0]);
    free(tour);*/
    free_Sdl(Surface, position3);

}

void niveau_moyen (SDL_Surface** Surface)
{

}

void niveau_difficile (SDL_Surface** Surface)
{

}
cases**  niveau_facile_definition_terrain(cases **plateau)
{


    int cmp=65;
     // remplissage pour cases pour le parcours des unites ennemies


    for(int i=0;i<=2;i++)//65-63
    {plateau[2][i].autorise = cmp--;}

    plateau[3][2].autorise =  cmp--;//62

    for(int i=2;i<=6;i++)//61-57
    {plateau[4][i].autorise =cmp--;}

    plateau[3][6].autorise = cmp--;//56

     for(int i=6;i<=10;i++)//55-51
    {plateau[2][i].autorise = cmp--;}

    for(int i=6;i<=10;i++)//50-48
    {plateau[i][10].autorise = cmp--;}

    for(int i=10;i>=3;i--)//47-40
    {plateau[6][i].autorise = cmp--;}

    for(int i=6;i<=13;i++)//39-32
    {plateau[i][2].autorise = cmp--;}

    for(int i=3;i<=8;i++)//31-26
    {plateau[13][10].autorise = cmp--; }

    for(int i=12;i>=9;i--)//25-22
    {plateau[i][8].autorise = cmp--;}

    for(int i=9;i<=11;i++)//21-19
    {plateau[9][i].autorise = cmp--;}

    for(int i=10;i<=12;i++)//18-16
    {plateau[i][11].autorise = cmp--;}

    for(int i=12;i<=14;i++)//15-13
    { plateau[12][i].autorise = cmp--;}

     for(int i=11;i>=2;i--)//12-3
    {plateau[i][14].autorise = cmp--;}

    for(int i=15;i<=16;i++)//2-1
    {plateau[2][i].autorise = cmp--;}

    plateau[2][16].contenu = 1; // premier ennemis à placer
    return plateau;
}

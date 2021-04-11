#include "func.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *perso = NULL , *backg = NULL ,*collisionMap = NULL , *timer=NULL;
    TTF_Font *police=NULL;
    SDL_Color noir = {0, 0, 0};
    SDL_Rect positionperso , positionbackg ,positionmsq;
    SDL_Event event;
    //SDL_TimerID time;
    int continuer = 1;
    minimap minimapp;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    int tempsPrecedent =0;
    int tempsActuel=0;
    //int time=0;
    temps t;
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);
    police= TTF_OpenFont("spacerangeracad.ttf",65);
    collisionMap = IMG_Load("map2collision.jpg");
    backg = IMG_Load("map2.jpg");
    perso = IMG_Load("down1.png");
    
    positionperso.x =50;
    positionperso.y = 50;
    positionbackg.x=0;
    positionbackg.y=0;
    positionmsq.x=0;
    positionmsq.y=0;
   //timer = SDL_AddTimer(1000, affichertemps, &positionZozor); /* Démarrage du timer */
   initialiser_temps(&t);
   initialiser_minimap(&minimapp,positionperso);
    
  SDL_EnableKeyRepeat(10, 10);
    while (continuer)
    {
     
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                    positionperso.y-=5;
                    if(collisionParfaite(collisionMap,positionperso, positionmsq)==1){ // Flèche haut
                        positionperso.y+=5;
                        }
                        break;
                    case SDLK_DOWN:
                    positionperso.y+=5;
                    if(collisionParfaite(collisionMap,positionperso, positionmsq)==1){ // Flèche bas
                        positionperso.y-=5;
                        }
                        break;
                    case SDLK_RIGHT:
                    positionperso.x+=5;
                    if(collisionParfaite(collisionMap,positionperso, positionmsq)==1){ // Flèche droite
                        positionperso.x-=5;
                        }
                        break;
                    case SDLK_LEFT:
                    positionperso.x-=5;
                    if(collisionParfaite(collisionMap,positionperso, positionmsq)==1){ // Flèche gauche
                        positionperso.x+=5;
                        }
                        break;
                }
                break;
        }
    
         //affichertemps (time,timer,noir,police,ecran);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(backg, NULL, ecran, &positionbackg);
        SDL_BlitSurface(perso, NULL, ecran, &positionperso);
        afficher_minimap(minimapp,positionperso,ecran);
        afficher_temps(&t,ecran);
        SDL_Flip(ecran);
    }
    free_temps(&t,ecran);
    SDL_FreeSurface(perso);
    SDL_FreeSurface(backg);
    SDL_FreeSurface(collisionMap);
    TTF_CloseFont(police); 
    SDL_Quit();

    return EXIT_SUCCESS;
}

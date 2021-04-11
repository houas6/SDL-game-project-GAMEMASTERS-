#include "func.h"
SDL_Color GetPixel (SDL_Surface* pSurface , pos tab)
{
    int x,y;
    x = tab.x;
    y = tab.y;
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}

int collisionParfaite(SDL_Surface *backgmasque , SDL_Rect posperso , SDL_Rect backgmasq)
{
	SDL_Color couleur , colorob;
	couleur.r=255;
	couleur.g=255;
	couleur.b=255;
	pos poss[8];
	poss[0].x =posperso.x;
	poss[0].y = posperso.y;
	poss[1].x =posperso.x + (posperso.w/2);
	poss[1].y = posperso.y;
	poss[2].x =posperso.x + (posperso.w);
	poss[2].y = posperso.y;
	poss[3].x =posperso.x;
	poss[3].y = posperso.y + (posperso.h/2);
	poss[4].x =posperso.x;
	poss[4].y = posperso.y + (posperso.h);
	poss[5].x = posperso.x + (posperso.w/2);
	poss[5].y = posperso.y + (posperso.h);
	poss[6].x =posperso.x + (posperso.w);
	poss[6].y = posperso.y + (posperso.h);
	poss[7].x =posperso.x + (posperso.w);
	poss[7].y = posperso.y + (posperso.h/2);
	
	int collision =0;
	int i;
	  
	for(i=0;i<8 && !collision;i++){
	
	 colorob = GetPixel (backgmasque , poss[i]);
	   if(colorob.r==255 && colorob.g==255 && colorob.b==255){
	     collision = 1;
	   }
	
	}
	printf("%d",collision);
	return collision;
	
}

void initialiser_minimap(minimap* map , SDL_Rect pos){
    map->minimape = IMG_Load("minimap.jpg");
    map->posminimap.x = 512;
    map->posminimap.y = 240;
    map->miniperso = IMG_Load("miniperso.png");
    map->posminiperso.x = pos.x * 20/100;
    map->posminiperso.y = pos.y * 20/100;
}    

void afficher_minimap(minimap m, SDL_Rect pos,SDL_Surface* screen){
 (pos).x=(pos).x * 20/100 + m.posminimap.x;
 (pos).y=(pos).y * 20/100 + m.posminimap.y;
 SDL_BlitSurface(m.minimape,NULL,screen,&m.posminimap);
 SDL_BlitSurface(m.miniperso,NULL,screen,&pos);
}

/*void affichertemps (int time , SDL_Surface *timer , SDL_Color noir, TTF_Font *police , SDL_Surface *screen){
	SDL_Rect postimer;
	char s_time [5];
	sprintf (s_time, "%d", time);
	timer =TTF_RenderText_Blended(police,s_time,noir);
	postimer.x =50;
	postimer.y = 50;
	SDL_BlitSurface(timer,NULL,screen,&postimer);
	printf("\nwaaaaaa\n");
	
}*/

void initialiser_temps(temps *t)
{
	t->texte = NULL; //surface li bech nblitiwha (forme    mm:ss)
	t->position.x=300;
	t->position.y=50;
	t->police = NULL;
	t->police = TTF_OpenFont("spacerangeracad.ttf", 40);
	strcpy(t->entree,"");
	(t->secondesEcoulees)=0;
	time(&(t->t1)); //temps du debut
}

void afficher_temps(temps *t,SDL_Surface *ecran)
{	
	SDL_Color couleurBlanche= {0, 0, 0};
	time(&(t->t2));// temps actuel
	t->secondesEcoulees = t->t2 - t->t1;
	t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	sprintf(t->entree,"%02d:%02d",t->min,t->sec);
	t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
	SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du texte */
  
	//SDL_Delay(80);
 
	
}
void free_temps(temps *t,SDL_Surface *ecran)
{
	SDL_FreeSurface(t->texte);
	TTF_CloseFont(t->police);
}


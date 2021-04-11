#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "func.h"


enigme init_enigme(enigme e)
{
int j,y,xpos;
e.background=IMG_Load("background.png");
e.posbackground.x=0;
e.posbackground.y=0;
e.posbackground.w=e.background->w;
e.posbackground.h=e.background->h;
y=500;
xpos=100;
for(j=0;j<3;j++)
{
e.b[j].bouton=IMG_Load("bouton.png");
e.b[j].pos.y=y;
e.b[j].pos.x=xpos;
xpos+=400;
}
e.flip.bouton=IMG_Load("flip.png");
e.tmp.bouton=IMG_Load("tmp.png");
e.tmp.pos.y=300;
e.tmp.pos.x=441.5;

return e;
}

enigme generer(enigme e)
{
 int x,i;
srand(time(NULL));
e.A=rand()%10+1;
do{
e.B=rand()%10;
e.C=rand()%10;
} while(e.B>e.C || e.B==e.C);
e.X=((float)(e.C-e.B)/(float)(e.A));
e.posvrai=rand()%2;
for(i=0;i<3;i++)
{
if(i==e.posvrai)
{
e.valb[i].val=e.X;
}
else
{

x=rand()%10+3;
e.valb[i].val=x;

}
}
return e;
}

void afficher_equation(enigme e,SDL_Surface *ecran)
{
TTF_Init();
TTF_Font *police=NULL;
SDL_Color couleur={252,190,17};
police=TTF_OpenFont("PIXEARG_.TTF",40);
char equation[30];
sprintf(equation,"%dX+%d=%d |X=?:",e.A,e.B,e.C);
e.equa.pos.x=490;
e.equa.pos.y=360;
e.equa.bouton=TTF_RenderText_Blended(police,equation,couleur);
SDL_BlitSurface(e.equa.bouton,NULL,ecran,&e.equa.pos);

	}

void afficher_valeur(enigme e,SDL_Surface *ecran)
{
 int i,x,posb;
 char bouton[20];
TTF_Init();
TTF_Font *police=NULL;
SDL_Color couleur={253,208,23};
police=TTF_OpenFont("PIXEARG_.TTF",40);
posb=195;
 for(i=0;i<3;i++)
{
sprintf(bouton,"%0.2f",e.valb[i].val);
e.valb[i].bouton=TTF_RenderText_Blended(police,bouton,couleur);
e.valb[i].pos.x=posb;
e.valb[i].pos.y=520;
SDL_BlitSurface(e.valb[i].bouton,NULL,ecran,&e.valb[i].pos);
posb+=400;
}

	}

int resoudreEnigme(enigme *e,int pos)
{

 if(pos==e->posvrai)
return 0;

else
{e->score-=20;
return 1;
}
}


void afficheEnigme(enigme e,SDL_Surface *ecran)
{ int j;
SDL_BlitSurface(e.background,NULL,ecran,&e.posbackground);
SDL_BlitSurface(e.tmp.bouton,NULL,ecran,&e.tmp.pos);
for(j=0;j<3;j++)
{
SDL_BlitSurface(e.b[j].bouton,NULL,ecran,&e.b[j].pos);
}
afficher_equation(e,ecran);
afficher_valeur(e,ecran);
SDL_Flip(ecran);
}
	

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
SDL_Surface *bouton; 
SDL_Rect pos;       
float val;             
} bouton;


typedef struct 
{
 SDL_Surface *background;        
 SDL_Rect posbackground;         
 int A;                          
 int B;                          
 int C;                          
 float X;                          
 int posvrai;                    
 int score; 
 bouton b[3];         
 bouton equa;        
 bouton valb[3]; 
 bouton flip;
 bouton tmp;                 
 } enigme;

enigme init_enigme(enigme e) ;
enigme generer(enigme e);
void afficher_equation(enigme e,SDL_Surface *ecran);
void afficher_valeur(enigme e,SDL_Surface *ecran);
int resoudreEnigme(enigme *e,int pos);
void afficheEnigme(enigme e,SDL_Surface *ecran); 








#include "image.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
SDL_Surface *LoadIMG(char nom[50])
{
	SDL_Surface *img;
	img=IMG_Load(nom);
	if(img==NULL)
	{
		printf("%s faild load",nom);
	}  
	return img;
}

void INIT_IMGB(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=0;
    I->src.y=0;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=0;
    I->dist.y=0;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_IMGB1(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=0;
    I->src.y=0;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=0;
    I->dist.y=0;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_IMGB2(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=0;
    I->src.y=0;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=0;
    I->dist.y=0;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=300;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=300;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player3(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=300;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=300;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player1(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=370;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=370;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player4(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=370;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=370;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player2(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=440;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=440;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player5(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=80;
    I->src.y=440;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=80;
    I->dist.y=440;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player6(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=200;
    I->src.y=70;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=200;
    I->dist.y=70;
    I->dist.w=100;
    I->dist.h=100;
}

void INIT_player7(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=200;
    I->src.y=0;
    I->src.w=0;
    I->src.h=0;

    I->dist.x=200;
    I->dist.y=0;
    I->dist.w=100;
    I->dist.h=100;
}



void displayIMG(image I,SDL_Surface *screen)
{
    SDL_BlitSurface(I.img,NULL,screen,&I.dist);
}


int MouseTest(SDL_Event event ,image P)
{
	if(event.motion.x > P.src.x && event.motion.x < P.src.x + P.src.w && event.motion.y > P.src.y && event.motion.y < P.src.y + P.src.h)
	{return 1;}
	else{return 0;}
}


void clean(SDL_Surface *S)
{
    SDL_FreeSurface(S);
    if(S!=NULL)
        printf("ERROR /> %s\n",SDL_GetError());
}

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>
#include"image.h"
#include"texte.h"
#include"texte.c"

int main(int argc , char *argv[])
{
    SDL_Surface *screen;
    SDL_Event event;
    image I[11];
    texte T;
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0)
    {
        printf("error init \n");
    }
    //texte : 
    TTF_Init();
    INIT_texte(&T,"/home/rayen/jeux1/arial.ttf");
    //sound :
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
      Mix_Music *m;
      m=Mix_LoadMUS("musique.mp3");
      Mix_PlayMusic(m,-1);

          
      Mix_Chunk * son;
      son= Mix_LoadWAV( "effet.wav" );



    INIT_IMGB(&I[0],"background.jpg");
    INIT_player(&I[1],"play.jpg");
    INIT_player1(&I[2],"parametre.jpg");
    INIT_player2(&I[3],"quitter.jpg");
    INIT_player3(&I[4],"plays.jpg");
    INIT_player4(&I[5],"parametres.jpg");
    INIT_player5(&I[6],"quitters.jpg");
    INIT_player6(&I[8],"bouton.png");
    INIT_player7(&I[9],"bouton1.png");
    INIT_IMGB1(&I[7],"/home/rayen/jeux1/backg settings F.jpg");
    INIT_IMGB2(&I[10],"/home/rayen/jeux1/background jeux.png");
    screen=SDL_SetVideoMode(1201,873,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    int loop=1;
    while (loop==1)
    {
        displayIMG(I[0],screen);
        displayIMG(I[1],screen);
        displayIMG(I[2],screen);
        displayIMG(I[3],screen);
        displayText(T,screen);
            SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    loop=0;
                    break;

                      case SDL_KEYUP:
	               if(event.key.keysym.sym ==SDLK_s)
			{
                      while(event.key.keysym.sym !=SDLK_ESCAPE)
                      {
				displayIMG(I[7],screen);
                                displayIMG(I[8],screen);
                                displayIMG(I[9],screen);
                                  if(event.key.keysym.sym ==SDLK_w)
			    {
				Mix_VolumeMusic(MIX_MAX_VOLUME/8);
			    }
			    if(event.key.keysym.sym ==SDLK_v)
			    {
				Mix_VolumeMusic(MIX_MAX_VOLUME);
			    }
                            if(event.key.keysym.sym ==SDLK_f)
			    {
			        screen=SDL_SetVideoMode(1201,873,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN); 
			    }     
				SDL_Flip(screen);
				SDL_PollEvent(&event);
                        switch(event.type)
                        {
                        case SDL_KEYDOWN:
                         
                         if (event.key.keysym.sym ==SDLK_v)
                           {  Mix_PlayChannel(-1,son,0);                                                
                               if(I[8].dist.x<300)
                                 I[8].dist.x=I[8].dist.x+110  ;                                                       
                           }
                                if (event.key.keysym.sym ==SDLK_w)
                                 {  Mix_PlayChannel(-1,son,0);
                                    if(I[8].dist.x>100)
                                      I[8].dist.x=I[8].dist.x-110  ; 
                                 }
                            

                           if (event.key.keysym.sym ==SDLK_ESCAPE)
                        { 
                                screen=SDL_SetVideoMode(1201,873,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
			        displayIMG(I[0],screen);
				displayIMG(I[1],screen);
				displayIMG(I[2],screen);
				displayIMG(I[3],screen);
				displayText(T,screen);
			        SDL_Flip(screen);

			}	
                        }    
                        }
                        break;
                        }
                        
                        if(event.key.keysym.sym ==SDLK_p)
			{
                           Mix_PlayChannel(-1, son, 0);
                      while(event.key.keysym.sym !=SDLK_ESCAPE)
                      {
			        displayIMG(I[10],screen);	
				SDL_Flip(screen);
				SDL_PollEvent(&event);
                        switch(event.type)
                        {
                        case SDL_KEYDOWN:
                           if (event.key.keysym.sym ==SDLK_ESCAPE)
                        {
			        displayIMG(I[0],screen);
				displayIMG(I[1],screen);
				displayIMG(I[2],screen);
				displayIMG(I[3],screen);
				displayText(T,screen);
                                Mix_PlayChannel(-1, son, 0);
			        SDL_Flip(screen);

			}	
                        }    
                        }
                        break;
                        }   
                          
                    break;

      
                     case SDL_KEYDOWN:
                          if(event.key.keysym.sym ==SDLK_p)
                          {
                            Mix_PlayChannel( -1, son, 0 ); 
                            displayIMG(I[4],screen);
                            SDL_Flip(screen);
                          }
                          if(event.key.keysym.sym ==SDLK_s)
                          {
                            Mix_PlayChannel( -1, son, 0 );
                            displayIMG(I[5],screen);
                            SDL_Flip(screen);
                          }
                          if(event.key.keysym.sym ==SDLK_e)
                          { 
                             Mix_PlayChannel( -1, son, 0 ); 
                             displayIMG(I[6],screen);
                             loop=0;
                             SDL_Flip(screen);
                          }
                     

                 
                         
                     case SDL_MOUSEMOTION:
				if(event.motion.x>=78 && event.motion.x<=78+85 && event.motion.y>=302 && event.motion.y<=302+34)
				{
				    displayIMG(I[4],screen);
				    Mix_PlayChannel(-1, son,0);
				}
			        if(event.motion.x>=78 && event.motion.x<=78+124 && event.motion.y>=373 && event.motion.y<=373+34)
				{
				    displayIMG(I[5],screen);
				    Mix_PlayChannel(-1, son, 0);
				}
                                if(event.motion.x>=78 && event.motion.x<=78+70 && event.motion.y>=444 && event.motion.y<=444+34)
				{
				    displayIMG(I[6],screen);
				    Mix_PlayChannel(-1, son, 0);
				}
                                break;
                      
                    case SDL_MOUSEBUTTONDOWN:
                       if(event.motion.x>=78 && event.motion.x<=78+178 && event.motion.y>=444 && event.motion.y<=444+34)
				{
				    loop = 0;
				}
                           break;
                    case SDL_MOUSEBUTTONUP:
				if(event.motion.x>=78 && event.motion.x<=78+178 && event.motion.y>=373 && event.motion.y<=373+34)
				{	    	                  
                      while(event.key.keysym.sym !=SDLK_ESCAPE)
                      {  
                            if(event.key.keysym.sym ==SDLK_w)
			    {
				Mix_VolumeMusic(MIX_MAX_VOLUME/8);
			    }
			    if(event.key.keysym.sym ==SDLK_v)
			    {
				Mix_VolumeMusic(MIX_MAX_VOLUME);
			    }
                                 if (event.key.keysym.sym ==SDLK_v)
                           {                                                 
                               if(I[8].dist.x<300)
                                 I[8].dist.x=I[8].dist.x+110  ;                                                       
                           }
                                if (event.key.keysym.sym ==SDLK_w)
                                 {  
                                    if(I[8].dist.x>100)
                                      I[8].dist.x=I[8].dist.x-110  ; 
                                 }
				displayIMG(I[7],screen); 
                                displayIMG(I[8],screen);
                                displayIMG(I[9],screen);    
				SDL_Flip(screen);
				SDL_PollEvent(&event);
                        switch(event.type)
                        {
                               
                        if (event.key.keysym.sym ==SDLK_ESCAPE)
                        {
			        displayIMG(I[0],screen);
				displayIMG(I[1],screen);
				displayIMG(I[2],screen);
				displayIMG(I[3],screen);
				displayText(T,screen);
			        SDL_Flip(screen);
		 	  }

			}	
                        }
                       break;
			}
                         if(event.motion.x>=78 && event.motion.x<=78+85 && event.motion.y>=302 && event.motion.y<=302+34)
				{
	    	                  
                      while(event.key.keysym.sym !=SDLK_ESCAPE)
                      {
				displayIMG(I[10],screen);	
				SDL_Flip(screen);
				SDL_PollEvent(&event);
                        switch(event.type)
                        {
                        if (event.key.keysym.sym ==SDLK_ESCAPE)
                        {
			        displayIMG(I[0],screen);
				displayIMG(I[1],screen);
				displayIMG(I[2],screen);
				displayIMG(I[3],screen);
				displayText(T,screen);
                                Mix_PlayChannel(-1, son, 0);
			        SDL_Flip(screen);
		 	  }
			}	
                        }
                        break;
                        }
                               
           
            }

        
  SDL_Flip(screen);    
    }
    Mix_FreeChunk( son); 
    screen=NULL;
    I[0].img=NULL;
  clean(screen);
  clean(I[0].img);
  SDL_Quit();
    

    return 0;
}



#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#define m SDL_RESIZABLE
#define fu SDL_FULLSCREEN
 
void pause();
 
int main(int argc, char *argv[])
{int interface=0,sousmenu=0,still=0;
 SDL_Surface *ecran = NULL, *imageDeFond = NULL, *s = NULL ,*f = NULL , *i=NULL;
SDL_Rect positionFond, positionS , positionf ,positioni,positionitaly,positionfrance,positionSapin,positionclic;
 
positionFond.x = 0;
positionFond.y = 0;
positionSapin.x = 300;
positionSapin.y = 100;
positionfrance.x = 300;
positionfrance.y = 200;
positionitaly.x = 300;
positionitaly.y = 300;

 
SDL_Init(SDL_INIT_VIDEO);
 
SDL_WM_SetIcon(IMG_Load("bg.png"), NULL);
 
ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|m);
SDL_WM_SetCaption("pff", NULL);
 
imageDeFond = IMG_Load("bg.png");
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
s = IMG_Load("play.png");
SDL_BlitSurface(s, NULL, ecran, &positionSapin);
 

f = IMG_Load("options.png");

SDL_BlitSurface(f, NULL, ecran, &positionfrance);

i = IMG_Load("quit.png");

SDL_BlitSurface(i, NULL, ecran, &positionitaly);
if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return 0;
    }
Mix_Music *music;
Mix_Chunk *scratch = NULL;
Mix_Chunk *buttonclick = NULL;
music=Mix_LoadMUS("music.mp3");
scratch = Mix_LoadWAV( "scratch.wav" );
buttonclick= Mix_LoadWAV("buttonclick.wav");
if(  scratch == NULL )
{
        return 0;
    }

Mix_VolumeMusic(MIX_MAX_VOLUME);	

SDL_Event event;
  
int done = 1;
int ps=0;
int volume=1;
Mix_PlayMusic(music,-1);
while(done)
{
SDL_BlitSurface(imageDeFond,&positionFond,ecran,NULL);
if(interface==0)
{
if(ps==1)
{
s= IMG_Load("play1.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f= IMG_Load("options.png");
SDL_BlitSurface(f,&positionFond ,ecran,&positionfrance);
i = IMG_Load("quit.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
			
      
     
      
			
}
else if (ps==2)
{
s = IMG_Load("play.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("options1.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("quit.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
}

else if (ps==3)
{
s = IMG_Load("play.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("options.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("quit1.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);

			

}


}
else if(interface==1)
{
if(ps==1)
{
s= IMG_Load("newgame1.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f= IMG_Load("continue.png");
SDL_BlitSurface(f,&positionFond ,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
			
      
     
      
			
}
else if (ps==2)
{
s = IMG_Load("newgame.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("continue1.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
}

else if (ps==3)
{
s = IMG_Load("newgame.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("continue.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return1.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);

			

}


}
else if((interface==2)&&(still==0))
{
if(ps==1)
{
s= IMG_Load("fullscreen1.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f= IMG_Load("sound.png");
SDL_BlitSurface(f,&positionFond ,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
			
      
     
      
			
}
else if (ps==2)
{
s = IMG_Load("fullscreen.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("sound1.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
}

else if (ps==3)
{
s = IMG_Load("fullscreen.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("sound.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return1.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);

			

}

}
else if((interface==3)||((interface==2)&&(still==1)))
{
if(ps==1)
{
s= IMG_Load("minscreen1.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f= IMG_Load("sound.png");
SDL_BlitSurface(f,&positionFond ,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
			
      
     
      
			
}
else if (ps==2)
{
s = IMG_Load("minscreen.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("sound1.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
}

else if (ps==3)
{
s = IMG_Load("minscreen.png");
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
f = IMG_Load("sound.png");
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
i = IMG_Load("return1.png");
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);

			

}

}
SDL_BlitSurface(imageDeFond,&positionFond,ecran,NULL);
SDL_BlitSurface(s,&positionFond,ecran,&positionSapin);
SDL_BlitSurface(i,&positionFond,ecran,&positionitaly);
SDL_BlitSurface(f,&positionFond,ecran,&positionfrance);
    
	
while(SDL_PollEvent(&event))
{
if( event.type == SDL_QUIT )
            {
                //Quit the program
                done=0;
            }		
switch(event.type)
{
case SDL_QUIT:
{case SDL_MOUSEBUTTONDOWN :
{
if (event.button.button == SDL_BUTTON_LEFT)
{
positionclic.x = event.button.x;
positionclic.y = event.button.y;
if ((event.motion.x>300 && event.motion.x<390)&&(event.motion.y>100 && event.motion.y<152))
                 
if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;
                    }
if ((event.motion.x>300 && event.motion.x<390)&&(event.motion.y>185 && event.motion.y<225))
                 
if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;
                    }
if ((event.motion.x>300 && event.motion.x<390)&&(event.motion.y>270 && event.motion.y<386))
                 { 
if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;
                    }
                done=0;
}
		
}
break;}
} break;
case SDL_KEYDOWN:
{
  if(event.key.keysym.sym == SDLK_n)  
{volume++;
Mix_VolumeMusic(MIX_MAX_VOLUME/volume*15); }
  if(event.key.keysym.sym == SDLK_b) 
{volume=1;
Mix_VolumeMusic(MIX_MAX_VOLUME); }      
if (ps==1)
{
if(event.key.keysym.sym == SDLK_RETURN)
{if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;}

 if((ps==1)&&(interface==0))
{                   
interface=1;
}}
}
if((interface==1)&&(ps==1))//new game
{
}
else if((interface==1)&&(ps==2))//continue
{
}		
/*if (ps==2)
{
if(event.key.keysym.sym == SDLK_f)
{ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|fu);}
if(ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|fu))
{
interface=3;
}
if(event.key.keysym.sym == SDLK_m)
{ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|m);}
}*/
if(event.key.keysym.sym == SDLK_RETURN)
{if((interface==2)&&(ps==1))

{ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|fu);
interface=3;
still=1;}
else if((interface==3)&&(ps==1))
{
ecran = SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|m);
interface=2;
still=0;
}
}
if(event.key.keysym.sym == SDLK_RETURN)
{if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;
                    }
if((ps==2)&&(interface==0))
{
interface=2;
}
}
	
if (ps==3)
{
if(event.key.keysym.sym == SDLK_RETURN)
{if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
                    {
                        return 1;
                    }
if ((interface==2)||(interface==1)||(interface==3))
{interface=0;}
else if(interface==0)
{
done=0;}
}	
}		
if(event.key.keysym.sym == SDLK_ESCAPE)
{
done = 0;
}
else if (event.key.keysym.sym == SDLK_UP)
{if( Mix_PlayChannel( -1, buttonclick, 0 ) == -1 )
                    {
                        return 1;
                    }
if (ps==1)
{
ps=3;
}
else
{
ps--;
}
}
               
else if (event.key.keysym.sym == SDLK_DOWN)
{if( Mix_PlayChannel( -1, buttonclick, 0 ) == -1 )
                    {
                        return 1;
                    }
if (ps==3)
{
ps=1;
}
else
{
ps++;
}
}
 break;
}	//case;


	case SDL_MOUSEMOTION:

	{	
		if((event.motion.x>300 && event.motion.x<390) && (event.motion.y>100 && event.motion.y<152))
		{
			ps=1;	
		}
		else if((event.motion.x>300 && event.motion.x<390)&&(event.motion.y>185 && event.motion.y<225))
		{
			ps=2;	
		}
		else if((event.motion.x>300 && event.motion.x<390)&&(event.motion.y>270 && event.motion.y<314))
		{
			ps=3;	
		}
	break;

	}
             
        }


    }
SDL_Flip(ecran);
}
    
   
 
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(s);
SDL_FreeSurface(f);
SDL_FreeSurface(i);
Mix_FreeMusic(music);
Mix_CloseAudio();
Mix_FreeChunk( scratch );
Mix_FreeChunk( buttonclick );
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
 
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
exit(1);
                
        }
    }
}

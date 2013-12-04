#include <iostream>
#include <SDL/SDL.h>
#include "pieces.hpp"

using namespace std;

int main(int argc, char** argv){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(500, 500, 32, SDL_SWSURFACE);
	SDL_Surface* oldImg = SDL_LoadBMP("img.bmp");
	SDL_Surface* img = SDL_DisplayFormat(oldImg);
	SDL_FreeSurface(oldImg);
	SDL_BlitSurface(img, NULL, screen, NULL);
	SDL_Event e;
	SDL_Rect dest;
	SDL_Rect wholeScreen;
	wholeScreen.x = wholeScreen.y = 0;
	wholeScreen.w = wholeScreen.h = 500;
	dest.x = dest.y = 0;
	while(true){
		SDL_WaitEvent(&e);
		if(e.type == SDL_QUIT){
			SDL_FreeSurface(img);
			SDL_Quit();
			return 0;
		}
		if(e.type == SDL_KEYDOWN){
			if(e.key.keysym.sym == SDLK_LEFT) dest.x--;
			else if(e.key.keysym.sym == SDLK_RIGHT) dest.x++;
			else if(e.key.keysym.sym == SDLK_UP) dest.y--;
			else if(e.key.keysym.sym == SDLK_DOWN) dest.y++;
		}

		SDL_FillRect(screen, &wholeScreen, 0x000000FF);
		SDL_BlitSurface(img, NULL, screen, &dest);
		SDL_Flip(screen);
	}
}

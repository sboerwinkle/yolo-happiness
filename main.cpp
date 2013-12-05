#include <iostream>
#include "pieces.hpp"
#include "board.hpp"


using namespace std;

Board Brd;

SDL_Surface* loadImg(char* name){
	SDL_Surface* old = SDL_LoadBMP(name);
	SDL_Surface* ret =  SDL_DisplayFormat(old);
	SDL_FreeSurface(old);
	return ret;
}

int main(int argc, char** argv){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(500, 500, 32, SDL_SWSURFACE);
	pawnImg = loadImg("pawn.bmp");
	bishopImg = loadImg("bishop.bmp");
	kingImg = loadImg("king.bmp");
	rookImg = loadImg("rook.bmp");
	Brd = Board(); // Delay until after the image pointers are established
	SDL_Event e;
	SDL_Rect dest;
	dest.w = dest.h = 40;
	SDL_Rect wholeScreen;
	wholeScreen.x = wholeScreen.y = 0;
	wholeScreen.w = wholeScreen.h = 500;
	while(true){
		SDL_WaitEvent(&e);
		if(e.type == SDL_QUIT){
			SDL_FreeSurface(pawnImg);
			SDL_FreeSurface(rookImg);
			SDL_FreeSurface(kingImg);
			SDL_FreeSurface(bishopImg);
			SDL_Quit();
			return 0;
		}
		if(e.type == SDL_KEYDOWN){
		}

		SDL_FillRect(screen, &wholeScreen, 0xFF000000);
		int j, i = 0;
		for(; i < 8; i++){
			dest.x = 40*i + 40;
			for(j = 0; j < 8; j++){
				if(Brd.getPiece(i, j)->getType() == BLANK) continue;
				dest.y = 40*j + 40;
				Brd.getPiece(i, j)->draw(screen, &dest);
			}
		}
		SDL_Flip(screen);
	}
}

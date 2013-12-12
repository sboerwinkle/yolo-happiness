#include <iostream>
#include "pieces.hpp"
#include "board.hpp"


using namespace std;

Board Brd;

int phase = 0; //White choose piece, white move, black choose piece, black move.
int selectedX, selectedY;

SDL_Surface* loadImg(const char* name){
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
	queenImg = loadImg("queen.bmp");
	knightImg = loadImg("knight.bmp");
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
		if(e.type == SDL_MOUSEBUTTONDOWN){
			int x = (e.button.x-90)/40;
			int y = (e.button.y-90)/40;
			if(phase%2){
				if(Brd.getPiece(x,y)->getType() != BLANK && (Brd.getPiece(x,y)->getColour() == WHITE) == (phase == 1)) continue; //Moving into a friendly unit's space
				Brd.move(selectedX, selectedY, x, y);
				phase++;
				if(phase == 4) phase = 0;
			}else{
				if(Brd.getPiece(x,y)->getType() == BLANK || (Brd.getPiece(x,y)->getColour() == WHITE) != (phase == 0)) continue; //Empty space or Wrong color
				selectedX = x;
				selectedY = y;
				phase++;
			}
		}

		SDL_FillRect(screen, &wholeScreen, phase < 2 ? 0xFFFFFFFF : 0xFF000000);
		int j, i = 0;
		dest.w = dest.h = 40;
		dest.x = 50;
		for(; i < 8; i++){
			dest.x += 40;
			dest.y = 50;
			for(j = 0; j < 8; j++){
				dest.y += 40;
				if(Brd.getPiece(i, j)->getType() == BLANK){
					SDL_FillRect(screen, &dest, (i+j)%2?0xFF303030:0xFFCFCFCF);
					continue;
				}
				Brd.getPiece(i, j)->draw(screen, &dest);
			}
		}
		if(phase % 2){ //If it's a movement phase
			dest.x = 40*selectedX+90;
			dest.y = 40*selectedY+90;
			dest.w = 40;
			dest.h = 2;
			SDL_FillRect(screen, &dest, 0xFF0000FF);
			dest.w = 2;
			dest.h = 40;
			SDL_FillRect(screen, &dest, 0xFF0000FF);
			dest.x += 38;
			SDL_FillRect(screen, &dest, 0xFF0000FF);
			dest.x -= 38;
			dest.y += 38;
			dest.w = 40;
			dest.h = 2;
			SDL_FillRect(screen, &dest, 0xFF0000FF);
		}
		SDL_Flip(screen);
	}
}

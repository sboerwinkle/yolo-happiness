#include <iostream>
#include "pieces.hpp"
#include "board.hpp"


using namespace std;

Board Brd;

int phase = 0; //White choose piece, white move, black choose piece, black move.
int selectedX, selectedY;

void loadImg(SDL_Surface** dest, const char* name){
	SDL_Surface* old = SDL_LoadBMP(name);
	SDL_Surface* tmp = SDL_DisplayFormat(old); //Possibly display format the actual pictures?
	dest[0] = SDL_CreateRGBSurface(0, 40, 40, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	SDL_FreeSurface(old);
	dest[1] = SDL_CreateRGBSurface(0, 40, 40, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	SDL_Rect r;
	r.w = r.h = 1;
	Uint32 color;
	int j, i = 0;
	for(; i < 40; i++){
		r.x = i;
		for(j = 0; j < 40; j++){
			r.y = j;
			color = ((Uint8*)tmp->pixels)\
				[j*(tmp->pitch)+\
				i*(tmp->format->BytesPerPixel)]\
				?0:0xFF000000;
			SDL_FillRect(dest[BLACK], &r, color);
			SDL_FillRect(dest[WHITE], &r, color+0xFFFFFF);
		}
	}
	SDL_FreeSurface(tmp);
	SDL_SetAlpha(dest[0], SDL_SRCALPHA, 255);
	SDL_SetAlpha(dest[1], SDL_SRCALPHA, 255);
}

int main(int argc, char** argv){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(500, 500, 32, SDL_SWSURFACE);
	loadImg(pawnImg, "pawn.bmp");
	loadImg(bishopImg, "bishop.bmp");
	loadImg(kingImg, "king.bmp");
	loadImg(rookImg, "rook.bmp");
	loadImg(queenImg, "queen.bmp");
	loadImg(knightImg, "knight.bmp");
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
			int i = 0;
			for(; i < 2; i++){
				SDL_FreeSurface(pawnImg[i]);
				SDL_FreeSurface(rookImg[i]);
				SDL_FreeSurface(kingImg[i]);
				SDL_FreeSurface(bishopImg[i]);
				SDL_FreeSurface(queenImg[i]);
				SDL_FreeSurface(knightImg[i]);
			}
			SDL_Quit();
			return 0;
		}
		if(e.type == SDL_MOUSEBUTTONDOWN){
			int x = (e.button.x-90)/40;
			int y = (e.button.y-90)/40;
			if(x<0 || x>7 || y<0 || y>7) continue;
			if(phase%2){
				if(x == selectedX && y == selectedY)
					phase--;
				else if(Brd.getPiece(selectedX,selectedY)->checkMove(x, y)){
					phase++;
					if(phase == 4) phase = 0;
				}
			}else{
				if(Brd.getPiece(x,y) == NULL || (Brd.getPiece(x,y)->getColour() == WHITE) != (phase == 0)) continue; //Empty space or Wrong color
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
				SDL_FillRect(screen, &dest, (i+j)%2?0xFF303030:0xFFCFCFCF);
				if(Brd.getPiece(i, j) == NULL){
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

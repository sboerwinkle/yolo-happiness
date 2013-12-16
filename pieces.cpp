//#include <cmath>
#include "math.hpp"
#include "pieces.hpp"
#include "board.hpp"
#include <iostream>

using namespace std;

extern Board Brd;

SDL_Surface* pawnImg[2];
SDL_Surface* rookImg[2];
SDL_Surface* kingImg[2];
SDL_Surface* bishopImg[2];
SDL_Surface* knightImg[2];
SDL_Surface* queenImg[2];

Piece newPiece(		int x, 
			int y,	
			piece_t newType=PAWN,
	       		piece_c newColour=BLACK){
	
	switch (newType){
		case PAWN:
			return Pawn( x, y, newColour);
			break;
		case ROOK:
			return Rook( x, y, newColour);
			break;
		case KNIGHT:
			return Knight( x, y, newColour);
			break;
		case BISHOP:
			return Bishop( x, y, newColour);
			break;
		case KING:
			return King( x, y, newColour);
			break;
		case QUEEN:
			return Queen( x, y, newColour);
			break;
		default:
			return Pawn( x, y, newColour);
			break;

	}

}

piece_t Piece::getType(){
	return type;
}

piece_c Piece::getColour(){
	return colour;
}
void Piece::move(int x, int y){
	Brd.move(pos.x, pos.y, x, y);
	pos.x = x;
	pos.y = y;
}

void Piece::draw(SDL_Surface* screen, SDL_Rect* dest){
	if(myImg) SDL_BlitSurface(myImg[colour], NULL, screen, dest);
}

int Piece::checkMove(int x, int y){
	move(x, y);
	return 1;
}
	
int Knight::checkMove(int x, int y){
	if(abs(dist(pos.x-x,pos.y-y)-sqrt(5)) < 0.001
		&& (Brd.enemy(x,y,colour)!=-1)){
		
		move(x,y);
		return 1;
	}else{
		return 0;
	}	
}

int Pawn::checkMove(int x, int y){
	int dir = colour*(-2)+1;
	if(y!=pos.y+dir){
		if(x!=pos.x || y!=pos.y+2*dir || y!=(7-dir)/2 || Brd.enemy(x,pos.y+dir,colour) || Brd.enemy(x,y,colour)) return 0;
		move(x, y);
		return 1;
	}
	switch(Brd.enemy(x, y, colour)){
		case -1: return 0;
		case 0:
			 if(x==pos.x){
				 move(x, y);
				 return 1;
			 }else return 0;
		case 1:
			 if(abs(x-pos.x) == 1){
				 move(x, y);
				 return 1;
			 }else return 0;
	}
	return 666; // Error code of the beast
}

int Bishop::checkMove(int x, int y){
	if(Brd.enemy(x, y, colour) == -1) return 0;
	int dx = x-pos.x;
	int dy = y-pos.y;
	int dist = abs(dx);
	if(dist != abs(dy)) return 0;
	dx /= dist;
	dy /= dist;
	int tmpx = pos.x+dx;
	int tmpy = pos.y+dy;
	while(dist > 1){
		if(Brd.enemy(tmpx, tmpy, colour)) return 0;
		tmpx += dx;
		tmpy += dy;
		dist--;
	}
	move(x, y);
	return 1;
}

int King::checkMove(int x, int y){
	if(abs(x-pos.x) > 1 || abs(y-pos.y) > 1 || Brd.enemy(x, y, colour) == -1) return 0;
	move(x, y);
	return 1;
}

int Queen::checkMove(int x, int y){
	if(abs(x-pos.x) == abs(y - pos.y)){
	}else if(x == pos.x || y == pos.y){
	}else{
		return 0;
	}

	if(Brd.enemy(x,y,colour)==-1) return 0;

	int dx = (int)((x-pos.x)/(abs(x-pos.x)+0.0001)); //set dxdy to one, negative one, or zero.
	int dy = (int)((y-pos.y)/(abs(y-pos.y)+0.0001));

	int tmpx,tmpy;
	for(tmpx = pos.x; tmpx != x; tmpx += dx){
		for(tmpy = pos.y; tmpy != y; tmpy += dy){
			if((Brd.enemy(tmpx,tmpy,colour)==-1)||(Brd.enemy(tmpx,tmpy,colour)==1)) return 0;
		}
	}
	move(x,y);
	return 1;

}

int Rook::checkMove(int x, int y){
	if(!(x==pos.x || y == pos.y)){
		return 0;
	}
	if(Brd.enemy(x,y,colour)==-1) return 0;

	int dx = (int)((x-pos.x)/(abs(x-pos.x)+0.0001)); //Always sets dx/dy to one, negative one, or zero.
	int dy = (int)((y-pos.y)/(abs(y-pos.y)+0.0001));

	int tmpx,tmpy;
	for(tmpx = pos.x; tmpx != x; tmpx += dx){
		for(tmpy = pos.y; tmpy != y; tmpy += dy){
			if((Brd.enemy(tmpx,tmpy,colour)==-1)||(Brd.enemy(tmpx,tmpy,colour)==1)) return 0;
		}
	}
	move(x,y);
	return 1;

}

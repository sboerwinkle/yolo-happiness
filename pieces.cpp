//#include <cmath>
#include "math.hpp"
#include "pieces.hpp"
#include "board.hpp"

using namespace std;

extern Board Brd;

SDL_Surface* pawnImg;
SDL_Surface* rookImg;
SDL_Surface* kingImg;
SDL_Surface* bishopImg;

Piece newPiece(		int x, 
			int y,	
			piece_t newType=PAWN,
	       		piece_c newColor=BLACK){
	
	switch (newType){
		case PAWN:
			return Pawn( x, y, newColor);
			break;
		case ROOK:
			return Rook( x, y, newColor);
			break;
		case KNIGHT:
			return Knight( x, y, newColor);
			break;
		case BISHOP:
			return Bishop( x, y, newColor);
			break;
		case KING:
			return King( x, y, newColor);
			break;
		case QUEEN:
			return Queen( x, y, newColor);
			break;
		default:
			return Pawn( x, y, newColor);
			break;

	}

}

piece_t Piece::getType(){
	return type;
}

piece_c Piece::getColor(){
	return colour;
}
void Piece::move(int x, int y){
	pos.x = x;
	pos.y = y;
}

void Piece::draw(SDL_Surface* screen, SDL_Rect* dest){
	if(myImg) SDL_BlitSurface(myImg, NULL, screen, dest);
}
	
int Knight::checkMove(int x, int y, piece_c c){
	if(abs(dist(abs(pos.x-x),abs(pos.y-y))-sqrt(5)) < 0.001
		&& !Brd.enemy(x,y,c)){
		
		this->move(x,y);
		return 1;
	}else{
		return 0;
	}	
}


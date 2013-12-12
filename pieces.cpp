//#include <cmath>
#include "math.hpp"
#include "pieces.hpp"
#include "board.hpp"

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
	pos.x = x;
	pos.y = y;
}

void Piece::draw(SDL_Surface* screen, SDL_Rect* dest){
	if(myImg) SDL_BlitSurface(myImg[colour], NULL, screen, dest);
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


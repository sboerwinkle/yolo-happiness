#include <SDL/SDL.h>

enum piece_t{
	BLANK,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	KING,
	QUEEN
};

enum piece_c{
	BLACK,
	WHITE
};


struct pt{

	int x,y;

};

extern SDL_Surface* pawnImg;
extern SDL_Surface* rookImg;
extern SDL_Surface* kingImg;
extern SDL_Surface* bishopImg;
extern SDL_Surface* knightImg;
extern SDL_Surface* queenImg;

class Piece{

	public:
		piece_t type;
		piece_c colour;
		pt pos;
		SDL_Surface* myImg;
		
		void draw(SDL_Surface* screen, SDL_Rect* dest);
		piece_t getType();
		piece_c getColour();
		void move(int x, int y);	
};

extern Piece newPiece(int x, int y, piece_t newType, piece_c newColour);



class Pawn: public Piece{
	public:
		Pawn(	int x=0, 
			int y=0, 
			piece_c c = BLACK){

			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = pawnImg;
			type = PAWN;
		}
		
};

class Rook: public Piece{
	public:
		Rook(	int x=0, 
			int y=0, 
			piece_c c = BLACK){

			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = rookImg;
			type = ROOK;
		}

};


class Knight: public Piece{
	public:
		Knight(	int x=0, 
			int y=0, 
			piece_c c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = knightImg;
			type = KNIGHT;
		}
		int checkMove(int x, int y, piece_c c);

	
};

class Bishop: public Piece{
	public:
		Bishop(	int x=0, 
			int y=0, 
			piece_c c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = bishopImg;
			type = BISHOP;
		}
	
};

class King: public Piece{
	public:
		King(	int x=0, 
			int y=0, 
			piece_c c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = kingImg;
			type = KING;
		}

};

class Queen: public Piece{
	public:
		Queen(	int x=0, 
			int y=0, 
			piece_c c = BLACK){

			pos.x = x;
			pos.y = y;
			colour = c;
			myImg = queenImg;
			type = QUEEN;
		}

};


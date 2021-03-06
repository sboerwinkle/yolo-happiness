#include <SDL/SDL.h>
#include <iostream>

using namespace std;

enum piece_t{
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

extern pt enPassant[2];

extern SDL_Surface* pawnImg[2];
extern SDL_Surface* rookImg[2];
extern SDL_Surface* kingImg[2];
extern SDL_Surface* bishopImg[2];
extern SDL_Surface* knightImg[2];
extern SDL_Surface* queenImg[2];

class Piece{

	public:
		piece_t type;
		piece_c colour;
		pt pos;
		SDL_Surface** myImg;
		
		void draw(SDL_Surface* screen, SDL_Rect* dest);
		piece_t getType();
		piece_c getColour();
		void move(int x, int y);	
		virtual int checkMove(int x, int y); //virtual means match fnct. call w/ definition at runtime. Allows for proper overriding.
		virtual ~Piece() {};
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
		virtual int checkMove(int x, int y);
		int checkMoveSub(int x, int y);
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
		virtual int checkMove(int x, int y);
		
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
		int checkMove(int x, int y);
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
	
		int checkMove(int x, int y);
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

		int checkMove(int x, int y);
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

		int checkMove(int x, int y);
};


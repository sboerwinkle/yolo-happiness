#include <stdlib.h>
#include "pieces.hpp"


class Board{
	public:
		Piece array[8][8];

		Board();


};

Board::Board(){
	using namespace Piece;
	array[0][0] = newPiece(ROOK,BLACK);
	array[0][1] = newPiece(KNIGHT,BLACK);
	array[0][2] = newPiece(BISHOP,BLACK);
	array[0][3] = newPiece(KING, BLACK);
	array[0][4] = newPiece(QUEEN,BLACK);
	array[0][5] = newPiece(BISHOP,BLACK);
	array[0][6] = newPiece(KNIGHT,BLACK);
	array[0][7] = newPiece(ROOK,BLACK);
	array[1][0] = newPiece(PAWN,BLACK);
	array[1][1] = newPiece(PAWN,BLACK);
	array[1][2] = newPiece(PAWN,BLACK);
	array[1][3] = newPiece(PAWN,BLACK);
	array[1][4] = newPiece(PAWN,BLACK);
	array[1][5] = newPiece(PAWN,BLACK);
	array[1][6] = newPiece(PAWN,BLACK);
	array[1][7] = newPiece(PAWN,BLACK);
	



}

#include <stdlib.h>

class Board{
	public:
		Piece array[8][8];

		Board();
		int enemy(int x, int y, piece_c c);
		Piece *getPiece(int x, int y);

};


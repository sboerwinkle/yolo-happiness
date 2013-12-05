#include "pieces.hpp"
#include "board.hpp"

Piece * Board::getPiece(int x, int y){
	
	return &(this->array[x][y]);

}

int Board::enemy(int x, int y, piece_c c){
	
	if(this->getPiece(x,y)->getType() == BLANK){
		return 0;
	}else if(this->getPiece(x,y)->colour != c){
		return 1;
	}else{
		return -1;
	}
	
}

Board::Board(){
	int i, j=2;
	for(; j < 6; j++)
		for(i=0; i < 8; i++) array[i][j].type = BLANK;

	for(i = 0; i < 8; i++){
		array[i][1] = Pawn(i, 1, BLACK);
		array[i][6] = Pawn(i, 7, WHITE);
	}
	array[0][0] = Rook(0, 0, BLACK);
	array[1][0] = Knight(0, 0, BLACK);
	array[2][0] = Bishop(0, 0, BLACK);
	array[3][0] = Queen(0, 0, BLACK);
	array[4][0] = King(0, 0, BLACK);
	array[5][0] = Bishop(0, 0, BLACK);
	array[6][0] = Knight(0, 0, BLACK);
	array[7][0] = Rook(0, 0, BLACK);

	array[0][7] = Rook(0, 0, WHITE);
	array[1][7] = Knight(0, 0, WHITE);
	array[2][7] = Bishop(0, 0, WHITE);
	array[3][7] = Queen(0, 0, WHITE);
	array[4][7] = King(0, 0, WHITE);
	array[5][7] = Bishop(0, 0, WHITE);
	array[6][7] = Knight(0, 0, WHITE);
	array[7][7] = Rook(0, 0, WHITE);
}

void Board::move(int x1, int y1, int x2, int y2){
	array[x2][y2] = array[x1][y1];
	array[x1][y1].type = BLANK;

}

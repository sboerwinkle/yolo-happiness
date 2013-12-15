#include "pieces.hpp"
#include "board.hpp"

Piece * Board::getPiece(int x, int y){
	return array[x][y];
}

int Board::enemy(int x, int y, piece_c c){

	if(array[x][y] == NULL){
		return 0;
	}else if(array[x][y]->colour != c){
		return 1;
	}else{
		return -1;
	}
	
}

Board::Board(){
	int i, j=2;
	for(; j < 6; j++)
		for(i=0; i < 8; i++) array[i][j] = NULL;

	for(i = 0; i < 8; i++){
		array[i][1] = new Pawn(i, 1, BLACK);
		array[i][6] = new Pawn(i, 6, WHITE);
	}
	array[0][0] = new Rook(0, 0, BLACK);
	array[1][0] = new Knight(1, 0, BLACK);
	array[2][0] = new Bishop(2, 0, BLACK);
	array[3][0] = new Queen(3, 0, BLACK);
	array[4][0] = new King(4, 0, BLACK);
	array[5][0] = new Bishop(5, 0, BLACK);
	array[6][0] = new Knight(6, 0, BLACK);
	array[7][0] = new Rook(7, 0, BLACK);

	array[0][7] = new Rook(0, 7, WHITE);
	array[1][7] = new Knight(1, 7, WHITE);
	array[2][7] = new Bishop(2, 7, WHITE);
	array[3][7] = new Queen(3, 7, WHITE);
	array[4][7] = new King(4, 7, WHITE);
	array[5][7] = new Bishop(5, 7, WHITE);
	array[6][7] = new Knight(6, 7, WHITE);
	array[7][7] = new Rook(7, 7, WHITE);
}

extern bool victory;

void Board::move(int x1, int y1, int x2, int y2){
	if(array[x2][y2]){
		if(array[x2][y2]->getType() == KING) victory = true;
		delete array[x2][y2];
	}
	array[x2][y2] = array[x1][y1];
	array[x1][y1] = NULL;

}

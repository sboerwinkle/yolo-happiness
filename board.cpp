#include "pieces.hpp"
#include "board.hpp"

Piece * Board::getPiece(int x, int y){
	
	return &(this->array[x][y]);

}

int Board::enemy(int x, int y, piece_c c){
	
	if(this->getPiece(x,y)== NULL){
		return 0;
	}else if(this->getPiece(x,y)->colour != c){
		return 1;
	}else{
		return -1;
	}
	
}

Board::Board(){
	
	//zero unfilled spaces fill sides.


}

void Board::move(int x1, int y1, int x2, int y2){
	array[x2][y2] = array[x1][y1];
	array[x1][y1] = NULL;

}

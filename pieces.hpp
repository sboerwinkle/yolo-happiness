
enum piece_t{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	KING,
	QUEEN
};

enum piece_colour{
	BLACK,
	WHITE
};


class Piece{

	public:
		piece_t type;
		piece_colour colour;

		Piece newPiece(piece_t type);	
		piece_t getType();
		piece_colour getColour();
};

class Pawn: public Piece{

};

class Rook: public Piece{

};

class Knight: public Piece{

};

class Bishop: public Piece{

};

class King: public Piece{

};

class Queen: public Piece{

};


Piece Piece::newPiece(	piece_t newType=PAWN,
	       		piece_colour newColour=BLACK){
	
	switch (newType){
		case PAWN:
			return Pawn();
			break;
		case ROOK:
			return Rook();
			break;
		case KNIGHT:
			return Knight();
			break;
		case BISHOP:
			return Bishop();
			break;
		case KING:
			return King();
			break;
		case QUEEN:
			return Queen();
			break;
		default:
			return Pawn();
			break;

	}

}

piece_t Piece::getType(){
	return type;
}

piece_colour Piece::getColour(){
	return colour;
}

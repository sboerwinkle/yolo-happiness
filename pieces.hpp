
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


struct pt{

	int x,y;

};


class Piece{

	public:
		piece_t type;
		piece_colour colour;
		pt pos;
		
		Piece newPiece(	int x, 
				int y, 
				piece_t type, 
				piece_colour newColour);

		piece_t getType();
		piece_colour getColour();
		void move(int x, int y);	
};

class Pawn: public Piece{
	public:
		Pawn(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){

			pos.x = x;
			pos.y = y;
			colour = c;	
		}
		
};

class Rook: public Piece{
	public:
		Rook(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){
			
			pos.x = x;
			pos.y = y;
			colour = c;	
		}

};

class Knight: public Piece{
	public:
		Knight(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;	
		}

	
};

class Bishop: public Piece{
	public:
		Bishop(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;	
		}
	
};

class King: public Piece{
	public:
		King(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;	
		}

};

class Queen: public Piece{
	public:
		Queen(	int x=0, 
			int y=0, 
			piece_colour c = BLACK){
		
			pos.x = x;
			pos.y = y;
			colour = c;	
		}

};


Piece Piece::newPiece(	int x, 
			int y,	
			piece_t newType=PAWN,
	       		piece_colour newColour=BLACK){
	
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

piece_colour Piece::getColour(){
	return colour;
}
void Piece::move(int x, int y){
	pos.x = x;
	pos.y = y;
}


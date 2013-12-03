
enum piece_t{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	KING,
	QUEEN
};





class Piece{

	public:
		piece_t type;
		Piece(piece_t type);	
		void SetType(piece_t newType);
};

Piece::Piece(piece_t newType=PAWN){
	
	type=newType;

}


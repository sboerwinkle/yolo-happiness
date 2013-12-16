#include "math.hpp"
#include "pieces.hpp"
#include "board.cpp"
#include "board.hpp"


int Rook::checkMove(int x, int y, piece_c)
{
	int orix, oriy, valid;
	orix = x;
	oriy = y;

	if ( pos.x != x)
		pos.y = y;
	if (pos.y != y)
		pos.x = x;

	valid = 1;


	if ((pos.x > x))
	{
		for (pos.x ; pos.x > x; pos.x--)
		{
			if (Piece[pos.x][y] != BLANK)
				valid = 0;
		}
	}

	else 
		if (x > pos.x)
	{
		for (pos.x ; pos.x < x; pos.x++)
		{
			if (Piece[pos.x][y] != BLANK)
				valid = 0;
		}
	}

		else
			if (pos.y > y)
			{
				for (pos.y; pos.y > y; pos.y--)
				{
					if (Piece[x][pos.y] != BLANK)
					valid = 0;
				}
			}

			else
				if (y > pos.y)
				{
					for (pos.y; pos.y < y; pos.y++)
					{
						if (Piece[x][pos.y] != BLANK)
						valid = 0;
					}
				}

		
		if (int Brd::enemy[x][y] == -1)
		{
			valid = 0;
		}

	}

	if (valid == 0)
	{
		pos.x = orix;
		pos.y = oriy;
	}
	
	else
	{
		pos.x = x;
		pos.y = y;
	}

	return valid;
}

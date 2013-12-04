
#include <iostream>
#include "pieces.hpp"

using namespace std;

int main(int argc, char** argv){
	Piece p;
	p = Piece(QUEEN);
	if(p.type == QUEEN) cout << "it's alive!!!\n";
	return 0;
}

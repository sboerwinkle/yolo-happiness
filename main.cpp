#include <iostream>
#include "pieces.hpp"

using namespace std;

int main(int argc, char** argv){
	Piece p;
	p = Piece(QUEEN);
	if(p.type == QUEEN) cout << "it's alive!!!\n";
	cout << "It works!" << endl;
	int i = 1;
	for(; i < argc; i++) cout << argv[i] << endl;
	return 0;
}

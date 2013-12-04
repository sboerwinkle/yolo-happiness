#include <iostream>
#include "pieces.hpp"

using namespace std;

int main(int argc, char** argv){
	cout << "It works!" << endl;
	int i = 1;
	for(; i < argc; i++) cout << argv[i] << endl;
	return 0;
}

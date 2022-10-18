#include <iostream>
#include <string>
#include "CSS.h"
int main(int argc, char** argv) {
    CSS myCSS(0.0,0.0,0.0,0.0,0.0,0.0,0);
    myCSS.printMenu();
    myCSS.setCoordinates();
    myCSS.printCoordinates();
	
	
	return 0;
}


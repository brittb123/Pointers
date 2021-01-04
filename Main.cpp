#include <iostream>
#include <fstream>
#include "Game.h"
#include "Character.h"

void changeNumber(int& num) {
	num = 5;
}

int main()
{
	int number = 2;
	int& numberReference = number;
	numberReference = 5;
	
	changeNumber(number);
	
	system("pause");
	Game game = Game();
	game.run();

	
	
	return 0;
}
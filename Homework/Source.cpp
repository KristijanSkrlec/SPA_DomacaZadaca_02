#include <iostream>
#include <string>
#include <fstream>
#include<ctime>
#include "game_of_life.h"
using namespace std;

int main() {

	game_of_life the_game;

	bool again;
	do {
		the_game.draw();
		the_game.next_generation();

		cout << "Again (1/0): ";
		cin >> again;
		the_game.n++;
	} while (again);
	return 0;
}
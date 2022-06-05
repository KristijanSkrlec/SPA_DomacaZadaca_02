#include "game_of_life.h"

int game_of_life::random_value()
{
	//Chances are 1 / 4 of the cell being alive
	return rand() % 4;
}

bool game_of_life::cell_taken(int i, int j)
{
	//I have absolutely no idea what this method should do 
	return false;
}

game_of_life::game_of_life()
{
	//Getting a random seed every time
	srand(time(nullptr));

	//Double ForLoop, filling the array with dead or alive cells
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (random_value() == 1)
			{
				cell[i][j] = 1;
			} 
		}
	}
}

void game_of_life::next_generation()
{

	//Calculating the amount of alive / dead neighbours for the next iteration
	//9 Possible Cases
	//4 For corners
	//4 For Edges
	//1 For the middle of the table
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//Top Left Corner
			if (i == 0 && j == 0)
			{
				counter[i][j] = cell[i][j + 1] + cell[i + 1][j] + cell[i + 1][j + 1];
			}
			//Top Row, Excluding Corners
			else if (i == 0 && j > 0 && j < COLS - 1)
			{
				counter[i][j] = cell[i][j - 1] + cell[i + 1][j - 1] +
					cell[i + 1][j] + cell[i + 1][j + 1] + cell[i][j + 1];
			}
			//Top Right Corner
			else if(i == 0 && j == COLS - 1)
			{
				counter[i][j] = cell[i][COLS - 1] + cell[i + 1][COLS - 1] + cell[i + 1][j];
			}
			//Left Row, Excluding Corners
			else if (i != 0 && i != ROWS - 1 && j == 0)
			{
				counter[i][j] = cell[i - 1][j] + cell[i - 1][j + 1] + cell[i][j + 1] +
					cell[i + 1][j] + cell[i + 1][j + 1];
			}
			//Bottom Left Corner
			else if (i == ROWS - 1 && j == 0)
			{
				counter[i][j] = cell[i - 1][j] + cell[i - 1][j + 1] + cell[i][j + 1];
			}
			//Bottom Row, Excluding Corners
			else if (i == ROWS - 1 && j != 0 && j != COLS - 1)
			{
				counter[i][j] = cell[i][j - 1] + cell[i - 1][j - 1] + cell[i - 1][j] +
					cell[i - 1][j + 1] + cell[i][j + 1];
			}
			//Right Row, Excluding Corners
			else if (i != 0 && i != ROWS -  1&& j == COLS - 1)
			{
				counter[i][j] = cell[i - 1][j - 1] + cell[i][j - 1] + cell[i - 1][j] + cell[i + 1][j - 1]
					+ cell[i + 1][j];
			}
			//Bottom Right Corner
			else if (i == ROWS - 1 && j == COLS - 1)
			{
				counter[i][j] = cell[i][j - 1] + cell[i - 1][j - 1] + cell[i - 1][j];
			}
			//Middle of the Table
			else
			{
				counter[i][j] = cell[i - 1][j - 1] + cell[i - 1][j] + cell[i - 1][j + 1] +
					cell[i][j - 1] + cell[i][j + 1] + cell[i + 1][j - 1] + cell[i + 1][j] +
					cell[i + 1][j + 1];
			}
			
		}
	}

	//Setting the cell based on its neighbours
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < COLS - 1; j++)
		{
			//Its alive if it has 2 or 3 alive neighbouring cells
			if (counter[i][j] == 2 || counter[i][j] == 3)
			{
				cell[i][j] = 1; 
			}
			//Its dead if it has more or less
			else
			{
				cell[i][j] = 0;
			}
		}
	}
}

void game_of_life::draw()
{
	//Clearing the CMD screen
	system("CLS");

	//Just a counter, design wise
	std::cout << "###############" << endl; 
	std::cout << "Phase: " << n << endl; 
	std::cout << "###############" << endl; 
	std::cout << endl; 

	//Drawing the cells
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//" " Represents dead cells
			if (cell[i][j] == 0) 
			{
				std::cout << " "; 
			}
			//"*" Represents alive cells
			else
			{
				std::cout << "*";
			}
			//std::cout << cell[i][j];
			//std::cout << counter[i][j];
		}
		std::cout << endl;
	}

}

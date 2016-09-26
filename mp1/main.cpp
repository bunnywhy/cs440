#include "algorithm.h"
#include "a_star.h"
using namespace std;


//-----------------------------Global Variables------------------------------------//
FILE *in;
coord start;
coord endpoint[30];
vector<coord> endset;
int row, column =0;
int x_max=0;
int y_max=0;
int dot_counter = 0;
//--------------------------------Draw Path----------------------------------------//
void draw_path(char * maze)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < column ; j++)
		{
			cout << maze[i * column + j];
		}
		cout << endl;
	}
}


//-------------------------Print Maze + Maze Solver-------------------------------//
void printMaze(char* argv)
{
	char c=0;
	int i = 0;
	int input;
	in = fopen(argv, "r");
	
	//char *maze = new char [column*row];
	char *maze = new char[row*column];

	do
	{
		c = (char)fgetc(in);
		if(c != '\n')
		{
			maze[i] = c;
			i++;
		}
	}while(c != EOF);
	fclose(in);
	cout << "x-max: " << column << " | y-max: " << row << endl;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < column ; j++)
		{
			if (maze[i * column + j] == 'P'){
				start.x = j;
				start.y = i;
			}
			else if (maze[i * column + j] == '.')
			{
				endpoint[dot_counter].x = j;
				endpoint[dot_counter].y = i;
				dot_counter++;
			}
			cout << maze[i * column + j];
		}
		cout << endl;
	}
	vector<coord> end = conversion(endpoint);
	//Print Start and End point
	cout << "start: (" << start.x << "," <<start.y << ")" <<endl;
	cout << "end: ";
	for (int i = 0; i < dot_counter; i++)
	{
		cout << "(" << endpoint[i].x << "," << endpoint[i].y << ") " ;
	}
	cout << endl;
	cout << "select an algorithm from the list:" << endl;
	cout << "1. BFS" << endl;
	cout << "2. DFS" << endl;
	cout << "3. Greedy" << endl;
	cout << "4. A* (choose me)" << endl;
	cin >> input;

	if (input == 1)
	{
		if(BFS(maze, start, endpoint[0]) == 1){
			cout << "Sucess!" << endl;
			draw_path(maze);
		}
		else
			cout << "Failed!" << endl;
	}
	//Check if we have suceffully got a path
	else if (input == 2)
	{
		if(DFS(maze, start, endpoint[0]) == 1){
			cout << "Sucess!" << endl;
			draw_path(maze);
		}
		else
		{
			cout << "Failed!" << endl;
		}
	}
	else if (input == 3)
	{
		if(GFS(maze, start, endpoint[0]) == 1){
			cout << "Sucess!" << endl;
			draw_path(maze);
		}
		else
		{
			cout << "Failed!" << endl;
		}
	}
	else if (input == 4)
	{
		if (_a_star(maze, start, end) == 1)
		{
			cout << "Sucess!" << endl;
			draw_path(maze);
		}
		else
		{
			cout << "Shame!" << endl;
			draw_path(maze);
		}
	}
	else
	{
		cout << "Please enter a number between 1-4" << endl;
	}
	delete [] maze;
}


//-----------------------------Main function-------------------------------------//
int main(int argc, char *argv[])
{
	char c=0;
	row = 0;
	column = 0;
	char dfault[15] = "tinySearch.txt";

	//Check amount of argument is correct, if not use default mediummaze
	if (argc != 2)
	{
		cout << "need 2 arguements, run with default map 'mediumMaze.txt'" << endl;
		in = fopen(dfault, "r");
		//return -1;
	}

	//if the arument provided is correct, open file with the given name
	else
		in = fopen(argv[1], "r");
	if (in == NULL)
	{
		cout << "Cannot open file" << endl;
		return -1;
	}

	//Start scanning amount of collumns
	do
	{
		c = (char)fgetc(in);
		if (c == '\n')
		{
			row++;
			break;
		}
		column++;	
	}while (c != EOF);

	//Start scanning amount of rows
	do
	{
		c = fgetc(in);
		if (c == '\n')
		{
			row++;
		}
		else if(c == EOF)
		{
			row++;
			break;
		}
	}while (c != EOF);

	//Aquired collumns and rows, close the current file
	fclose(in);
	x_max = column;
	y_max = row;

	//Start execute print maze, which also does search algo.
	if (argc != 2)
		printMaze(dfault);
	else
		printMaze(argv[1]);

	return 1;
}

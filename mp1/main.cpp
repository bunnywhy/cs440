#include "algorithm.h"
#include "a_star.h"
using namespace std;


//-----------------------------Global Variables------------------------------------//
FILE *in;
coord start;
coord endpoint[30];
int row, column =0;


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
	int dot_counter = 0;
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
	cout <<"x-max: " << column << " | y-max: " << row << endl;
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

	//Print Start and End point
	cout<<"start: ("<<start.x<< ","<<start.y<<")"<<endl;
	cout<<"end: ("<<endpoint[0].x<< ","<<endpoint[0].y<<")"<<endl;

	//Check if we have suceffully got a path
	if( BFS(maze, start, endpoint[0], row, column) ==1)
		cout<<"Sucess!"<<endl;

	else
		cout<<"Failed!"<<endl;

		draw_path(maze);
	
	delete [] maze;

}


//-----------------------------Main function-------------------------------------//
int main(int argc, char *argv[])
{
	char c=0;
	row = 0;
	column = 0;
	char dfault[15] = "mediumMaze.txt";

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

	//Start execute print maze, which also does search algo.
	if (argc != 2)
		printMaze(dfault);
	printMaze(argv[1]);

	return 0;
}

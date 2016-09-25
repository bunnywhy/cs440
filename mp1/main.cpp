#include "algorithm.h"
#include "a_star.h"
using namespace std;

FILE *in;
coord start;
coord endpoint[30];
int row, column =0;

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
	cout << column << " " << row << endl;
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
	cout << "start:(" << start.x << ", " << start.y << ")" << endl;
	cout << "end:(" << endpoint[0].x << ", " << endpoint[0].y << ")" << endl;
	a_star(maze, start, endpoint[0]);
	draw_path(maze);
	delete [] maze;

}

int main(int argc, char *argv[])
{
	char c=0;
	row = 0;
	column = 0;
	char test[15] = "mediumMaze.txt";
	if (argc != 2)
	{
		cout << "need 2 arguements" << endl;
		in = fopen(test, "r");
		//return -1;
	}
	else
		in = fopen(argv[1], "r");
	if (in == NULL)
	{
		cout << "Cannot open file" << endl;
		return -1;
	}

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


	fclose(in);
	if (argc != 2)
		printMaze(test);
	printMaze(argv[1]);
	return 0;
}


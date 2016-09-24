#include "algorithm.h"
using namespace std;

coord endpoint[30];
coord start;
int row, column =0;
FILE *in;
void printMaze()
{
	char c=0;
	int i = 0;
	int dot_counter = 0;
	in = fopen("mediumMaze.txt", "r");
	
	//char *maze = new char [column*row];
	char maze[row*column];

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
		for (int j = 0; j < column - 1; j++)
		{
			if (maze[i * column + j] == 'P'){
				start.x = i;
				start.y = j;
			}
			else if (maze[i * column + j] == '.')
			{
				endpoint[dot_counter].x = i;
				endpoint[dot_counter].y = j;
				dot_counter++;
			}
			cout << maze[i * column + j];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	char c=0;
	row = 0;
	column = 0;

	if (argc != 2)
	{
		cout << "need 2 arguements" << endl;
		return -1;
	}
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
	printMaze();
	return 0;
}


void draw_path(char * maze, )
/* Can we make two global arrays (one for x and one for y) to save the path we figured out
   by the algorithms to print it out?
*/ 
#include "algorithm.h"
using namespace std;

int xStart, yStart;
int xEnd[30] = {0};
int yEnd[30] = {0};
void printMaze(){
	FILE *in;
	int row = 21;
	int column = 42;
	char c=0;
	int dot_counter = 0;
	in = fopen("mediumMaze.txt", "r");
	int i = 0;
	//char *maze = new char [column*row];
	char maze[42*21];
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
				xStart = i;
				yStart = j;
			}
			else if (maze[i * column + j] == '.')
			{
				xEnd[dot_counter] = i;
				yEnd[dot_counter] = j;
				dot_counter++;
			}
			cout << maze[i * column + j];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	FILE *in;
	char c=0;
	int row = 0;
	int column = 0;
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
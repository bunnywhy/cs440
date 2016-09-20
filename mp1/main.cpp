#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

void printMaze(){
	FILE *in;
	int row = 21;
	int column = 42;
	char c;
	in = fopen("mediumMaze.txt", "r");
	int i = 0;
	//char *maze = new char [column*row];
	char maze[42*21];
	while(c != EOF)
	{
		c = (char)fgetc(in);
		if(c != '\n')
		{
			maze[i] = c;
			i++;
		}
	}
	fclose(in);
	cout << column << " " << row << endl;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < column - 1; j++)
		{
			cout << maze[i * column + j];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	FILE *in;
	char c;
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
	while (c != EOF)
	{
		c = (char)fgetc(in);
		if (c == '\n')
		{
			row++;
			break;
		}
		column++;	
	}
	while (c != EOF)
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
	}
	fclose(in);
	printMaze();
	// rewind(in);
	return 0;
}

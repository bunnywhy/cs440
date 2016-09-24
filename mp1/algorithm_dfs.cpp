#include "algorithm.h"
#define x_max 42
#define y_max 21
#define x_min 0
#define y_min 0

int MD(int x, int y, int end_x, int end_y)
{
	return abs(x - end_x) + abs(y - end_y);
}

int BFS(char *maze, int x_start, int y_start, int* x_end, int* y_end)
{
	std::queue<int> qx;
	std::queue<int> qy;
	qx.push(x_start);
	qy.push(y_start);
	return BFS_R(maze, x_end, y_end, qx, qy);
}

int BFS_R(char *maze, int* x_end, int* y_end, std::queue<int> &qx, std::queue<int> &qy)
{
	int x,y;
	x = qx.front();
	qx.pop();

	y = qy.front();
	qy.pop();

	if ( ((x == x_end[0]) && (y == y_end[0])) )
	{
		return 1;
	}

	else if ( qx.empty())
	{
		return -1;
	}

	else
	{
		//Modify current loc. status
		maze[get_cord(x,y)] = '.';

		//Push Right Neighbor
		if( check_cell( maze,(x+1), y) && ((x+1)<=x_max) )
		{
			qx.push(x+1);
			qy.push(y);
		}

		//Push Left Neighbor
		if( check_cell( maze,(x-1), y) && ((x-1)>=x_min) )
		{
			qx.push(x-1);
			qy.push(y);
		}
		//Push Down Neighbor
		if( check_cell( maze,x, (y+1)) && ((y+1)<=y_max) )
		{
			qx.push(x);
			qy.push(y+1);
		}
		//Push Up Neighbor
		if( check_cell( maze,x,(y-1)) && ((y-1)>=y_min) )
		{
			qx.push(x);
			qy.push(y-1);
		}

		return BFS_R(maze, x_end, y_end, qx, qy);
	}

}

int get_cord(int x, int y)
{
	return (x+y*x_max);
}

int check_valid( char* maze, int x, int y)
{
	if(maze[get_cord(x,y)] == '.' || maze[get_cord(x,y)] == '%')				// reached a dot or hit a wall
		return 0;																// invalid
	else
		return 1;
}

int DFS(char *maze, int x_start, int y_start, int* x_end, int* y_end)
{
	std::stack<int> sx;
	std::stack<int> sy;
	sx.push(x_start);
	sy.push(y_start);
	int * visit[100][100] = 0;
	return DFS_R(maze, x_end, y_end, sx, sy, visit);
}

int DFS_R(char *maze, int* x_end, int* y_end, std::stack<int> &sx, std::stack<int> &sy, int * visited[][])		// Use backtracking
{
	int x, y;
	x = sx.top();
	y = sy.top();
	visited[x][y] = 1;

	if ( (x == x_end[0]) && (y == y_end[0]) && (visited[x][y] == 0)	)					// when it reaches a dot
		return 1;
	
	if ( sx.empty() )												// stack is empty
		return -1;


	if( check_valid(maze, x+1, y) && (x+1 <= x_max) && (visited[x][y] == 0) )				// always check right neighbor first
	{																// push it					
		sx.push(x+1);
		sy.push(y);
		return DFS_R(maze, x_end, y_end, sx, sy);
	}

	else if( check_valid(maze, x-1, y) && (x-1 >= x_min) && (visited[x][y] == 0) )			// check left
	{
		sx.push(x-1);
		sy.push(y);
		return DFS_R(maze, x_end, y_end, sx, sy);
	}

	else if( check_cell(maze, x, y+1) && (y+1 <= y_max) && (visited[x][y] == 0) )			// check up
	{
		sx.push(x);
		sy.push(y+1);
		return DFS_R(maze, x_end, y_end, sx, sy);
	}

	else if( check_cell(maze, x, y-1) && (y-1 >= y_min) && (visited[x][y] == 0) )			// check down
	{
		sx.push(x);
		sy.push(y-1);
		return DFS_R(maze, x_end, y_end, sx, sy);
	}

	sx.pop();
	sy.pop();

	return 0;
}










int GFS(void)
{
	return 0;
}

int AS(void)
{
	return 0;
}



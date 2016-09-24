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

int check_cell( char* maze, int x, int y)
{
	if( x>= x_max || x<= x_min || y>= y_max || y<= y_min)
		return 0;

	if(maze[get_cord(x,y)] == '.' || maze[get_cord(x,y)] == '%' || maze[get_cord(x,y)] == 'X')
		return 0;

	else
		return 1;
}

int DFS(void)
{

	return 0;

}

int GFS(char* maze, int x, int y, int x_end, int y_end)
{
	coord path[200];
	coord start, end;
	int point=0;
	start.x = x;
	start.y = y;
	end.x 	= x_end;
	end.y 	= y_end;


	return 0;
}

int GFS_Recurr(char* maze, int x, int y, int x_end, int y_end, int &point)
{
	//Mark current location as  discovered

	//Push next locaion

	//Check return value

	//Push next loc

	//if
	return 0;
}


// 0=up , 1=down , 2=left, 3=right
int GFS_move(char* maze, coord start, coord end)
{
	 int curr_min, direction, curr_dist=0;
	 curr_min = 999999;

	 //Check heuristic of moving up
	 curr_dist= MD(start.x, (start.y-1), end.x, end.y);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, start.x, (start.y-1) ) ==1)
	 {
	 		curr_min = curr_dist;
	 		direction = 0;
	 }

	 //Check heuristic of moving down
	 curr_dist= MD(start.x, (start.y+1), end.x, end.y);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, start.x, (start.y+1)) ==1)
	 {
	 		curr_min = curr_dist;
	 		direction = 1;
	 }

	 //Check heuristic of moving left
	 curr_dist= MD((start.x-1), start.y, end.x, end.y);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, (start.x-1), start.y)  ==1)
	 {
	 		curr_min = curr_dist;
	 		direction = 2;
	 }

	 //Check heuristic of moving right
	 curr_dist= MD((start.x+1), start.y, end.x, end.y);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, (start.x+1), start.y  ) ==1)
	 {
	 		curr_min = curr_dist;
	 		direction = 3;
	 }

	 //Return shortest distance direction
	 return direction;
}

int AS(void)
{
	return 0;
}



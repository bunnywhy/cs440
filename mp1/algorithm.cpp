#include "algorithm.h"
#define x_min 0
#define y_min 0
int x_max=0;
int y_max=0;
using namespace std;
				//Commmon Class + functions//
//---------------------------------------------------------------//
#include "algorithm.h"
#define x_max 42
#define y_max 21
#define x_min 0
#define y_min 0

				//Commmon Class + functions//
//---------------------------------------------------------------//

int MD(coor curr, coord end)
{
	return abs(curr.x - end.x) + abs(curr.y - end.y);
}

bool coord::operator==(const coord &other) const 
 {
 	if( other.x == this->x && other.y == this->y)
 		return true;

 	else
 		return false;
 }

int get_cord(coord curr)
{
	return (curr.x+curr.y*x_max);
}

int check_cell( char* maze, coord curr)
{
	if( curr.x>= x_max || curr.x<= x_min || curr.y>= y_max || curr.y<= y_min)
		return 0;

	if(maze[get_cord(curr)] == '%' || maze[get_cord(curr)] == 'X')
		return 0;

	if(maze[get_cord(curr)] == '.')
		return 2;

	else
		return 1;
}
							//BFS//
//-----------------------------------------------------------------//

int BFS(char *maze, coord start, coord end)
{
	std::queue<coord> pathq;
	pathq.push(start);								// qx -> pathq
	return BFS_R(maze, end, pathq);
}

int BFS_R(char *maze,coord end, std::queue<coord> &pathq)
{
	coord curr;										// path -> coord

	curr = pathq.front();
	pathq.pop();


	if (curr == end)
	{
		return 1;
	}

	else if (pathq.empty())
	{
		return -1;
	}

	else
	{
		//Modify current loc. status
		maze[get_cord(curr)] = '.';

		//Push Right Neighbor
		if( check_cell( maze,(curr.x+1), y) && ((curr.x+1)<=x_max) )
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


int DFS(char *maze, coord start, coord end)
{
	std::stack<coord> paths;
	paths.push(start);
	return DFS_R(maze, end, paths);
}

int DFS(char *maze, coord end, std::stack<coord> &paths)
{
	coord curr;
	curr = paths.top();
	int x = curr.x;
	int y = curr.y;

	if ((curr.x == end.x) && (curr.y == end.y))							// when it reaches a dot
		return 1;
	
	else if (paths.empty())												// stack is empty
		return -1;

	else																// always check right neighbor first
	{		
		//Modify current loc. status
		maze[get_cord(curr)] = '.';				
								
		if(check_cell(maze, x+1, y) && (x+1 <= x_max))
		{																// push it					
			paths.push((x+1, y));
			return DFS_R(maze, end, paths);
		}
	
		else if( check_cell(maze, x-1, y) && (x-1 >= x_min) )			// check left
		{
			paths.push((x-1, y));
			return DFS_R(maze, end, paths);
		}

		else if( check_cell(maze, x, y+1) && (y+1 <= y_max) )			// check up
		{
			paths.push((x, y+1));
			return DFS_R(maze, end, paths);
		}

		else if( check_cell(maze, x, y-1) && (y-1 >= y_min) )			// check down
		{
			paths.push((x, y-1));
			return DFS_R(maze, end, paths);
		}

		paths.pop();
	}

		return 0;
}

/*
<<<<<<< HEAD
int check_valid( char* maze, int x, int y)
{
	if(maze[get_cord(x,y)] == '.' || maze[get_cord(x,y)] == '%')				// reached a dot or hit a wall
		return 0;																// invalid
=======
*/

int GFS(char* maze, coord start, coord end)
{
	int point=0;
	coord path[200];

	if(GFS_Recurr(maze, start, end, path, point)==-1 || point ==0);
		return -1;

>>>>>>> 4dac578fd258dcce1f72da937e1f4db0b24fd360
	else
	{
		for(int i=0 ; i<point ;  point++)
		{
			maze[get_cord(path[i])] = "^";
		}
		return 0;
	}


	return -1;
}

<<<<<<< HEAD
int GFS(void)
=======
int GFS_Recurr(char* maze, coord curr, coord end, coord* path, int &point)
{
	int ret_val=0;
	coord next;
	//Check location with end point
	if(check_cell(maze, cuur.x, curr.y) ==2)
		return 1;

	//Mark current location as  discovered
	if(check_cell(maze, cuur.x, curr.y) ==1)
		maze[get_cord (curr.x, curr.y)] = 'X';

	//Append current location to path
	path[point] = cuur;
	point++;

	//Push next locaion 
	for(int i=0; i<4 ; i++)
	{
		switch(GFS_move(maze,curr.x,curr.y))
		{
			case 0:
			{
				next.x = curr.x;
				next.y = curr.y-1;
			}

			case 1:
			{
				next.x = curr.x;
				next.y = curr.y+1;
			}

			case 2:
			{
				next.x = curr.x-1;
				next.y = curr.y;
			}

			case 3:
			{
				next.x = curr.x+1;
				next.y = curr.y;
			}

			case -1:
			{
				point--;
				return -1;
			}
		}

		ret_val = GFS_Recurr(maze, next, end, path, point);

		//Check return value
		if(ret_val == 1)
			return 1;
		else if(ret_val == -1)
			return -1;
	}
	
	return -1;
}


// 0=up , 1=down , 2=left, 3=right
int GFS_move(char* maze, coord start, coord end)
>>>>>>> 4dac578fd258dcce1f72da937e1f4db0b24fd360
{
	 int curr_min, direction, curr_dist=0;
	 curr_min  = 999999;
	 direction = -1;

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


int MD(coord curr, coord end)
{
	return (abs(curr.x - end.x) + abs(curr.y - end.y));
}

bool coord::operator==(const coord &other) const 
 {
 	if( other.x == this->x && other.y == this->y)
 		return true;

 	else
 		return false;
 }

int get_cord(coord curr)
{
	return (curr.x+curr.y*x_max);
}

int check_cell( char* maze, coord curr)
{
	//Boundary Check
	if( curr.x>= x_max || curr.x<= x_min || curr.y>= y_max || curr.y<= y_min)
		return 0;

	//Location content test
	if(maze[get_cord(curr)] == '%' || maze[get_cord(curr)] == 'X' || maze[get_cord(curr)] == 'N')
		return 0;

	//Goal Test
	if(maze[get_cord(curr)] == '.')
		return 2;

	//valid
	else
		return 1;
}
							//BFS//
//-----------------------------------------------------------------//

int BFS(char *maze, coord start, coord end)
{
	/*std::queue<coord> pathq;
	qx.push(start);
	return BFS_R(maze, end, pathq);*/
	return 0;
}

int BFS_R(char *maze,coord end, std::queue<coord> &pathq)
{
	path curr;

	curr = pathq.front();
	pathq.pop();


	if (curr == end)
	{
		return 1;
	}

	else if ( pathq.empty())
	{
		return -1;
	}

	else
	{
		//Modify current loc. status
		maze[get_cord(curr)] = '.';

		//Push Right Neighbor
		if( check_cell( maze,(curr.x+1), y) && ((curr.x+1)<=x_max) )
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
	return 1;
}


int DFS(void)
{

	return 0;

}

int GFS(char* maze, coord start, coord end, int row, int column)
{
	int point=0;
	coord path[400];

	x_max = column;
	y_max = row;
	if(GFS_Recurr(maze, start, end, path, point)<=-1)
		return -1;

	else
	{
		for(int i=0 ; i<point ;  i++)
		{
			maze[get_cord(path[i])] = '-';
		}
		return 1;
	}


	return -1;
}

void draw_ppath(char * maze)
{
	int i = 0;
	for (i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max ; j++)
		{
			cout << maze[i * x_max + j];
		}
		cout << endl;
	}
}

int GFS_Recurr(char* maze, coord curr, coord end, coord* path, int &point)
{
	int ret_val=0;
	coord next;

	//Check location with end point
	if(check_cell(maze, curr) ==2)
		return 1;

	//Mark current location as  discovered
	if(check_cell(maze, curr) ==1)
		maze[get_cord (curr)] = 'X';

	//draw_ppath(maze);

	//Append current location to path
	path[point] = curr;
	point++;

	//Push next locaion 
	for(int i=0; i<4 ; i++)
	{
		switch(GFS_move(maze, curr, end))
		{
			case 0:
			{
				next.x = curr.x;
				next.y = curr.y-1;
				break;
			}

			case 1:
			{
				next.x = curr.x;
				next.y = curr.y+1;
				break;
			}

			case 2:
			{
				next.x = curr.x-1;
				next.y = curr.y;
				break;
			}

			case 3:
			{
				next.x = curr.x+1;
				next.y = curr.y;
				break;
			}

			case -1:
			{
				ret_val = -2;
				break;
			}

			default:
			break;
		}

		if(ret_val == -2)
			break;

		ret_val = GFS_Recurr(maze, next, end, path, point);

		//Check return value
		if(ret_val == 1)
			return 1;

	}
	if(ret_val <= -1)
	{
		point--;
		maze[get_cord (curr)] = 'N';
	}
	
	return -1;
}


// 0=up , 1=down , 2=left, 3=right
int GFS_move(char* maze, coord start, coord end)
{
	 int curr_min, direction, curr_dist=0;
	 curr_min  = 999999;
	 direction = -1;
	 coord neighbor;

	 //Check heuristic of moving up
	 neighbor.x = start.x;
	 neighbor.y = start.y-1;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) && check_cell(maze, neighbor) >=1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 0;
	 }

	 //Check heuristic of moving down
	 neighbor.x = start.x;
	 neighbor.y = start.y+1;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) >=1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 1;
	 }

	 //Check heuristic of moving left
	 neighbor.x = start.x-1;
	 neighbor.y = start.y;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) >=1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 2;
	 }

	 //Check heuristic of moving right
	 neighbor.x = start.x+1;
	 neighbor.y = start.y;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) >=1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 3;
	 }

	 //Return shortest distance direction
	 return direction;
}

int AS(void)
{
	return 0;
}



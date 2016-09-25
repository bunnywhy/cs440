#include "algorithm.h"
#define x_min 0
#define y_min 0
int x_max=0;
int y_max=0;
using namespace std;

                                    //Commmon Class + functions//
//---------------------------------------------------------------------------------------------------------//

int MD(coord curr, coord end)
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

bool coord::operator<(const coord &other) const{
	return ((this->x < other.x) || ((this->x == other.x) && (this->y < other.y)));
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
//------------------------------------------------------------------------------------------------------------//

int BFS(char *maze, coord start, coord end, int row, int column)
{
	std::queue<coord> frontier;
	coord parent[y_max*x_max];
	coord curr;

	x_max = column;
	y_max = row;
	//Push start point and mark it as a root node
	parent[get_cord(start)].x=-1;
	parent[get_cord(start)].y=-1;
	frontier.push(start);

	// check if we have sucessfully find a path to goal
	if(BFS_R(maze, end, frontier, parent) == 1)			 // qx -> frontier
	{
		curr = parent[get_cord(end)];
		while(curr.x != -1)
		{
			maze[get_cord(curr)] = '-';
			curr = parent[get_cord(curr)];
		}
		return  1;
	}

	else
		return -1;
}

int BFS_R(char *maze, coord end, std::queue<coord> &frontier, coord *parent)
{
	coord curr,neighbor;								// path -> coord
	curr = frontier.front();
	frontier.pop();


	if (curr == end)
	{
		return 1;
	}

	else if (frontier.empty())
	{
		return -1;
	}

	else
	{
		maze[get_cord(curr)] = 'X';
		draw_ppath(maze);
		 //Check moving up
		 neighbor.x = curr.x;
		 neighbor.y = curr.y-1;
		 if( check_cell(maze, neighbor) >=1)
		 {
		 	frontier.push(neighbor);
		 	parent[get_cord(neighbor)] = curr;
		 }

		 //Check moving down
		 neighbor.x = curr.x;
		 neighbor.y = curr.y+1;
		 if(check_cell(maze, neighbor) >=1)
		 {
		 	frontier.push(neighbor);
		 	parent[get_cord(neighbor)] = curr;
		 }

		 //Check moving left
		 neighbor.x = curr.x-1;
		 neighbor.y = curr.y;
		 if( check_cell(maze, neighbor) >=1)
		 {
		 	frontier.push(neighbor);
		 	parent[get_cord(neighbor)] = curr;
		 }

		 //Check moving right
		 neighbor.x = curr.x+1;
		 neighbor.y = curr.y;
		 if(check_cell(maze, neighbor) >=1)
		 {
		 	frontier.push(neighbor);
		 	parent[get_cord(neighbor)] = curr;
		 }

		return BFS_R(maze, end, frontier, parent);
	}
	return 0;

}

                                               //BFS//
//------------------------------------------------------------------------------------------------------------//
int DFS(char *maze, coord start, coord end)
{
	std::stack<coord> paths;
	paths.push(start);
	return DFS_R(maze, end, paths);
}

int DFS_R(char *maze, coord end, std::stack<coord> &paths)
{
	/*coord curr;
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
	}*/

		return 0;
}

                                               //GFS//
//------------------------------------------------------------------------------------------------------------//
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



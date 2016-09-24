#include "algorithm.h"
#define x_max 41
#define y_max 21
#define x_min 0
#define y_min 0

				//Commmon Class + functions//
//---------------------------------------------------------------//

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
	/*path curr;

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
	}*/
	return 1;
}


int DFS(void)
{

	return 0;

}

int GFS(char* maze, coord start, coord end)
{
	int point=0;
	coord path[400];

	if(GFS_Recurr(maze, start, end, path, point)==-1)
		return -1;

	else
	{
		for(int i=0 ; i<point ;  i++)
		{
			maze[get_cord(path[i])] = '^';
		}
		return 0;
	}


	return -1;
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
				point--;
				break;
			}

			default:
			break;
		}

		ret_val = GFS_Recurr(maze, next, end, path, point);

		//Check return value
		if(ret_val == 1)
			return 1;

	}
	if(ret_val == -1)
		maze[get_cord (curr)] = 'N';
	
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
	 if( ( curr_dist < curr_min) && check_cell(maze, neighbor) ==1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 0;
	 }

	 //Check heuristic of moving down
	 neighbor.x = start.x;
	 neighbor.y = start.y+1;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) ==1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 1;
	 }

	 //Check heuristic of moving left
	 neighbor.x = start.x-1;
	 neighbor.y = start.y;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) ==1)
	 {
	 		curr_min  = curr_dist;
	 		direction = 2;
	 }

	 //Check heuristic of moving right
	 neighbor.x = start.x+1;
	 neighbor.y = start.y;
	 curr_dist= MD(neighbor, end);
	 if( ( curr_dist < curr_min) &&  check_cell(maze, neighbor) ==1)
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



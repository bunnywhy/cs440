#include "a_star.h"
using namespace std;
vector<coord> neighbor;

coord min_cost(vector<coord> openSet, map<coord, int> cost){
	vector<coord>::iterator it;
	int current_min = 10000;
	coord current_node;
	current_node.x = -1;
	current_node.y = -1;
	for (int i = 0; i < openSet.size(); i++)
	{
		if (cost[openSet[i]] < current_min){
			current_min = cost[openSet[i]];
			current_node.x = openSet[i].x;
			current_node.y = openSet[i].y;
		}
	}
	return current_node;
}

void _draw_path(char * maze)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << maze[i * column + j];
		}
		cout << endl;
	}
}

void find_neighbor(char* maze, coord current){
	coord left;
	left.x = current.x - 1;
	left.y = current.y;
	coord right;
	right.x = current.x + 1;
	right.y = current.y;
	coord up;
	up.x = current.x;
	up.y = current.y - 1;
	coord down;
	down.x = current.x;
	down.y = current.y + 1;
	if (check_cell(maze, left) >= 1){
		neighbor.push_back(left);
	}
	if (check_cell(maze, right) >= 1)
	{
		neighbor.push_back(right);
	}
	if (check_cell(maze, up) >= 1)
	{
		neighbor.push_back(up);
	}
	if (check_cell(maze, down) >= 1)
	{
		neighbor.push_back(down);
	}
}

int a_star(char *maze, coord start, coord end){
	int curPathcost;
	map<coord, coord> cameFrom;
	vector<coord> openSet;
	vector<coord> closedSet;
	map<coord, int> pathCost;
	map<coord, int> totalCost;
	coord current;

	openSet.push_back(start);
	pathCost[start] = 0;
	totalCost[start] = MD(start, end);

	while (!openSet.empty()){
		current = min_cost(openSet, totalCost);
		//cout << "current.x:" << current.x << ' ' << "current.y" << current.y << endl;
		//cout << "current cost:" << totalCost[current] << endl;
		if ((current.x == end.x) && (current.y == end.y)){
			vector<coord> result = totalPath(cameFrom, current);
			for (vector<coord>::iterator it = result.begin(); it != result.end(); it++)
			{
		 		if ((it->x == start.x) && (it->y == start.y))
		 		{
		 			continue;
		 		}
		 		maze[it->y * column + it->x] = '.';
			}
			return 1;
		}
		openSet.erase(remove(openSet.begin(),openSet.end(), current), openSet.end());
		closedSet.push_back(current);
		neighbor.clear();
		find_neighbor(maze, current);
		for (int i = 0; i < neighbor.size(); i++)
		{
			//cout << "neighbor" << neighbor[i].x << ' ' << neighbor[i].y << endl;
			if (find(closedSet.begin(), closedSet.end(), neighbor[i]) != closedSet.end()){
				continue;
			}
			pathCost[neighbor[i]] = 10000;
			curPathcost = pathCost[current] + 1;
			if (find(openSet.begin(), openSet.end(), neighbor[i]) == openSet.end())
			{
				openSet.push_back(neighbor[i]);
			}
			else if (curPathcost >= pathCost[neighbor[i]])
			{
				continue;
			}
			cameFrom[neighbor[i]] = current;
			pathCost[neighbor[i]] = curPathcost;
			totalCost[neighbor[i]] = pathCost[neighbor[i]] + MD(neighbor[i], end);
			//cout << "neighbor totalCost:" << totalCost[neighbor[i]] << endl;
		}
	}
	return 0;
}

vector<coord> totalPath(map<coord, coord> path, coord current){
	vector<coord> totalPath;
	totalPath.push_back(current);
	while(path.find(current) != path.end()){
		current = path[current];
		totalPath.push_back(current);
	}
	return totalPath;
}


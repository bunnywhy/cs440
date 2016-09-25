#include "a_star.h"
using namespace std;

vector<coord> neighbor;

coord min_cost(map<coord, int> *cost){
	map<coord, int>::iterator it;
	int current_min = 10000;
	coord current_node;
	current_node.x = -1;
	current_node.y = -1;
	for (it = cost->begin(); it != cost->end(); it++)
	{
		if (it->second < current_min){
			current_min = it->second;
			current_node.x = it->first.x;
			current_node.y = it->first.y;
		}
	}
	return current_node;
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
	cout << "check cell return" << check_cell(maze, up) << endl;
	if (check_cell(maze, left)>=1){
		neighbor.push_back(left);
	}
	if (check_cell(maze, right)>=1)
	{
		neighbor.push_back(right);
	}
	if (check_cell(maze, up)>=1)
	{
		neighbor.push_back(up);
	}
	if (check_cell(maze, down)>=1)
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
		current = min_cost(&totalCost);
		cout << "current.x" << current.x << endl;
		cout << "current.y" << current.y << endl;
		if ((current.x == end.x) && (current.y == end.y)){
			return 1;
		}
		openSet.erase(remove(openSet.begin(),openSet.end(), current), openSet.end());
		closedSet.push_back(current);
		neighbor.clear();
		find_neighbor(maze, current);
		for (int i = 0; i < neighbor.size(); i++)
		{
			cout << "neighbor" << neighbor[i].x << ' ' << neighbor[i].y << endl;
			if (find(closedSet.begin(), closedSet.end(), neighbor[i]) == closedSet.end()){
				continue;
			}
			pathCost[neighbor[i]] = 10000;
			curPathcost = pathCost[current] + 1;
			if (find(openSet.begin(), openSet.end(), neighbor[i]) != openSet.end())
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
			vector<coord> result = totalPath(cameFrom, current);
			for (vector<coord>::iterator it = result.begin(); it != result.end(); it++)
			{
		 		maze[it->y * 41 + it->x] = '.';
			}
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


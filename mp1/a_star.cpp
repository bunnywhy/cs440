#include "algorithm.h"
using namespace std;
class coord
	{
	public:
		int x;
		int y;	
	};

coord min_cost(map<coord, int> cost){
	map<coord, int>::iterator it;
	int current_min = 10000;
	coord current_node;
	current_node.x = -1;
	current_node.y = -1;
	for (it = cost.begin(); it != cost.end(); it++)
	{
		if (it->second < current_min){
			current_min = it->second;
			current_node.x = it->first.x;
			current_node.y = it->first.y;
		}
	}
	return current_node;
}
int MD(coord start, coord end){
	return 0;
}
int a_star(char *maze, coord start, coord end){
	vector<coord> closedSet;
	vector<coord> openSet;
	vector<coord> neighbor;
	map<coord, coord> cameFrom;
	map<coord, coord>::iterator it;
	map<coord, int> pathCost;
	map<coord, int> totalCost;
	coord current;
	openSet.push_back(start);
	pathCost[start] = 0;
	totalCost[start] = MD(start, end);

	while (!openSet.empty()){
		current = min_cost(totalCost);
		if (current == end){
			return 1;
		}
		openSet.erase(current);
		closedSet.push_back(current);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	return 0;
}
int _a_star(char *maze, coord start, vector<coord> endset){
	int curPathcost;
	map<coord, coord> cameFrom;
	vector<coord> openSet;
	vector<coord> closedSet;
	map<coord, int> pathCost;
	map<coord, int> totalCost;
	coord current;

	openSet.push_back(start);
	pathCost[start] = 0;
	totalCost[start] = optimal_cost(start, end);
	_a_star_recursive(maze, start, endset);
}
int _a_star_recursive(char *maze, coord start, vector<coord> endset){

	while (!openSet.empty()){
		current = min_cost(openSet, totalCost);
		//cout << "current.x:" << current.x << ' ' << "current.y" << current.y << endl;
		//cout << "current cost:" << totalCost[current] << endl;
		end = min_cost(endset, )
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
			endset.erase(remove(endset.begin(),endset.end(), current), endset.end());
			if(endset.empty())
			{
				return 1;
			}
			else
			{
				return _a_star_recursive(maze, start, endset);
			}
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
			totalCost[neighbor[i]] = pathCost[neighbor[i]] + optimal_cost(neighbor[i], end);
			//cout << "neighbor totalCost:" << totalCost[neighbor[i]] << endl;
		}
	}
	return 0;
}
map<coord, int> cost_to_end;
map<coord, int> totalCost;
vector<coord> openSet;
vector<coord> closedSet;
map<coord, coord> cameFrom;
map<coord, int> pathCost;

int _a_star(char *maze, coord start, vector<coord> endset){
	
	openSet.push_back(start);
	pathCost[start] = 0;
	totalCost[start] = optimal_cost(start, end);
	_a_star_test(maze, start, endset);
}

int _a_star_test(char *maze, coord start, vector<coord> endset)
{
	coord current;
	int curPathcost;
	coord prev_end,end;
	
	//While frontier is not empty
	while (!openSet.empty())
	{
		if(prev_end != end)
		{
			//update all total_cost
			update_all_total_cost(end, openSet);
			prev_end  = end;
		}
		current = min_cost(openSet, totalCost);
		//cout << "current.x:" << current.x << ' ' << "current.y" << current.y << endl;
		//cout << "current cost:" << totalCost[current] << endl;

		//Check if we have reached 1 end point
		if ((current.x == end.x) && (current.y == end.y))
		{	


			endset.erase(remove(endset.begin(),endset.end(), current), endset.end());
			if(endset.empty())
			{
				//Append current location to the path
				vector<coord> result = totalPath(cameFrom, current);

				//Since we have reached one point, draw the path onto the maze map
				for (vector<coord>::iterator it = result.begin(); it != result.end(); it++)
				{
					//Skip starting point 'p'
			 		if ((it->x == start.x) && (it->y == start.y))
			 		{
			 			continue;
			 		}
			 		maze[it->y * column + it->x] = '.';
				}
				return 1;
			}

			else
			{
				multi_update(coord curr, vector<coord> endset, map<coord, int> cost_to_end);
				end = min_cost(endset, cost_to_end);				
			}
		}

		//Move the current location out of the frontier
		openSet.erase(remove(openSet.begin(),openSet.end(), current), openSet.end());

		//Mark current loc. as explored
		closedSet.push_back(current);

		//Reset neighbor for ucpoming update
		neighbor.clear();

		//Apeend curr loc's neighbor to the vector
		find_neighbor(maze, current);

		//Iterate through every neighbor
		for (int i = 0; i < neighbor.size(); i++)
		{
			//cout << "neighbor" << neighbor[i].x << ' ' << neighbor[i].y << endl;

			//If neighbor is already explored, skip them
			if (find(closedSet.begin(), closedSet.end(), neighbor[i]) != closedSet.end()){
				continue;
			}

			//Calc neighbor's current path cost
			curPathcost = pathCost[current] + 1;

			//Push neighbor into froniter if not already
			if (find(openSet.begin(), openSet.end(), neighbor[i]) == openSet.end())
			{
				openSet.push_back(neighbor[i]);

				//Initialize path cost of neighbor to MAX
				pathCost[neighbor[i]] = 10000;
			}

			//Compare existing pathcost to the current 
			else if (curPathcost >= pathCost[neighbor[i]])
			{
				continue;
			}

			// from current loc to neighbor is closer than original path, therefore throw away prevoious path to neighbor
			cameFrom[neighbor[i]] = current;
			pathCost[neighbor[i]] = curPathcost;
			
			//Update total cost
			totalCost[neighbor[i]] = pathCost[neighbor[i]] + optimal_cost(neighbor[i], end);
			//cout << "neighbor totalCost:" << totalCost[neighbor[i]] << endl;
		}
		multi_update(coord curr, vector<coord> endset, map<coord, int> cost_to_end);
		end = min_cost(endset, cost_to_end);
	}
	return 0;
}

void multi_update(coord curr, vector<coord> &endset)
{
	for(int i = 0; i < endset.size(); i++)
	{
		cost_to_end[endset[i]] = optimal_cost(curr, endset[i]);
	}
}

void update_all_total_cost(coord end, vector<coord> &openSet)
{
	for(int i = 0; i < openSet.size(); i++)
	{
		totalCost[openSet[i]] = optimal_cost(end, openSet[i]);
	}
}
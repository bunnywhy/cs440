#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <cstdlib>

				//Commmon Class + functions//
//----------------------------------------------------------//
class coord
{
	public:
		int x;
		int y;	
		bool operator==(const coord &other) const ;
};

//Manhatten distance calc.
int MD(coord curr, coord end);

//coordinate for maze array calc
int get_cord(coord curr);

//Cell status + boundary check
int check_cell(char* maze, coord curr);

			//Search method + helper function//
//---------------------------------------------------------//

//A* Search
int AS(void);

//Bread first search
int BFS(char *maze, coord start, coord end);
int BFS_R(char *maze,coord end, std::queue<coord> &pathq);

//Depth first search
int DFS(void);

//Greedy first search
int GFS(char* maze, coord start, coord end);
int GFS_move(char* maze, coord start, coord end);
int GFS_Recurr(char* maze, coord curr, coord end, coord* path, int &point);

#endif
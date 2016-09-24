#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
class coord
{
	public:
		int x;
		int y;	
};
int DFS(void);
int GFS(void);
int AS(void);
int MD(int x, int y, int end_x, int end_y);
int BFS(char *maze, int x_start, int y_start, int* x_end, int* y_end);
int BFS_R(char *maze, int* x_end, int* y_end, std::queue<int> &qx, std::queue<int> &qy);
int get_cord(int x, int y);
int check_cell(char* maze, int x, int y);
#endif
#ifndef A_STAR_H
#define A_STAR_H
#include <map>
#include <algorithm>
#include "algorithm.h"
extern int column, row;
using namespace std;
coord min_cost(vector<coord> openSet, map<coord, int> cost);
void erase(vector<coord> *coord_vec, coord to_be_erased);
int check_wall(char* maze, coord current);
void find_neighbor(char* maze, coord current);
//int a_star(char *maze, coord start, coord end);
vector<coord> totalPath(map<coord, coord> path, coord current);
int optimal_cost(coord cur, coord end);
void update_all_total_cost(coord end, vector<coord> &openSet);
void multi_update(coord curr, vector<coord> &endset);
int _a_star_test(char *maze, coord start, vector<coord> endset);
int _a_star(char *maze, coord start, vector<coord> endset);
#endif
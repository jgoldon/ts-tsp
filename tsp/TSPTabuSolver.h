#pragma once
#include "map.h"
#include "solution.h"
class TSPTabuSolver {
public:
	TSPTabuSolver(string filePath);
	void solve(int);
	Solution* getBestNearbySolution(int);
	void resetTabuList();
	double getBSS();
	double bestSolverScore;
private:
	int** tabu_list;
	int** tabu_f_list;
	Map* map;
	Solution* s;
};


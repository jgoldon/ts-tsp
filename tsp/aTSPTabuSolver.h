#pragma once
#include "asolution.h"
class aTSPTabuSolver {
public:
	aTSPTabuSolver(string filePath);
	void solve(int);
	aSolution* getBestNearbySolution(int);
	void resetTabuList();
	double getBSS();
	double bestSolverScore;
private:
	int** tabu_list;
	int** tabu_f_list;
	aMap* amap;
	aSolution* s;
};


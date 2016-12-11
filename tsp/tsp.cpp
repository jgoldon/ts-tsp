// tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "Solution.h"
#include "TSPTabuSolver.h"

int main()
{
	TSPTabuSolver solver2("tsp0.txt");
	solver2.solve(6);
	TSPTabuSolver solver1("tsp1.txt");
	solver1.solve(5);



	TSPTabuSolver solver3("tsp2.txt");
	solver3.solve(7);
}


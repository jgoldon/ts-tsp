#pragma once
#include "Map.h"
class Solution
{
	double score;
	Map* map;
	int* v;
public:
	void computeScore();
	void swapSolve(int i, int j);
	Solution(Map* map);
	void initSolution();
	int getV(int key);
	double getScore();
	void set(int key, int value);
	void free();
	void printPath();
};


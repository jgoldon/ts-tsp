#pragma once
#include "aMap.h"
class aSolution
{
	double score;
	aMap* amap;
	int* v;
public:
	void computeScore();
	void swapSolve(int i, int j);
	aSolution(aMap* map);
	void initSolution();
	int getV(int key);
	double getScore();
	void set(int key, int value);
	void free();
	void printPath();
};

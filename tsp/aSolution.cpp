#include "stdafx.h"
#include "aSolution.h"


aSolution::aSolution(aMap* amap)
{
	this->amap = amap;
	v = new int[amap->Dimension];
	score = 0;
	initSolution();
}

void aSolution::initSolution()
{
	for (int i = 0; i < amap->Dimension; i++) 
	{
		this->v[i] = i;
	}
	srand(time(NULL));
	for (int i = (amap->Dimension - 1); i >= 0; i--) 
	{
		int j = rand() % amap->Dimension;
		swap(this->v[i], this->v[j]);
	}
	computeScore();
}

void aSolution::computeScore() 
{
	score = 0;
	for (int i = 0; i < (amap->Dimension - 1); i++) 
	{
		score += amap->CalculateDistance(this->v[i], this->v[i + 1]);
	}
	score += amap->CalculateDistance(this->v[amap->Dimension - 1], this->v[0]);
}

void aSolution::printPath() 
{
	cout << "Path: ";
	for (int i = 0; i < amap->Dimension; i++) 
	{
		cout << this->v[i] << " ";
	}
	cout << endl;
}

int aSolution::getV(int key) 
{
	return this->v[key];
}
void aSolution::set(int key, int value) 
{
	this->v[key] = value;
}

void aSolution::swapSolve(int i, int j) 
{
	swap(this->v[i], this->v[j]);
}

double aSolution::getScore() 
{
	computeScore();
	return score;
}

void aSolution::free() 
{
	delete[] this->v;
}


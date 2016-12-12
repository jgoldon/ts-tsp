#include "stdafx.h"
#include "Solution.h"


Solution::Solution(Map* map) 
{
	this->map = map;
	v = new int[map->Dimension];
	score = 0;
	initSolution();
}

void Solution::initSolution() 
{
	for (int i = 0; i < map->Dimension; i++) {
		this->v[i] = i;
	}
	srand(time(NULL));
	for (int i = (map->Dimension - 1); i >= 0; i--) {
		int j = rand() % map->Dimension;
		swap(this->v[i], this->v[j]);
	}
	computeScore();
}

void Solution::computeScore() {
	score = 0;
	for (int i = 0; i < (map->Dimension - 1); i++) {
		score += map->CalculateDistance(this->v[i], this->v[i + 1]);
	}
	score += map->CalculateDistance(this->v[map->Dimension - 1], this->v[0]);
}

void Solution::printPath() {
	cout << "Path: ";
	for (int i = 0; i < map->Dimension; i++) {
		cout << this->v[i] << " ";
	}
	cout << endl;
}

int Solution::getV(int key) {
	return this->v[key];
}
void Solution::set(int key, int value) {
	this->v[key] = value;
}

void Solution::swapSolve(int i, int j) {
	swap(this->v[i], this->v[j]);
}

double Solution::getScore() {
	computeScore();
	return score;
}

void Solution::free() {
	delete[] this->v;
}

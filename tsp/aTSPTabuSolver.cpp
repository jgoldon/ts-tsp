#include "stdafx.h"
#include "aTSPTabuSolver.h"


//#define TABU_LENGTH 5
//#define NUM_INTERATION 50
//#define PENAL_LONG_TERM 5
//#define LONG_TERM_LENGTH 20
//#define TIME_TRY 25
#define TABU_LENGTH 13
#define NUM_INTERATION 600
#define PENAL_LONG_TERM 8
#define LONG_TERM_LENGTH 20
#define TIME_TRY 30

aTSPTabuSolver::aTSPTabuSolver(string filePath)
{
	amap = new aMap(filePath);
	amap->Load();
	s = new aSolution(amap);
	bestSolverScore = (std::numeric_limits<double>::max)();

	//double asd = (std::numeric_limits<double>::max)();

	tabu_list = new int*[amap->Dimension];
	tabu_f_list = new int*[amap->Dimension];
	for (int i = 0; i < amap->Dimension; i++)
	{
		tabu_f_list[i] = new int[amap->Dimension];
		tabu_list[i] = new int[amap->Dimension];
	}

	resetTabuList();
}

void aTSPTabuSolver::resetTabuList() {
	for (int i = 0; i < amap->Dimension; i++) {
		for (int j = 0; j < amap->Dimension; j++) {
			tabu_list[i][j] = 0;
			tabu_f_list[i][j] = 0;
		}
	}
}

/*
numCandidate : times that solver run to get the best score
*/
void aTSPTabuSolver::solve(int numCandidate)
{
	aSolution bestSolution(amap);
	double bestSolutionScore = bestSolution.getScore();

	for (int loopCount = 0; loopCount < numCandidate; loopCount++) {
		s->initSolution();
		resetTabuList();
		//cout << "Init Score : " << s->getScore() << endl;
		int countTime = 0;
		bestSolverScore = (std::numeric_limits<double>::max)();
		for (int i = 0; i < NUM_INTERATION; i++) {
			s = this->getBestNearbySolution(i);
			double score = s->getScore();
			//cout << "cos" << endl;
			if (score < bestSolverScore) {
				bestSolverScore = score;
				countTime = 0;

				if (bestSolverScore < bestSolutionScore) {
					for (int j = 0; j < amap->Dimension; j++) {
						bestSolution.set(j, s->getV(j));
					}
					bestSolutionScore = bestSolverScore;
				}
			}
			else
			{
				countTime++;
				if (countTime > TIME_TRY) {
					break;
				}
			}
		}

	}
	cout << "Best score : " << bestSolutionScore << endl;
	//bestSolution.printPath();
}
double aTSPTabuSolver::getBSS()
{
	return this->bestSolverScore;
}
aSolution* aTSPTabuSolver::getBestNearbySolution(int it)
{
	double bestScore = (std::numeric_limits<double>::max)();
	int vertexA = 0;
	int vertexB = 1;
	for (int i = 0; i < amap->Dimension; i++) {
		for (int j = (i + 1); j < amap->Dimension; j++) {
			//swap for new solution
			s->swapSolve(i, j);
			double currentScore = s->getScore();
			double penalScore = currentScore + PENAL_LONG_TERM * tabu_f_list[i][j];
			if ((bestScore > penalScore && this->tabu_list[i][j] <= it) || currentScore < bestSolverScore) {
				vertexA = i;
				vertexB = j;
				bestScore = penalScore;
				this->tabu_list[i][j] = (it + TABU_LENGTH);
				this->tabu_list[j][i] = (it + TABU_LENGTH);
			}
			// back to orginal solution
			s->swapSolve(j, i);
			if (tabu_f_list[i][j] > 0 && it > LONG_TERM_LENGTH) tabu_f_list[i][j] -= 1;
		}
	}
	tabu_f_list[vertexA][vertexB] += 2;
	s->swapSolve(vertexA, vertexB);
	return s;
}
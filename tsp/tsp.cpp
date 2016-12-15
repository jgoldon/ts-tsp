// tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "Solution.h"
#include "TSPTabuSolver.h"
#include "aTSPTabuSolver.h"

double PCFreq = 0.0;
__int64 licznik = 0;


void start()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "B³¹d!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	licznik = li.QuadPart;
}
double getTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	//cout << "Operacja zajela: " << (li.QuadPart - licznik) / PCFreq << " milisekund" << endl;
	return double((li.QuadPart - licznik) / PCFreq);
}

int main()
{
	double time = 0;
	double costs = 0;
	for (int i = 0; i < 1; i++)
	{
		TSPTabuSolver solver2("a280.tsp");
		start();
		solver2.solve(1);
		time += getTime();
		costs += solver2.bestSolverScore;
	}

	cout << time / 1 << " " << costs / 1 << " " << endl;



	////do testow
	//ofstream file;
	////file.open("test.txt");
	//file.open("test439.txt");
	////string names[6];
	//string anames[6];


	//names[0] = "berlin52.tsp";
	//names[1] = "pr76.tsp";
	//names[2] = "pr152.tsp";
	//names[3] = "a280.tsp";
	//names[4] = "lin318.tsp";
	//names[5] = "pr439.tsp";
	//anames[0] = "br17.atsp";
	//anames[1] = "ftv33.atsp";
	//anames[2] = "ftv70.atsp";
	//anames[3] = "kro124p.atsp";
	//anames[4] = "ftv170.atsp";
	//anames[5] = "rbg443.atsp";
	//double solves[8] = { 0.9, 0.95, 0.99, 0.995, 0.999, 0.9995, 0.9999, 0.99995 };


	//for (int i = 0; i < 6; i++)
	//{
	//	//double costs[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		//double costs = 0;
	//	//double time[8] = { 0, 0, 0, 0, 0, 0, 0 , 0 };
		//double time = 0;
	//	TSPTabuSolver solver2(names[i]);
	//	file << names[i] << endl;
	//	file << endl;
		//for (int j = 0; j < 3; j++)
		//{
		//	start();
		//	solver2.solve(1);
		//	time += getTime();
		//	costs += solver2.bestSolverScore;
		//}

		//	file << time / 3 << " " << costs / 3 << endl;
		//file << endl;
	//	cout << "-------------------------------------" << endl;
	//}

	//asymetryczny
	//for (int i = 0; i < 6; i++)
	//{
	//	//double atime[8] = { 0, 0, 0, 0, 0, 0, 0 , 0 };
	//	double atime = 0;
	//	//double acosts[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	//	double acosts = 0;
	//	aTSPTabuSolver solver3(anames[i]);
	//	file << anames[i] << endl;
	//	file << endl;
	//	for (int j = 0; j < 3; j++)
	//	{
	//		start();
	//		solver3.solve(1);
	//		atime += getTime();
	//		acosts += solver3.bestSolverScore;
	//	}

	//		file << atime / 3 << " " << acosts / 3 << endl;
	//	file << endl;
	//	cout << "-------------------------------------" << endl;
	//}
	//file.close();
	system("pause");
}


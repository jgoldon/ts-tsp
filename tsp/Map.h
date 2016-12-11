#pragma once
class Map
{
public:
	int numVertex;
	double** coordinate;
	Map(string file);
	double getDistance(int, int);
	string file;
	void free();
};


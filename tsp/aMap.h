#pragma once
class aMap
{
private:
	ifstream file;
public:
	vector <vector < int > > Distances;

	string Name;
	string Type;
	string Comment;
	int Dimension;
	string EdgeWeightType;
	int CalculateDistance(int firstCityIndex, int secondCityIndex);
	aMap(string s);
	~aMap();
	void Load();
};


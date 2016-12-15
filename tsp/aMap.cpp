#include "stdafx.h"
#include "aMap.h"

aMap::aMap(string s)
{
	file.open(s);
	if (!file.good())
		throw new exception("File not found");
}

void aMap::Load()
{
	string temp;

	while (true)
	{
		getline(file, temp, ':');


		if (temp.find("NAME") != string::npos)
		{
			getline(file, Name);
		}
		if (temp.find("TYPE") != string::npos)
		{
			getline(file, Type);
		}
		if (temp.find("COMMENT") != string::npos)
		{
			getline(file, Comment);
		}
		if (temp.find("DIMENSION") != string::npos)
		{
			file >> Dimension;
		}
		if (temp.find("EDGE_WEIGHT_TYPE") != string::npos)
		{
			getline(file, EdgeWeightType);
			getline(file, temp);
			break;
		}
	}

	for (auto i = 0; i < Dimension; i++)
	{
		Distances.push_back(vector<int>());
	}

	for (auto i = 0; i < Dimension; i++)
	{
		for (auto j = 0; j < Dimension; j++)
		{
			int distance;
			file >> distance;
			Distances[i].push_back(distance);
		}
	}
}

int aMap::CalculateDistance(int firstCityIndex, int secondCityIndex)
{
	int dist = this->Distances[firstCityIndex].at(secondCityIndex);
	//cout << firstCityX << " " << firstCityIndex<< " " << firstCityY << " " << firstCityIndex << " " << secondCityX << " " << secondCityIndex<< " " << secondCityY << " " << secondCityIndex << " \n";
	return dist;
}

aMap::~aMap()
{
	file.close();
}

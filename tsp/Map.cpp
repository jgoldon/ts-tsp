#include "stdafx.h"
#include "Map.h"



Map::Map(string s)
{
	file.open(s);
	if (!file.good())
		throw new exception("File not found");
}

void Map::Load()
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
		int rowNumber;
		float x;
		float y;

		file >> rowNumber >> x >> y;

		MapX.push_back(x);
		MapY.push_back(y);
	}
}

float Map::CalculateDistance(int firstCityIndex, int secondCityIndex)
{
	float firstCityX = this->MapX[firstCityIndex];
	float firstCityY = this->MapY[firstCityIndex];

	float secondCityX = this->MapX[secondCityIndex];
	float secondCityY = this->MapY[secondCityIndex];

	float x = firstCityX - secondCityX;
	float y = firstCityY - secondCityY;

	float dist = pow(x, 2) + pow(y, 2);
	dist = round(sqrt(dist));
	//cout << firstCityX << " " << firstCityIndex<< " " << firstCityY << " " << firstCityIndex << " " << secondCityX << " " << secondCityIndex<< " " << secondCityY << " " << secondCityIndex << " \n";
	return dist;
}


Map::~Map()
{
	file.close();
}
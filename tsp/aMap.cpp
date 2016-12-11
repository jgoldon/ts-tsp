#include "stdafx.h"
#include "aMap.h"

//string DIMESION_PROPERTY = "DIMENSION";
//string BEST_PROPERTY = "BEST";
//string START_VERTEX_PAGE = "EDGE_WEIGHT_SECTION";

aMap::aMap(string filePath)
{
	//string line;
	//cout << endl;
	//cout << "File:  " << filePath << endl;
	//ifstream dataFile;
	//dataFile.open(filePath.c_str());
	//if (dataFile.is_open())
	//{
	//	bool vertexDataRegion = false;
	//	while (dataFile.good())
	//	{
	//		getline(dataFile, line);

	//		if (vertexDataRegion)
	//		{
	//			int vertexId;
	//			double posX;
	//			double posY;
	//			sscanf(line.c_str(), "%d %lf %lf", &vertexId, &posX, &posY);
	//			vertexId--; // we store vertex from 0

	//			this->coordinate[vertexId][0] = posX;
	//			this->coordinate[vertexId][1] = posY;
	//		}

	//		if (line.find(DIMESION_PROPERTY) == 0)
	//		{
	//			unsigned int index = 0;
	//			for (; index < line.size(); index++) {
	//				if (line[index] >= '0' && line[index] <= '9') break;
	//			}
	//			this->numVertex = atoi(line.substr(index, 100).c_str());
	//			cout << "Dimension: " << this->numVertex << endl;

	//			this->coordinate = new double*[this->numVertex];
	//			for (int i = 0; i < this->numVertex; i++)
	//			{
	//				this->coordinate[i] = new double[2];
	//			}
	//		}

	//		if (line.find(BEST_PROPERTY) == 0)
	//		{
	//			int bestValue;
	//			unsigned int index = 0;
	//			for (; index < line.size(); index++) {
	//				if (line[index] >= '0' && line[index] <= '9') break;
	//			}
	//			bestValue = atoi(line.substr(index, 100).c_str());
	//			cout << "Cost: " << bestValue << endl;
	//		}

	//		if (line.find(START_VERTEX_PAGE) == 0) {
	//			vertexDataRegion = true;
	//		}
	//	}
	//	dataFile.close();
	//}
}


aMap::~aMap()
{
}

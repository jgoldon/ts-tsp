#pragma once
class Map
{
private:
	ifstream file;
public:
	vector<float> MapX;
	vector<float> MapY;
	string Name;
	string Type;
	string Comment;
	int Dimension;
	string EdgeWeightType;

	Map(string s);
	~Map();
	float CalculateDistance(int firstCityIndex, int secondCityIndex);
	void Load();
};


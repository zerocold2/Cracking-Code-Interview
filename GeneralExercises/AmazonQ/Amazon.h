#pragma once
#include "../CP.h"

class Amazon
{
public:
	int getMinimumCostToConstruct(int numTotalAvailableCities,
		int numTotalAvailableRoads,
		int** roadsAvailable,
		int numNewRoadsConstruct,
		int** costNewRoadsConstruct);
	void Driver_getMinimumCostToConstruct();

	vector<string> orderedJunctionBoxes(int numberOfBoxes, vector<string> boxList);
};


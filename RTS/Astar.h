#pragma once
#include <vector>
#include "Vector2.h"

using namespace std;

class Astar
{
public:
	Astar(vector<vector<int>>* graph);
	vector<Vector2> mostShortWay(Vector2 start, Vector2 target);

private:
	vector<vector<int>>* graph;
	vector<vector<int>> distance;
	vector<Vector2> openList;
	vector<Vector2> closedList;
	vector<vector<Vector2>> predecessor;
	vector<Vector2> neighbours;
	vector<vector<int>> heuristique;

	int getDistance(Vector2 node1, Vector2 node2);
	vector<Vector2> reconstructPath(Vector2 start, Vector2 target);
	void findNeightbours(vector<vector<int>>* graph, Vector2 node);
	void initialize(vector<vector<int>>* mat, Vector2 deb);
};
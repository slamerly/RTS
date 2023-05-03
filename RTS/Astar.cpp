#include "Astar.h"
#include <iostream>
#include "Maths.h"

Astar::Astar(vector<vector<int>>* graphP)
{
	graph = graphP;
}

vector<Vector2> Astar::mostShortWay(Vector2 start, Vector2 target)
{
	Vector2 currentNode;

	//cout << "target : " << target.x << ", " << target.y << endl;

	initialize(graph, start);

	while (!openList.empty())
	{
		currentNode = openList.at(0);

		for (int i = 1; i < openList.size(); i++)
		{
			if (distance[openList.at(i).x][openList.at(i).y] < distance[currentNode.x][currentNode.y] || (distance[openList.at(i).x][openList.at(i).y] == distance[currentNode.x][currentNode.y] && heuristique[openList.at(i).x][openList.at(i).y] < heuristique[currentNode.x][currentNode.y]))
			{
				currentNode = openList.at(i);
			}
		}

		//cout << "currentNode : " << currentNode.x << ", " << currentNode.y << endl;

		auto iter = find(begin(openList), end(openList), currentNode);
		openList.erase(iter);
		closedList.push_back(currentNode);

		if (currentNode == target)
		{
			return reconstructPath(start, target);;
		}

		findNeightbours(graph, currentNode);

		for (size_t i = 0; i < neighbours.size(); i++)
		{
			auto neightClosedList = find(begin(closedList), end(closedList), neighbours.at(i));
			auto neightOpenList = find(begin(openList), end(openList), neighbours.at(i));

			int newDistance = distance[currentNode.x][currentNode.y] + getDistance(currentNode, neighbours.at(i));

			if (!(neightClosedList != end(closedList)) && (!(neightOpenList != end(openList)) || (newDistance < distance[neighbours.at(i).x][neighbours.at(i).y])))
			{
				distance[neighbours.at(i).x][neighbours.at(i).y] = newDistance;
				heuristique[neighbours.at(i).x][neighbours.at(i).y] = getDistance(neighbours.at(i), target);
				predecessor[neighbours.at(i).x][neighbours.at(i).y] = currentNode;

				if (neightOpenList == end(openList))
				{
					openList.push_back(neighbours.at(i));
				}
			}
		}
	}
}

int Astar::getDistance(Vector2 node1, Vector2 node2)
{
	int distX = abs(node1.x - node2.x);
	int distY = abs(node1.y - node2.y);

	if (distX > distY)
		return 14 * distY + 10 * (distX - distY);
	return 14 * distX + 10 * (distY - distX);
}

vector<Vector2> Astar::reconstructPath(Vector2 start, Vector2 target)
{
	cout << "---- ASTAR ----" << endl;
	cout << "ORIGIN(" << start.x << ", " << start.y << ") - DESTINATION(" << target.x << ", " << target.y << ")" << endl;
	//cout << "Cost: " << distance.at(target) << endl;

	vector<Vector2> way;

	way.push_back(target);
	//cout << "Road: [" << target.x << ", " << target.y << "] <- ";
	Vector2 node = target;
	while (node != start)
	{
		//cout << "[" << predecessor[node.x][node.y].x << ", " << predecessor[node.x][node.y].y << "]";
		node = predecessor[node.x][node.y];
		way.push_back(node);
		/*
		if (node != start)
			cout << " <- ";
		*/
	}

	return way;
}

void Astar::findNeightbours(vector<vector<int>>* graph, Vector2 node)
{
	neighbours.clear();

	//cout << endl << node.x << ", " << node.y << " : " << endl;

	for (int i = -1; i < 2; i++)
	{
		if (node.x + i >= 0 && node.x + i < graph->size())
		{
			for (int j = -1; j < 2; j++)
			{
				if (node.y + j >= 0 && node.y + j < graph->at(0).size()
					&& (i != 0 || j != 0))
				{
					if (graph->at(node.x + i).at(node.y + j) < 1)
					{
						//cout << "    " << node.x + i << ", " << node.y + j << endl;
						neighbours.push_back({ node.x + i, node.y + j });
					}
				}
			}
		}
	}
}

void Astar::initialize(vector<vector<int>>* mat, Vector2 deb)
{
	distance.clear();
	openList.clear();
	closedList.clear();
	predecessor.clear();
	neighbours.clear();
	heuristique.clear();

	openList.push_back(deb);

	for (int i = 0; i < mat->size(); i++)
	{
		vector<int> line;
		vector<Vector2> linePred;
		for (int j = 0; j < mat->at(0).size(); j++)
		{
			if (i == deb.x && j == deb.y)
			{
				line.push_back(0);
			}
			else
			{
				line.push_back(1000000);
			}
			linePred.push_back({ float(i), float(j) });
		}
		distance.push_back(line);
		heuristique.push_back(line);

		predecessor.push_back(linePred);
	}
	//std::cout << "dist : " << distance.size() << std::endl;
}

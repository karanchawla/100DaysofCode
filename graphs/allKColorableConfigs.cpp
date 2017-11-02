//Print all k colorable configurations of the graph
#include <iostream>
#include <vector> 

using namespace std;

#define N 5

struct Edge
{
	int source;
	int destination;
};

class Graph
{
public:
	vector<int> adjList[N];

	Graph(const vector<Edge> &edges)
	{
		for(int i = 0; i < edges.size(); i++)
		{
			int source = edges[i].source;
			int destination = edges[i].destination;

			adjList[source].push_back(destination);
			adjList[destination].push_back(source);
		}
	}

	
}
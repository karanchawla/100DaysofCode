#include <iostream>
#include <vector> 

using namespace std; 

#define N 6

struct Edge
{
	int src;
	int dest;
};

class Graph
{
public:
	vector<int> adjList(N);

	Graph(const vector<int> &edges)
	{
		for(size_t i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

string COLORS[] = {"", "RED", "BLUE", "GREEN", "YELLOW"};

bool isValidColor(Graph const &graph, int vertex, int c, const vector<int>& color)
{
	for(int u: graph.adjList[vertex])
	{
		if(color[u] == c)
			return false;
	}

	return true;
}

void kColorable(Graph const &graph, int v, int k, vector<int>& color)
{
	if(v==N)
	{
		//print color configuration
	}

	for(int c = 1; c<k; c++)
	{
		if(isValidColor(graph, v, c, color))
		{
			color[v] = c;

			kColorable(graph, v + 1, k, color);

			color[v] = 0;
		}	
	}
}
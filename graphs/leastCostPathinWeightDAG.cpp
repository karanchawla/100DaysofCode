#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

#define N 5

struct Edge
{
	int source;
	int destination;
	int weight;
};

class Graph
{
public:
	vector<int> adjList[3*N];
	
	Graph(vector<Edge> &edges, int x)
	{
		for(int i = 0; i < edges.size(); i++)
		{
			int u = edges[i].source;
			int v = edges[i].destination;
			int weight = edges[i].weight;

			if(weight == 3*x)
			{
				adjList[u].push_back(u + N);
				adjList[u + N].push_back(u + 2*N);
				adjList[u + 2*N].push_back(v);
			}
			else if(weight == 2*x)
			{
				adjList[u].push_back(u + N);
				adjList[u + N].push_back(v);
			}
			else
			{
				adjList[u].push_back(v);
			}
		}
	}
};

void BFS(const Graph &graph, int source, int destination)
{
	queue<int> q;
	vector<bool> discovered(N, false);

	discovered[source] = true;

	vector<int> parent(3*N, -1);

	q.push(source);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(auto v: graph.adjList[u])
		{
			if(v == destination)
			{
				int cost = -1;
				// Print path;
			}
			if(!discovered[v])
			{
				discovered[v] = true;
				q.push(v);
				parent[v] = u;
			}
		}
	}

}
#include <vector> 
#include <iostream>
#include <cstdlib> 

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
	vector<Edge> adjList[N];

	Graph(const vector<Edge>& edges)
	{
		for(int i = 0; i < edges.size(); ++i)
		{
			int source = edges[i].source;
			int destination = edges[i].destination;
			int weight = edges[i].weight;

			adjList[source].push_back({source, destination, weight});
		}
	}

	void printGraph() const
	{
		for(int i = 0; i < N; i++)
		{
			cout << i << " ";
			for(auto u: adjList[i])
			{
				cout << u.destination << " ";
			}
			cout << endl;
		}
	}
};

void printPath(vector<int>& parent, int v)
{
	if(v<0)
		return;

	printPath(parent, parent[v]);
	cout << v << " ";
}

void bellmanFord(vector<Edge> &edges, int source)
{
	int E = edges.size();

	vector<int> distance(N, INT_MAX);
	distance[source] = 0;

	vector<int> parent(N, -1);

	int u, v, w;
	int k = N;

	// Run the loops N - 1 times
	while(--k)
	{
		for(int j = 0; j < E; j++)
		{
			u = edges[j].source;
			v = edges[j].destination;
			w = edges[j].weight;

			if(distance[u]!=INT_MAX && (distance[u] + w) < distance[v])
			{
				distance[v] = w + distance[u];
				parent[v] = u;
			}
		}
	}

	// Run the relaxation step once more to check for negative cycles
	for(int i = 0; i < E; i++)
	{
		int src = edges[i].source;
		int dest = edges[i].destination;
		int weight = edges[i].weight;

		if(distance[dest]!=INT_MAX && (distance[u] + weight) < distance[dest])
		{
			cout << "Negative cycle found";
			return;
		}
	}
}
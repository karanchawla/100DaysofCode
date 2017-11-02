#include <vector> 
#include <iostream>

using namespace std;

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

	Graph(const vector<Edge> &edges)
	{
		for(int i = 0; i < edges.size(); i++)
		{
			int source = edges[i].source;
			int destination = edges[i].destination;
			int weight = edges[i].weight;

			adjList[source].push_back({source, destination, weight});
		}
	}

	void printGraph() const
	{
		for(int i = 0; i < edges.size(); i++)
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

void DFS(Graph &graph, int v, vector<int> &departure, vector<bool> &discovered, int &time)
{
	discovered[v] = true;

	for(Edge e: graph.adjList[v])
	{
		int u = e.destination;
		if(!discovered[u])
		{
			DFS(graph, u, departure, discovered, time);
		}
	}

	departure[time] = v;
	time++;
}

void findShortestDistance(Graph &graph, int source)
{
	vector<bool> discovered(N, false);

	vector<int> departure(N, -1);

	int time = 0;

	for(int i = 0; i < N; i++)
	{
		if(!discovered[i])
			DFS(graph, i, departure, discovered, time);
	}

	vector<int> cost(N, INT_MAX);
	cost[source] = 0;

	for(int i = N - 1; i >=0; i--)
	{
		int u = departure[i];
		for(Edge e: graph.adjList[v])
		{
			int v = e.destination;
			int w = e.weight;
			if(cost[u]!= INT_MAX && cost[u] + w < cost[v])
			{
				cost[v] = cost[u] + w;
			}
		}
	}
}
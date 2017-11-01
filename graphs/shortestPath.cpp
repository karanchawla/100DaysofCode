#include <vector> 
#include <iostream>
#include <queue>

#define N 7

using namespace std;

struct Edge
{
	int source, destination, weight;
};

class Graph
{
public:
	vector<Edge> adjList[N]; 

	Graph(vector<Edge>& edges)
	{
		for(int i = 0; i < edges.size(); i++ )
		{
			int src = edges[i].source;
			int dest = edges[i].destination;
			int weight = edges[i].weight;

			adjList[src].push_back({src, dest, weight});
		}
	}

	void printGraph() const
	{
		for(int i = 0; i < N; i++)
		{
			cout << i << " ";
			for(auto v: adjList[i])
			{
				cout << v.destination;
			}
			cout << endl;
		}
	}
};

struct Node
{
	int vertex;
	int weight;
};

struct comp
{
	bool operator()(const Node& firstNode, const Node& secondNode)
	{	
		return firstNode.weight > secondNode.weight;
	}	
};


void dijkstra(const Graph& graph, const int source)
{
	priority_queue<Node, vector<Node>, comp> minHeap;
	minHeap.push({source, 0});

	vector<bool> processed(N, false);
	processed[source] = true;

	vector<int> distance(N, INT_MAX);
	distance[source] = 0;

	vector<int> parent(N,-1);

	while(!minHeap.empty())
	{
		Node topVertex = minHeap.top();
		minHeap.pop();

		int u = topVertex.vertex;

		for(auto i: graph.adjList[u])
		{
			int src = i.source;
			int dest = i.destination;
			int weight = i.weight;
			if(!processed[dest] && (weight + distance[u]) < distance[dest])
			{
				distance[dest] = weight + distance[u];
				parent[dest] = u;
				minHeap.push({dest, distance[dest]});
			}	
		}

		processed[u] = true;
	}
}

void printRoute(const vector<int>& parent, int i)
{
	if (i<0)
		return;

	printRoute(parent, parent[i]);
	cout << "i" << " ";
}


int main()
{
	vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };

    Graph graph(edges);
    
    graph.printGraph();
}
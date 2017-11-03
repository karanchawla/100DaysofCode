//
//  graphs.cpp
//  
//
//  Created by Karan Chawla on 10/22/17.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N = 6;

struct Edge
{
    int src;
    int dest;
    int weight;
};

class Graph
{
public:
    vector<int> adjList[6];
    
    Graph(vector<Edge> &edges)
    {
        for(unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            
            adjList[src].push_back({src, dest, weight});
        }
        
    }
};

struct Node
{
    int vertex, weight;
};

void printRoute(int prev[], int i)
{
    if(i<0)
        return;
    printRoute(prev, prev[i]);
    cout << "i" << " ";
}

bool comp(const Node& left, const Node& right)
{
    return left.weight > right.weight;
}

// Single source shortest paths 
void shortestPath(const Graph& graph, int source)
{
    priority_queue<Node, vector<Node>, comp> minHeap;
    minHeap.push({source, 0});


    vector<int> dist(N, INT_MAX);
    dist[source] = 0;

    bool done[N] = {0};
    done[source] = 1;

    int prev[N] = {-1};

    while(!minHeap.empty())
    {
        Node node = minHeap.top();
        minHeap.pop();

        int u = node.vertex;
        for(auto i : graph.adjList[u])
        {
            int v = i.dest;
            int weight = i.weight;

            if(!done[v] && (dist[u] + weight) < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                minHeap.push({v, dist[v]});
            }
        }

        done[u] = 1;
    }
}

int main()
{
    vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };
    Graph graph(edges);
    
    printGraph(graph);

    return (0);
}

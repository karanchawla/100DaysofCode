#include <iostream> 
#include <vector> 

using namespace std; 

#define N 8

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, -2, 2};

bool isValid(int x, int y)
{
	if(x < 0 || y <0 || x>=N || y>=N)
		return false;

	return true;
}

struct Node
{
	int x, y, dist;

	bool const operator==(const Node& a) const
	{
		return x==o.x && y==o.y;
	}

	bool operator <(const Node& o) const
	{
		return x < o.x || (x==o.x && y<o.y);
	}
};


int BFS(Node src, Node dest)
{
	map<Node, bool> visited; 

	queue<Node> q; 
	q.push(src);

	while(!q.empty())
	{
		Node node = q.front();
		q.pop();

		int x = q.x, y = q.y, dist = q.dist;

		if(x == dest.x && y==dest.y)
		{
			return dist;
		}

		if(visited.find(node) == visited.end())
		{
			visited[node] = true;

			for(int i = 0; i < 8; i++)
			{
				int pos1 = x + row[i];
				int pos2 = y + col[i];

				if(isValid(pos1, pos2))
					q.push({pos1, pos2, dist+1});
			} 
		}
	}
}
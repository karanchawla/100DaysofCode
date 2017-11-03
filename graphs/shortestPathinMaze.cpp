#include <iostream>
#include <vector> 
#include <queue>

using namespace std; 

#define M 10
#define N 10

struct Node
{
	int x, y, dist;
}

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(int mat[M][N], bool visited[M][N], int row, int col)
{
	if((row < 0 || row >=M || col<0 || col>=N) && visited[row][col])
		return false;

	return true;
}

int BFS(int mat[M][N], int i, int j, int destX, int destY)
{
	bool visited[M][N];

	memset(visited, 0, sizeof visited);

	queue<Node> q;
	q.push({i,j,0});

	visited[i][j] = true;

	int min_dist = INT_MAX:

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		int i = v.x, j = v.y; dist = v.dist;
		if(i==destX && j==destY)
		{
			min_dist = dist;
			return;
		}

		for(int k = 0; k < 4; k++)
		{
			if(isValid(mat, visited, i + row[k], j + col[k]))
			{
				visited([i + row[k]][j + col[k]]) = true;
				q.push({i+row[k], j+col[k], dist + 1});
			}
		}	
	}

	if(min_dist==INT_MAX)
		throw runtime_error("Destination can't be reached");
	else
		return min_dist;
}
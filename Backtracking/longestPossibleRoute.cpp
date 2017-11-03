#include <iostream>
#include <vector>

using namespace std;

#define M 10
#define N 10

bool isValid(int mat[M][N], int i, int j, bool visited[M][N])
{
	if(i>=0 && i<M && j >=0 && j<N)
	{
		if(!visited[i][j] || mat[i][j])
			return true;
	}

	return false;
}

void findLongestPathinMatrix(int mat[M][N], int i, int j, int destX, int destY, bool visited[M][N], int& max_dist, int dist)
{
	visited[i][j] = true;

	if(i == destX && j == destY)
	{
		max_dist = max(dist, max_dist);
		return;
	}

	if(isValid(mat, i + 1, j, visited))
		findLongestPathinMatrix(mat, i + 1, j, destX, destY, visited, max_dist, dist + 1);

	if(isValid(mat, i, j + 1, visited))
		findLongestPathinMatrix(mat, i, j + 1, destX, destY, visited, max_dist, dist + 1);

	if(isValid(mat, i, j - 1, visited))
		findLongestPathinMatrix(mat, i, j - 1, destX, destY, visited, max_dist, dist + 1);

	if(isValid(mat, i - 1, j, visited))
		findLongestPathinMatrix(mat, i - 1, j, destX, destY, visited, max_dist, dist + 1);

	visited[i][j] = false;
}

int main()
{

	int mat[M][N] = 
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};

	bool visited[M][N];
	memset(visited, false, sizeof visited);

	int max_dist = INT_MIN;

	findLongestPathinMatrix(mat, 0, 0, 5, 7, visited, max_dist, 0);

	if(max_dist!= INT_MIN)
		cout << max_dist;
	else
		throw runtime_error("Destination not found");
	

	return(0);
}
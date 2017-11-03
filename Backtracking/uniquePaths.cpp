#include <iostream>
#include <vector>

using namespace std; 

#define N 4 

bool isValid(const int i, const int j)
{
	if(i<0 || i>=N || j<0 || j>=N)
		return false;

	return true;
}

void findUniquePaths(int mat[N][N], int i, int j, int &freq, int visited[N][N])
{
	if(i==N-1 && j==N-1)
	{
		freq++;
		return;
	}

	visited[i][j] = 1;

	if(isValid(i,j) && mat[i][j])
	{
		if(!visited[i+1][j])
			findUniquePaths(mat, i+1, j, freq, visited);

		if(!visited[i-1][j])
			findUniquePaths(mat, i-1, j, freq, visited);

		if(!visited[i][j+1])
			findUniquePaths(mat, i, j+1, freq, visited);

		if(!visited[i][j-1])
			findUniquePaths(mat, i, j-1, freq, visited);
	}

	visited[i][j] = 0;
}

int main()
{
	int maze[N][N] = 
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	};

	int freq = 0;

	int visited[N][N];

	memset(visited, 0, sizeof visited);
	
	// start from source cell (0, 0)
	findUniquePaths(maze, 0, 0, freq, visited);
	
	std::cout << "Total number of unique paths are " << freq;
	
	return 0;

}


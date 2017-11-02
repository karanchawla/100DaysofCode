#include <vector> 
#include <iostream>

using namespace std;
#define M 8
#define N 6

int findLargestSquare(int mat[M][N], int m, int n, int &max_size)
{
	if(m==0 || n==0 || mat[m][n]==0)
		return mat[m][n];

	int left = findLargestSquare(mat, m, n-1, max_size);

	int top = findLargestSquare(mat, m-1, n, max_size);

	int top_left = findLargestSquare(mat, m-1, n-1, max_size);

	int size = 1 + min(min(left, top), top_left);

	max_size = max(size, max_size);

	return size;
}

int findLargestSquareMemoized(int mat[M][N])
{
	int lookup[M][N];
	int max = INT_MIN;

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			lookup[i][j] = mat[i][j];

			if(i && j && mat[i][j])

				lookup[i][j] = min(min(lookup[i-1][j], lookup[i][j-1]), lookup[i-1][j-1]) + 1;

			if(lookup[i][j]>max)
				max = lookup[i][j];
		}
	}

	return max;
}

int main()
{

	int mat[M][N] =
	{ 
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 }, 
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	int size = 0;

	cout << findLargestSquareMemoized(mat);

	return(0);
}
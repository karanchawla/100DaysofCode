#include <iostream>
#include <vector> 

using namespace std; 

int findMinCost(int cost[M][N])
{
	int lookup[M][N];

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			lookup[i][j] = cost[M][N];

			if(i==0 && j > 0)
				lookup[i][j] += lookup[i][j-1];

			else if (i > 0 && j==0)
				lookup[i][j] += lookup[i-1][j];

			else if(i > 0 && j > 0)
				lookup[i][j] += min(lookup[i-1][j], lookup[i][j-1]);
		}
	}

	return lookup[M-1][N-1];
}

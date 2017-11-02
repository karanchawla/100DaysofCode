#include <vector> 
#include <iostream>

using namespace std;

int matrixChainMultiplication(int dims[], int i, int j)
{
	if(j <= i+1)
		return 0;

	int min = INT_MAX;

	for(int k = i+1; k<=j-1; k++)
	{
		int cost = matrixChainMultiplication(dims, i, k);

		cost += matrixChainMultiplication(dims, k, j);

		cost += dims[i] * dims[k] * dims[j];

		if(cost < min)
			min = cost;
	}

	return min;
}

int matrixChainMultiplicationMemoized(int dims[], int i, int j)
{
	if(j<=i+1)
		return 0;

	int minCost = INT_MAX;

	static int lookup[4][4];

	if(lookup[i][j]==0)
	{
		for(int k = i+1; k <= j-1; k++)
		{
			int cost = matrixChainMultiplicationMemoized(dims, i, k);

			cost+= matrixChainMultiplicationMemoized(dims, k, j);

			cost += dims[i]*dims[k]*dims[j];

			if (cost < minCost)
				minCost = cost;
		}

		lookup[i][j] = minCost;
	}

	return minCost;
}

int main(void)
{
	int dims[] = {10, 30, 5, 60};

	int n = sizeof(dims)/sizeof(int);

	cout << matrixChainMultiplicationMemoized(dims, 0, n-1);
}
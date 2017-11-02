#include <iostream>
#include <string> 
#include <unordered_map>
#define N 6
using namespace std; 

unordered_map<string, string> lookup;

bool isValid(int i, int j)
{
	return(i>=0 && i<N && j>=0 && j < N);
}

string findLongestPath(int mat[N][N], int i, int j)
{
	if(!isValid(i, j))
		return 0;

	string key = to_string(i) + "|" + to_string(j);

	if(lookup.find(key)==lookup.end())
	{
		string path; 

		if(i > 0 && mat[i-1][j] - mat[i][j]== 1)
			path = findLongestPath(mat, i-1, j);

		if(j+1 < N && mat[i][j+1] - mat[i][j]==1)
			path = findLongestPath(mat, i, j+1);

		if(i+1 < N && mat[i+1][j] - mat[i][j] == 1)
			path = findLongestPath(mat, i+1, j);

		if(j>0 && mat[i][j-1] - mat[i][j] == 1)
			path = findLongestPath(mat, i, j-1);

		lookup[key] = to_string(mat[i][j]) + "-" + path;
	}

	return lookup[key];
}

int main()
{
	int mat[N][N] = 
	{ 
		{ 10, 13, 14, 21, 23 },
		{ 11,  9, 22,  2,  3 },
		{ 12,  8,  1,  5,  4 },
		{ 15, 24,  7,  6, 20 },
		{ 16, 17, 18, 19, 25 }
	};

	string res;				// stores longest path found so far
	string str;				// stores current path
	int resSize = INT_MIN;	// stores no. of elements in res

	// from each cell (i, j), find the longest path starting from it
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			// str would be like 1 - 2 - 3 - 4 - 5 -
			string str = findLongestPath(mat, i, j);
			
			// find number of elements involved in current path
			int size = count(str.begin(), str.end(), '-');
			
			// update result if longer path is found
			if (size > resSize)
				res = str, resSize = size;
		}
	}
		
	// print the path
	cout << res;

	return 0;
}
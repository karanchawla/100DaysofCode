#include <iostream> 
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
	int count = 0;
	int repeat = 0;

	for(int i = 0; i <grid.size(); i++)
	{
		for(int j =0; j < grid[i].size(); j++)
		{
			count++;
			if(i!=0 && grid[i-1][j] == 1) repeat++;
			if(j!=0 && grid[i][j-1] == 1) repeat++;
		}
	}

	return 4*count - 2*repeat;
}
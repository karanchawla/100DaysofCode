#include <iostream>
#include <vector>
#include <climits> 
#include <unorderd_map>

using namespace std;

int minSubMatrixDegree(const vector<int> &nums)
{
	unorderd_map<int, vector<int>> map;
	int min_dist = INT_MIN;
	int degree = 0;
	//create counter
	for(int i = 0; i < nums.size(); i++)
	{
		map[nums[i]].push_back(i);
		int size = map[nums[i]].size()
		degree = max(degree, size);
	}

	for(auto m: map)
	{
		vector<int> temp = m.second;
		if(temp.size() == degree)
			min_dist = min(min_dist, temp[temp.size() - 1] - temp[0] + 1);
	}

	return min_dist;
}


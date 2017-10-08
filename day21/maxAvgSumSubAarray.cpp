#include <iostream>
#include <vector>
#include <deque> 

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
	double max_avg = INT_MIN;
	double sum = 0;

	for(int i =0; i<nums.size(); i++)
	{
		sum += nums[i];
		if(i >=k)
			sum -= nums[i-k];
		if(i>=k-1)
			max_avg = max(max_avg, sum);
	}

	return (double) max_avg/k;
}


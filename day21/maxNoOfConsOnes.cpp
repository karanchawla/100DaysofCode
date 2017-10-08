#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
	int currMax = 0;
	int overallMax = INT_MIN;

	for(auto num: nums)
	{
		if(num==1)
		{
			currMax++;
			overallMax = max(currMax, overallMax);
		}
		else
			currMax = 0;
	}
	return overallMax;
}

int main()
{
	vector<int> nums = {1,1,0,1,0,0,1,1,1,1};
	cout << findMaxConsecutiveOnes(nums);
}
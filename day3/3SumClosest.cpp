#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
	if(nums.size()<3) return 0;

	int closest = nums[0] + nums[1] + nums[2];

	sort(nums.begin(),nums.end());

	for(int first=0; first< nums.size() -2; first++)
	{
		if(first>0 && nums[first]==nums[first-1]) continue;
		int second = first+1;
		int third = nums.size() -1;
		while(second < third)
		{
			int currSum = nums[first] + nums[second] + nums[third];
			if(currSum==target) return currSum;
			if(abs(currSum-target) < abs(target - closest))
			{
				closest = currSum;
			}
			if(currSum > target)
			{
				--third;
			}
			else
				second++;
		}

	}

	return closest;


}
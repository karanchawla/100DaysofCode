#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
	vector<vector<int>> result;

	sort(nums.begin(), nums.end());

	for(int i = 0; i < nums.size() -2; i++)
	{
		if(i > 0 && nums[i-1]==nums[i]) continue;

		int a = nums[i];
		int low = i + 1;
		int high = nums.size() - 1;
		while(low < high)
		{
			int b = nums[low];
			int c = nums[high];
			if(a+b+c == 0)
			{
				vector<int> v;
				v.push_back(a);
				v.push_back(b);
				v.push_back(b);
				result.push_back(v);

				while(low < high && nums[low] == nums[low + 1]) low++;
				while(low < high && nums[high] == nums[high - 1]) high--;
				low++;
				high--;
			}
			else if(a + b + c > 0)
			{
				while(high > 0 && nums[high] == nums[high - 1]) high--;
				high -- ;
			}
			else 
			{
				while(low < nums.size() - 1 && nums[low] == nums[low + 1]) low++;
				low++;
			}
		}	
	}
	
	return result;
}
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// brute force
int findMinRotatedArr(vector<int> &nums)
{
	return *min_element(nums.begin(), nums.end());
}

int findMinRotatedArr01(vector<int> &nums)
{
	int low = 0;
	int high = nums.size() - 1;
	
	while(low < high)
	{
		if(nums[low] < nums[high])
			return nums[low];
		
		int mid = low + (high - low)/2;
		
		if(nums[mid] > nums[high])
			low = mid + 1;
		else 
			high = mid;
	}

	return nums[low];
}

int main()
{
	vector<int> nums = {4 ,5, 6, 7, 0, 1, 2};
	cout << findMinRotatedArr01(nums);
}
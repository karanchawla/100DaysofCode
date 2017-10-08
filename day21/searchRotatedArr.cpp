#include <iostream>
#include <vector> 

using namespace std;

int search(vector<int> &nums, int target)
{
	if(nums.size()==0) return -1;
	int low = 0;
	int high = nums.size() - 1;
	while(low < high)
	{
		int mid = (low) +  (high - low)/2;

		if(nums[mid] == target) return mid;

		if(nums[low] <= nums[mid])
		{
			if(target >= nums[low] && target < nums[mid])
			{
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		else
		{
			if(target > nums[mid] && target <= nums[high])
			{
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
	}

	return nums[low]==target ? low : -1;
}

int main()
{
	vector<int> nums = {1, 3, 5};
	cout << search(nums, 1);
}
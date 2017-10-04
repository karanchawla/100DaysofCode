#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 

using namespace std;

int findDuplicates(std::vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	for(int i = 1; i < nums.size()-1; i++)
	{
		if(nums[i] == nums[i-1])
			return nums[i];
	}
	return -1;
}

int findDuplicatesOptim(std::vector<int> &nums)
{
	int n = nums.size();
	int one = n;
	int two = n;
	do
	{
		one = nums[one-1];
		two = nums[nums[two-1]-1];
	}while(one!=two)

	
}

int main()
{
	std::vector<int> nums = {1,2,3,4,55,6,7,88,9,55};
	cout << findDuplicates(nums);
	return 0;
}
#include <iostream>
#include <vector> 
#include <climits>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums)
{
	// int maxProd = INT_MIN;
	// int currProd = 1;

	// for(int i = 0; i <nums.size() - 3; i++)
	// {
	// 	currProd = nums[i]*nums[i+1]*nums[i+2];
	// 	maxProduct
	// }

	sort(nums.begin(), nums.end());
	int temp1 = (nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
	int temp2 = (nums[0] * nums[1] * nums[2]);
	return temp1 > temp2 ? temp1 : temp2;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	cout << maxProduct(nums);
}
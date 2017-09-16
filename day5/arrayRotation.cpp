#include <iostream>
#include <vector> 
#include <algorithm>

class Solution
{
public:
	std::vector<int> arrayRotation(std::vector<int>& nums, int d)
	{
		for(int i=0; i<d; ++i)
		{
			nums.push_back(nums[i]);
		}

		nums.erase(nums.begin(), nums.begin() + d);

		for(int i = 0; i!=nums.size(); ++i)
		{
			std::cout << nums[i] << " ";
		}

		return nums;
	}

	std::vector<int> arrayRotationWithReversalAlgorithm(std::vector<int> nums, int d)
	{
		reverseVec(nums, 0, d-1);
		reverseVec(nums, d, nums.size() - 1);
		reverseVec(nums, 0, nums.size() - 1);
	
		for(int i = 0; i!=nums.size(); ++i)
		{
			std::cout << nums[i] << " ";
		}

		return nums;
	}

	void reverseVec(std::vector<int>& vec, int start, int end)
	{
		int temp;
		while(start < end)
		{
			temp = vec[start];
			vec[start] = vec[end];
			vec[end] = temp;
			start++;
			end--;
		}
	}
	
};

int main()
{
	std::vector<int> nums;
	for (int i=1; i<=10; i++) nums.push_back(i);

	int d = 2;
	Solution sol;
	sol.arrayRotationWithReversalAlgorithm(nums,d);

	return 0;
}
#include <vector>
#include <iostream>

using namespace std; 

int LIS(vector<int> &nums, int i, int previous)
{
	int n = nums.size();

	if(i==n)
		return 0;

	int excl = LIS(nums, i+1, previous);

	int incl = 0;
	if(nums[i] > previous)
		incl = LIS(nums, i+1, nums[i]) + 1;

	return max(incl, excl);
}

// Memoization because overlapping sub problems
int LISMemoized(vector<int> &nums)
{
	int n = nums.size();

	vector<int> L(n, 0);
	L[0] = 1;

	for(int i = 1; i < nums.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(nums[i] > nums[j] && L[j] > L[i])
				L[i] = L[j];
		}

		L[i]++;
	}

	int lis = INT_MIN;
	for(int x: L)
	{
		lis = max(lis, x);
	}

	return lis;
}

void findLIS(vector<int> nums)
{
	int n = nums.size();

	vector<vector<int>> L(n);
	L[0].push_back(nums[0]);

	for(int i = 1; i < nums.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(nums[i] > nums[j] && L[i].size() < L[j].size())
				L[i] = L[j];
		}
		L[i].push_back(nums[i]);
	}

	int j = 0; 
	for(int i = 0; i < nums.size(); i++)
	{
		if(L[i].size() > L[j].size())
			j = i;
	}

	for(auto i: L[j])
		cout << i << " ";

}

int main()
{
	vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1};

	findLIS(nums);

	return(0);
}
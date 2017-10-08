#include <iostream>
#include <vector> 

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
	int len = nums.size();
	for(int i = 0; i < len; i++)
	{
		int m = abs(nums[i]) - 1 ;
		cout << m << endl;
		nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
	}

	vector<int> result;
	for(int i = 0; i < len; i++)
	{
		if(nums[i] > 0) result.push_back(i+1);
	}

	return result;
}

int main()
{
	vector<int> nums = {4,3,2,7,8,2,3,1};
	std::vector<int> res = findDisappearedNumbers(nums);

	for(auto num: res) cout << num;
}
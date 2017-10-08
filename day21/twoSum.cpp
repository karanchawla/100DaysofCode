#include <iostream>
#include <unordered_map>
#include <vector> 

using namespace std; 

vector<int> twoSum(vector<int> &nums, int target)
{
	unordered_map<int, int> hash;
	vector<int> result; 

	for(int i = 0; i < nums.size(); i++)
	{
		int numberToFind = target - nums[i];
		if(hash.find(numberToFind)!= hash.end())
		{
			// return these values 
			result.push_back(hash[numberToFind]);
			result.push_back(i);
			return result;
		}
		//else add the number to the map
		hash[nums[i]] = i;
	}
	return result;
}

int main()
{
	vector<int> nums = {2,7,11,15};
	vector<int> result = twoSum(nums,9);
	for(auto res: result) cout << res;
}
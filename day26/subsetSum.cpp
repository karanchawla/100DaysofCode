#include <iostream>
#include <vector> 
#include <map>

using namespace std;

bool doesSumExist(const vector<int> &nums, int target)
{
	unordered_map<int, int> hashmap;
	vector<int> result; 
	for(int i = 0; i < nums.size(); i++)
	{
		if(hashmap.find(nums[i])==nums.end())
		{
			hashmap[target - nums[i]] = i;
		}
		else
		{
			result.push_back(m[nums[i]] + 1);
			result.push_back(i + 1);
		}
	}

	
}

int main()
{
	int arr[] = {1, 3, 4, 5};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	int target = 9;

	cout << doesSumExist(nums, target);

}

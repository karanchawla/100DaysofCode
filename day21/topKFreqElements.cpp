#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <map> 

using namespace std; 

vector<int> topKFrequent(vector<int> &nums, int k)
{
	vector<int> result;
	map<int, int> count;
	for(int i = 0; i <nums.size(); i++)
	{
		count[nums[i]]++;
	} 

	int j = 0;
	for(auto i = count.begin(); i != count.end(); i++)
	{
		if(j<k && find(result.begin(), result.end(), i->second)==result.end)
			result.push_back(i->first);
		j++;	
		// cout << i->first << " " << i->second << " ";
		// cout << endl;
	}

	return result;
}

int main()
{
	vector<int> nums = {4,1,-1,2,-1,2,3};
	vector<int> ans = topKFrequent(nums, 2);
	for(auto num: ans) cout << num;
	return(0);
}
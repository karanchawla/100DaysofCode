#include <vector> 
#include <iostream> 

using namespace std; 

void coutingSort(vector<int> &nums, int k)
{
	vector<int> frequency(k,0);
	for(auto i: nums) 
		frequency[i]++;

	int i = 0;
	for(auto it: frequency)
		while(it.second--)
			nums[i++] = it.first;
}
#include <iostream>
#include <vector> 
#include <set>

using namespace std; 

int thirdMax(vector<int> &nums)
{
	set<int> top3;
	for(int num: nums)
	{
		top3.insert(num);
		if(top3.size() > 3)
		{
			top3.erase(top3.begin());
		}
	}

	return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

int main()
{
	vector<int> nums = {2,2,3,1};
	cout << thirdMax(nums);
	return(0);
}
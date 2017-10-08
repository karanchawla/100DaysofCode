#include <iostream>
#include <vector> 
#include <set> 

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
	multiset<int> mset;
    int n = nums.size();
    for (int i = 0; i < n; i++) { 
        mset.insert(nums[i]);
        if (mset.size() > k)
            mset.erase(mset.begin());
    }
    return *mset.begin();
} 

int main()
{
	vector<int> nums = {-2, -2};
	cout << findKthLargest(nums, 2);
	return(0);
}
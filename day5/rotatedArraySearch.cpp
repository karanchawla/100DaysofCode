#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

	int search(std::vector<int> nums, int l, int h, int key)
	{
		if(nums.size()==0) return -1;

		int mid = (l + h)/2;
		if(nums[mid] == key) return mid;

		if(nums[l] <= nums[mid])
		{
			if(key >= nums[l] && key < nums[mid])
			{
				return search(nums, l, mid-1, key);
			}

			return search(nums, mid+1, h, key);
		}

		if (key >= nums[mid] && key <= nums[h])
    	    return search(nums, mid+1, h, key);
 
	    return search(nums, l, mid-1, key);
	}
};

// Driver program
int main()
{
    std::vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    int key = 6;
    Solution sol;

    int i = sol.search(v, 0, v.size()-1, key);
    
    if (i != -1) std::cout << "Index: " << i << std::endl;
    else std::cout << "Key not foundn";
}
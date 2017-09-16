#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        sort(nums.begin(), nums.end());
        while(true)
        {
            std::vector<int>::iterator it = find(nums.begin(),nums.end(),val);
            if(it!= nums.end())
                nums.erase(it);
            else
                break;
        }
        return nums.size();

    }
};

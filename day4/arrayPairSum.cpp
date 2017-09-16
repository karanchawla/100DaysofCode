#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0; i<nums.size(); sum +=nums[i], i+=2){}

        return sum;
    }
};

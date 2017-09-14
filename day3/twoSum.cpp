#include <iostream>
#include <vector> 

// Inputed array is sorted


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        int low = 0;
        int high = size -1;
        std::vector<int> result;
        while(low < high)
        {
            int curr = nums[low] + nums[high];
            std::cout << curr;
            if(curr > target)
            {
                high--;
            }
            else if(curr < target)
            {
                low++;
            }
            else if(curr == target)
            {
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }
        }
    }
};
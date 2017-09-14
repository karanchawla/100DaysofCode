#include <iostream>
#include <vector> 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int index = 0;
        int count = 1;
        
        for(int i = 1; i<nums.size(); ++i)
        {
            if(nums[index] == nums[i])
            {
                count ++;
            }
            else
                count --;
            
            if(count==0)
            {
                index = i;
                count = 1;
            }
        }
            
        return nums[index];
    }
    
};
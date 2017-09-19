'''
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.


'''

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        n = len(nums)
        dp = []
        
        if(n >=1): dp.append(nums[0]) 
        if(n >=2): dp.append(max(nums[0], nums[1]))
            
        for i in range(2,len(nums)):
            dp.append(max(dp[i-1], dp[i-2] + nums[i]))
            
        return dp[n-1]
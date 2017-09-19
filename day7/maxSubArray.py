'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

'''

class Solution(object):
    def maxSubArray(self, A):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not A:
            return 0
        
        currSum = maxSum = A[0]
        
        for num in A[1:]:
            currSum = max(num, currSum+num)
            maxSum = max(maxSum, currSum)
            
        return maxSum
        
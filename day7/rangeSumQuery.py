'''
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
1. You may assume that the array does not change.
2. There are many calls to sumRange function.

'''
class NumArray(object):
	def __init__(self, nums):
		self.accu = [0]

		for num in nums:
			self.accu += self.accu[-1] + num


	def sumRange(self, i, j):
		return self.accu[j+1] - self.accu[i]





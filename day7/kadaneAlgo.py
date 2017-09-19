'''

Kadane's Agorithm to calculate the maximum contiguous array sum.

'''

def maxSubArray(nums):
	max_so_far = max_ending_here = 0
	start = end = 0

	for i in range(len(nums)):
		max_ending_here += nums[i]

		if(max_ending_here < 0):
			max_ending_here = 0
			s = i+1 

		elif(max_so_far < max_ending_here):
			max_so_far = max_ending_here
			end = i
			start = s

		

	return (max_so_far,start,end)


a = [-2, -3, 4, -1, -2, 1, 5, -3]
max_sum = maxSubArray(a)
print(max_sum)
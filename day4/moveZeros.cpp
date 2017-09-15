#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

	void moveZerosSubOptimal(std::vector<int>& nums)
	{
		int numZeros = 0;
		for (auto i = nums.begin(); i != nums.end(); ++i)
		{
			if(*i==0)
			{
				numZeros++;
			}
		}

		std::vector<int> result;
		for(auto i = nums.begin(); i!=nums.end(); ++i)
		{
			if(*i!=0)
				result.push_back(*i);
		}

		while(numZeros--)
		{
			result.push_back(0);
		}

		for(int i = 0; i!= nums.size(); ++i)
		{
			nums[i] = result[i];
		}

	}

	void moveZerosSpaceOptimal(std::vector<int>& nums)
	{
		int lastZeroFoundAt = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if(nums[i]!= 0)
			{
				nums[lastZeroFoundAt++] = nums[i];
			}
		}

		for (int i = lastZeroFoundAt; i < nums.size(); ++i)
		{
			nums[i] = 0;
		}
	}


	void moveZerosOptimal(std::vector<int>& nums)
	{
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) 
		{
        	if (nums[cur] != 0) 
        	{
            	swap(nums[lastNonZeroFoundAt++], nums[cur]);
        	}
    	}
	}

};
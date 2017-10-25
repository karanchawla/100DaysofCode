#include <vector> 
#include <map> 
#include <climits>
#include <stack>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <unordered_set> 
#include <unordered_map>
#include <set>
#include <algorithm>


using namespace std; 

// Find pair with given sum in the array 
void findPair(vector<int> nums, int sum)
{
	unordered_map<int, int> hash;

	for(int i = 0; i < nums.size(); i++)
	{
		if(hash.find(sum - nums[i])!= hash.end())
			cout << "The pair with given sum: " << hash[sum-nums[i]] << i << endl;
		else
			hash[nums[i]] = i;
	}
}

// Check if subarray with 0 sum exists
bool checkZeroSum(vector<int> nums)
{
	unordered_set<int> set; 
	set.insert(0);

	int sum = 0;

	for(int i = 0; i < nums.size(); i++)
	{
		sum +=nums[i];

		if(set.find(sum)!=set.end())
			return true;
		else 
			set.insert(sum);
	}

	return false;
}

// Print all subarrays with zero sum 
void printZeroSumSubArrays(vector<int> &nums)
{
	unordered_multimap<int, int> map;

	int sum = 0;
	map.insert({0,-1});

	for(int i = 0; i < nums.size(); i++)
	{
		sum+=nums[i];

		if(map.find(sum)!= map.end())
		{
			auto it = map.find(sum);
			while(it != map.end() && it->first == sum)
			{
				cout << it->second + 1 << i;
				it++;
			}
		}
		else
			map.insert({sum, i});
	}
}

// Sort binary array in linear time
vector<int> sortBinaryArray(vector<int> &nums)
{
	int k = 0;

	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i]==0)
			nums[k++] = 0;
	}

	while( k < nums.size())
		nums[k++] = 1;

	return nums;
}

// Find duplicate element in a limited range arr
int findDuplicate(vector<int> &nums)
{
	int k = nums[0];
	for(int i = 1; i < nums.size(); i++)
	{
		k = k^nums[i];
	}

	for(int i = 1; i < nums.size(); i++)
		k = k^i;

	return k;
}

// Largest subarray with consecutive ints 
bool isConsecutive(vector<int> &nums, int min, int max, int i, int j)
{
	//check if size of the array is equal to the diff
	//between max and min
	if(max - min != j - i)
		return false;

	//check if array contains unique elements
	set<int> s;
	for(int k = i; k < j+1; k++)
	{
		if(s.find(nums[k])==s.end())
			s.insert(nums[k]);
		else
			return false;	
	}

	return true;
}

void findMaxSubarray(vector<int> &nums)
{
	int n = nums.size();

	int len = 1;
	int start = 0; int end = 0;

	for(int i = 0; i < n - 1; i++)
	{
		int min_val = nums[i]; 
		int max_value = nums[i];

		for(int j = i +1; j < n; j++)
		{
			min_val = min(min_val, nums[j]);
			max_value = max(max_value, nums[j]);

			if(isConsecutive(nums, min_val, max_value, i, j))
			{
				if(len < max_value - min_val+1)
				{
					len = max_value- min_val + 1;
					start = i; end = j;
				}
			}
		}
	}

	cout << "The largest subarr is between " << start << " and " << end;
}

// Find maximum length subarray having given sum ***
void maxSubArray(vector<int> &nums, int S)
{
	unordered_map<int, int> map;

	map[0] = -1;

	int len = 0;
	int ending_index = -1;
	int sum = 0;

	for(int i = 0; i< nums.size(); i++)
	{
		sum +=nums[i];

		if(map.find(sum) == map.end())
			map[i] = sum;

		if(map.find(sum-S)!=map.end() && len < i - map[sum-S])
		{	
			len = i - map[sum-S];
			ending_index = i;
		}
	}

	cout << ending_index - len + 1 << ending_index;
}

// Dutch flag problem
void ductFlagSort(vector<int> &nums)
{
	int start = 0; 
	int mid = 0;
	int end = nums.size() - 1;
	while(mid <= end)
	{
		if(nums[mid]==0)
		{
			swap(nums[start], nums[mid]);
			start++;
			mid++;
		}
		else if(nums[mid]==1)
			mid++;
		else 
		{
			swap(nums[end], nums[mid]);
			end--;
		}
	}
}

// Inplace merge sort two sorted arrays 
// Size of nums1 > nums2
void InplaceMerge(vector<int> &nums1, vector<int> &nums2)
{
	int i = 0; 
	while(i < nums1.size())
	{
		if(nums1[i] > nums2[0])
		{
			swap(nums1[i], nums2[0]);
			
			int first = nums2[0]; // ***
			int k; 
			for( k = 1; k < nums2.size() && nums2[k] < first; k++)
				nums2[k-1] = nums2[k];

			nums2[k - 1] = first;
		}
		i++;
	}
}

// Merge two arrays given that first array has extra space for accomodating the second arr
// Has zeros for extra elements 
void rearrange(vector<int> &x, vector<int> &y) // ***
{
	int m = x.size();
	int n = y.size();

	int k = 0; 

	for(int i = 0; i < m; i++)
	{
		if(x[i]!=0)
			x[k++] = x[i];
	}

	while(k < m)
		x[k++] = 0;
}

void merge(vector<int> &x, vector<int> &y)
{
	int m = x.size();
	int n = y.size();

	int k = m + n;
	while(m>=0 && n>=0)
	{
		if(x[m] > y[n])
			x[k--] = x[m--];
		else 
			x[k--] = y[n--];
	}

	while(n>=0)
		x[k--] = y[n--];
}

// Find 0 to replace to get max consecutive ones 
int findZeroIndex(vector<int> &nums)
{
	int left = 0;
	int count = 0;

	int max_index = -1; 
	int max_count = 0;
	int prev_zero_index; 

	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i]==0)
		{
			count++;
			prev_zero_index = i;
		}

		if(count == 2)
		{
			while(nums[i])
				left++;

			// Remove zero element
			left++;

			count = 1;
		}

		if(i - left + 1 > max_count)
		{
			max_count = i - left + 1; 
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

// Find maximum product of two integers in an array 
int maxProduct(vector<int> &nums)
{
	std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(), std::greater<int>());

    int Max = nums[0];
	int SecMax = nums[1];

	std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());

	int Min = nums[0];
	int SecMin = nums[1];

	return max(Max*SecMax, Min*SecMin);
}

// Boyer Moore Algorithm 
int maxFreqElement(vector<int> &nums)
{
	int count = 1;
	int max_freq_element = nums[0];

	for(int i = 1; i < nums.size(); i++)
	{
		if(count==0)
			max_freq_element = nums[i];

		if(max_freq_element == nums[i])
			count++;
		else
			count--;
	}

	return max_freq_element;
}

// Move all zeros present in the array to the end 
void moveZeros(vector<int> &nums)
{
	int k = 0; 
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i])
			nums[k++] = nums[i];
	}

	while(k < nums.size())
		nums[k++] = 0;	
}

// Replace each element of the array with the product of the rest of the elements
// without using the / operator 
void replaceWithProduct(vector<int> &nums)
{
	vector<int> left;
	vector<int> right; 

	left[0] = 1;
	// left array stores the product from 0 to i-1
	for(int i = 0; i < nums.size(); i++)
	{
		left[i] = left[i-1]*nums[i-1];
	}
	right[nums.size() - 1];
	// right stores the product from i+1 to n -1
	for(int i = nums.size() - 2; i >=0; i--)
		right[i] = nums[i+1]*right[i+1];

	for(int i = 0; i < nums.size(); i++)
	{
		nums[i] = left[i]*right[i];
	}
}

// Kadane's algorithm for the maximum sum subarray
int kadane(vector<int> &nums)
{
	int max_sum;
	int max_so_far = nums[0]; 
	for(int i = 1; i < nums.size(); i++)
	{
		max_so_far += nums[i];

		max_so_far = max(max_so_far, nums[i]);

		max_sum = max(max_sum, max_so_far);
	}

	return max_sum;
}

void printVec(const vector<int> &nums)
{
	for(auto i : nums)
		cout << i;

	return;
}

int main()
{
	vector<int> nums = {2,1,-4,1,-4, -4, -4};
	// int sum = 0;
	// findPair(nums, sum);

	// if(checkZeroSum(nums))
	// 	cout << "True";
	// else cout << "False";

	// printZeroSumSubArrays(nums);

	// vector<int> binarr = {0,1,1,0,0,1,0,0,1};

	// binarr = sortBinaryArray(binarr);

	// for(auto i : binarr)
	// 	cout << i;

	// vector<int> limRangeArr = {1,2,3,4,2};

	// cout << findDuplicate(limRangeArr);

	// std::vector<int> v = {2,0,2,1,4,3,1,0};
	// findMaxSubarray(limRangeArr);

	// std::vector<int> dutcharr = {0,1,2,2,2,0,0,1};
	// ductFlagSort(dutcharr);

	// for(auto i : dutcharr)
	// {
	// 	cout << i;
	// }

	cout << maxFreqElement(nums);



	return (0);
}
#include <iostream>
#include <vector> 
#include <algorithm>
#include <stdio.h>

using namespace std;

//Binary Search

int binarySearch(std::vector<int> nums, int l, int r, int key)
{
	if(r >= l)
	{
		int mid = l + (r - l)/2;

		if(nums[mid] == key) return mid;

		else if(nums[mid] > key) return binarySearch(nums, l, mid-1, key);

		return binarySearch(nums, mid+1, r, key);
	}

	return -1;
}

//Jump Search
int jumpySearch(std::vector<int> nums, int m, int key)
{
	if(nums.size() == 0) return -1;

	int left = 0;
	int right = 0;

	for(int i = 0; i< nums.size(); i+=m)
	{
		if(nums[i] > key && i!=0)
			{
				right = i;
				left = i-m;
			}
	}

	while(left<right)
	{
		if(nums[left] == key)
			return left;
		left++;
	}

	return -1;
}


int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   std::vector<int> nums(arr , arr + sizeof(arr)/sizeof(int) );
   int n = nums.size();
   int x = 10;
   int result = binarySearch(nums, 0, n-1, x);
   int result_js = jumpySearch(nums, 2, x);
   (result_js == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result_js);
   return 0;

}
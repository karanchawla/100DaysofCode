#include <iostream>
#include <vector> 

using namespace std;

void reverse(vector<int> &nums, int start, int end);

void rotate(vector<int> &nums, int k)
{	
	k %= nums.size();
	reverse(nums, 0, nums.size() - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, nums.size() - 1);
}

void reverse(vector<int> &nums, int start, int end)
{
	while(start < end)
	{
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}

void printVector(vector<int> &nums)
{
	for(auto &i : nums)
	{
		cout << " " << i;
	}
}

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7};
	int k = 3; 
	rotate(v, k);
	printVector(v);

	return(0);
}
#include <iostream>
#include <vector> 
#include <utility>

using namespace std;

int binarySearch(const vector<int>& nums, int searchElement)
{
	int searchIndex = -1;
	int low = 0;
	int high = nums.size() - 1;

	while(low <= high)
	{
		int mid = low + (high - low)/2;

		if(nums[mid] == searchElement)
		{
			searchIndex = mid;
			break;
		}
		
		if(nums[mid] < searchElement)
			low = mid;
		else
			high = mid - 1;	
	}

	if(searchIndex == -1)
		throw runtime_error("element not found");
	else
		return searchIndex;
}

pair<int, int> firstAndLastOccurence(const vector<int> &nums, int searchElement)
{
	pair<int, int> startAndEndIndex;
	startAndEndIndex.first = binarySearch(nums, searchElement);
	int endIndex = startAndEndIndex.first; 
	for(int i = startAndEndIndex.first; i <nums.size(); i++)
	{
		if(nums[i]==nums[i+1] && i + 1 < nums.size())
			endIndex++;
		else
			break;
	}

	startAndEndIndex.second = endIndex;

	return startAndEndIndex;
}



int main()
{
	vector<int> nums = {0, 0, 0, 1, 2, 3, 4, 4, 8, 8, 8, 8};

	pair<int, int> result = firstAndLastOccurence(nums, 8);

	cout << result.first << " " << result.second;

}
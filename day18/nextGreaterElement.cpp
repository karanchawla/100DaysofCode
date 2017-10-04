// Find the next greater element in an array
// If none exists return -1 

#include <iostream>
#include <stack> 
#include <vector> 
#include <unordered_map>

using namespace std;

// Method 1: brute force - use two for loops and check for the next greater element - if found return this else return -1 

void printNextGreaterElement(vector<int> arr)
{
	int next, i, j;

	for(int i = 0; i < arr.size(); i++)
	{
		next = -1;
		for (int j = 1; j < arr.size(); j++)
		{
			if(arr[j] > arr[i])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << "  -----  " << next << endl; 
	}
}

// Method 2: using stack and unordered map
void printNextGreaterElementOptimized(vector<int> &nums)
{
	stack<int> s; 
	unordered_map<int,int> m;

	for(int n: nums)
	{
		while(s.size() && s.top() < n)
		{
			m[s.top()] = n;
			s.pop();
			// cout << "I'm in while" << endl;
		}

		s.push(n);
	}
	for(int n: nums)
	{
		int ans = m.count(n) ? m[n] : -1;
		cout << n << "  ----  " << ans << endl;
	}
}


int main()
{
    vector<int> nums= {11, 13, 21, 3};
    printNextGreaterElementOptimized(nums);
    return 0;
}
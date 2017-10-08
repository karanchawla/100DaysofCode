#include <iostream> 
#include <vector> 
#include <deque>
#include <set>

using namespace std;

// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k 

// O(n logk)

vector<int> maxSlidingWindow02(vector<int>& nums, int k)
{
	vector<int> result; 

	multiset<int> w;

	for(int i = 0; i<nums.size(); ++i)
	{
		// remove the left item which leaves the window
		if(i>=k)
		{
			w.erase(w.find(nums[i-k]));
		}

		// insert the right item which enters the window
		w.insert(nums[i]);
		
		if(i >= k-1)
		{
			result.push_back(*w.rbegin());
		}
	}

	return result;
}


void printDeque(deque<int> &q, std::vector<int> &nums)
{
	for(auto i = q.begin(); i!= q.end(); ++i)
	{
		cout << nums[*i];
	}
	cout << endl;
}


//O(n)

vector<int> maxSlidingWindow01(vector<int> &nums,  int k)
{
	vector<int> result; 

	deque<int> q; 

	for(int i=0; i < nums.size(); ++i)
	{
		// remove the left item which leaves the queue 
		if(!q.empty() && q.front() == i-k)
		{
			q.pop_front();
		}

		// remove all num which less than current number from the back one by one 

		while(!q.empty() && nums[q.back()] < nums[i])
		{
			q.pop_back();
		}

		// insert the right item which enter the window 
		q.push_back(i);
		if(i>=k-1)
		{
			result.push_back(nums[q.front()]);
		}

		printDeque(q, nums);
	}

	return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return maxSlidingWindow01(nums, k);
    return maxSlidingWindow02(nums, k);
}

void printVector( vector<int>& v ) {
    cout << "{ ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size() ? " ": ", ");
    }
    cout << "}" << endl;
}

int main(int argc, char** argv) 
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    // printVector(nums);
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);
}
#include <iostream>
#include <vector> 
#include <climits> 

using namespace std;

int maxProfit(vector<int>& prices) 
{
    const size_t n = prices.size();
    int ans = 0;
    for (size_t i=1;i<n;i++)
        ans += max(0,prices[i]-prices[i-1]);
    return ans;
}

int main()
{
	vector<int> nums = {7, 1, 5, 3, 6, 4};
	cout << maxProfit(nums);

	return(0);
}

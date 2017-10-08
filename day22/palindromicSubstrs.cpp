#include <iostream>
#include <vector> 

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
	int len = nums.size();
	vector<int> result(len, 1);

	for(int i = 1; i < len; i++)
	{
		result[i] = result[i-1] * nums[i-1];
	}

	for(auto num: result) cout << num;

	cout << endl;

	int r_prod = 1;
	for(int i = len - 1; i >=0; i--)
	{
		result[i] *= r_prod;
		r_prod *= nums[i];
	}

	return result;
}


int main()
{
	std::vector<int> v = {1,2,3,4};
	productExceptSelf(v);

	return(0);
}
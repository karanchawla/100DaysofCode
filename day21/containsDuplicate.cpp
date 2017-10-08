#include <iostream> 
#include <vector> 
#include <map>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{   
    map<int, int> m;
    for(int i = 0; i <nums.size(); i++) 
    {
        if(m[nums[i]] >=1)
            return true;
        else 
            m[nums[i]]++;
            
    }
    
    return false;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 7};
	cout << containsDuplicate(nums);
}
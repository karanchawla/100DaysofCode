#include <iostream>
#include <climits> 
#include <cmath> 

using namespace std; 

int mySqrt(int x)
{
	if (x == 0) return 0;

    int left = 1, right = x;

    while (true) 
    {
        int mid = left + (right - left)/2;
        
        if (mid > x/mid) 
        {
            right = mid - 1;
        } 
        else 
        {
            if (mid + 1 > x/(mid + 1))
                return mid;
            
            left = mid + 1;
        }
    }
}

int main()
{
	cout << mySqrt(5);
	return 0;
}
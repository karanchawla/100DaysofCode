#include <string> 
#include <iostream> 
#include <algorithm>

using namespace std; 

bool expand(string str, int low, int high, int k)
{
	while(low >=0 && high < str.length() && str[low]==str[high])
	{
		if(high-low+1 == k)
			return true;

		low--; high++;
	}

	return false;
}

bool LongestPalindromicSubString(string str, int k)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(expand(str, i, i, k) || expand(str, i, i+1, k))
			return true;
	}

	return false;
}


bool isRotatedPalindrome(string str)
{
	int m = str.length();

	return LongestPalindromicSubString(str+str, m);
}

int main()
{
	string str = "ABCDCBA";

	rotate(str.begin(), str.begin() + 2, str.end());

	cout << isRotatedPalindrome(str);
}
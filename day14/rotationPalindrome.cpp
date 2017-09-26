//Check if a given string is a rotation of a palindrome

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkCharCount(std::vector<int> &count, string &s)
{
	int odd = 0;

	if(s.size()%2==0)
	{
		for(int i = 0; i < s.size(); ++i)
		{
			if(count[i]%2 !=0) return false;	
		}
	}
	else 
	{
		for(int i = 0; i < 256; ++i)
		{
			if(count[i]>0 && count[i]==1) odd++;
			if(odd > 1) return false;
		}
	}

	return true;
}

bool isRotationPalindrome(string s)
{
	if(s.size()==0) return true;

	std::vector<int> count(256,0);

	for(int i = 0; i < s.size(); ++i) count[s[i]]++;

	return checkCharCount(count, s);

}webm
int main()
{
    cout << isRotationPalindrome("aab") << endl;
    cout << isRotationPalindrome("abcde") << endl;
    cout << isRotationPalindrome("aaaad") << endl;

   return 0;	
}
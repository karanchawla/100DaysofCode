// Check whether two strings are anagram of each other

#include <iostream>
#include <string>
#include <vector>

# define NO_OF_CHARS 256

using namespace std;

bool ifAnagram(string s1, string s2)
{
	if(s1.size()!=s2.size()) return false;

	vector<int> count1(NO_OF_CHARS,0) , count2(NO_OF_CHARS,0);
	for(auto c: s1) count1[c]++;
	for(auto c: s2) count2[c]++; 

	for(int i =0 ;i < NO_OF_CHARS; ++i)
	{
		if(abs(count1[i] - count2[i])!=0)
			return false;
	}

	return true;
}

int main()
{
    string str1("geeksforgeeks");
    string str2("forgeeksgeeks");
    if (ifAnagram(str1, str2) )
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");
 
    return 0;
}
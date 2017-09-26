// Given two strings in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string. 
// Find minimum number of characters to be deleted to make both the strings anagram?

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define CHARS 26 

int remAnagram(string s, string t)
{
	vector<int> count1(CHARS,0), count2(CHARS,0);

	for(int i =0; i < s.size(); ++i) count1[s[i]-'a']++;
	for(int i =0; i < t.size(); ++i) count2[t[i]-'a']++;

	int result = 0;
	for(int i = 0; i < CHARS; ++i)
	{
		result += abs(count1[i] - count2[i]);
	}

	return result;
} 
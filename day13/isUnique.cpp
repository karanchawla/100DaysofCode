#include <iostream>
#include <string>
#include <algorithm> 
#include <vector> 

using namespace std;

bool isUnqiue(const string &str)
{
	if(str.length()>128)
	{
		return false;
	}

	vector<bool> char_set(128);
	for(int i=0; i<str.length(); ++i)
	{
		int val = str[i];
		if(char_set[val])
		{
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

bool isUnqiue_noDS(const string& str)
{
	for(int i = 0; i<str.length()-1; i++)
	{
		for(int j = i+1; j<str.length(); ++i)
		{
			if(str[i]==str[j])
			{
				return false;
			}
		}
	}
}

int main()
{
	vector<string> words = {"abcde", "hello", "apple"};
	for(auto word : words)
	{
		cout << word << string(": ") << boolalpha << isUnqiue(word) <<endl;
	} 
}
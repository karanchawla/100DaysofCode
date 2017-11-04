#include <iostream>
#include <string> 
#include <utility> 
#include <algorithm>
#include <set>

using namespace std; 

pair<int, int> expand(string str, int low, int high)
{
	while(low >=0 && high< str.length() && str[low]==str[high])
		low--, high++;

	return make_pair(low, high);
}

set<string> allPalindromicSubStrings(string str)
{
	set<string> result; 
	string curr_string;

	for(int i = 0; i < str.length(); i++)
	{
		pair<int,int> lowHighPair = expand(str, i, i);
		curr_string = str.substr(lowHighPair.first+1, lowHighPair.second - lowHighPair.first - 1);
		result.insert(curr_string);

		lowHighPair = expand(str, i, i+1);
		curr_string = str.substr(lowHighPair.first+1, lowHighPair.second - lowHighPair.first - 1);
		result.insert(curr_string);
	}

	return result;
}

int main()
{

	string str = "google";

	set<string> result = allPalindromicSubStrings(str);

	for(auto i: result)
	{
		cout << i << endl;
	}
}
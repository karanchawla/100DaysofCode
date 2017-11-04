#include <string> 
#include <algorithm> 
#include <utility> 
#include <iostream>

using namespace std; 

pair<int, int> expand(string &str, int low, int high)
{
	while(low>=0 && high < str.length() && str[low]==str[high])
		low--, high++;

	pair<int, int> result = make_pair(low, high);

	return result; 
}

string longestPalindromicSubString(string &str)
{
	string max_palindrome = "";
	int max_length = 0;

	string curr_string;
	int curr_length = INT_MIN;

	for(int i = 0; i < str.length(); i++)
	{
		pair<int, int> result = expand(str, i, i);
		curr_string = str.substr(result.first + 1, result.second - result.first - 1);
		curr_length = curr_string.length();

		if(curr_length > max_length)
		{
			max_palindrome = curr_string;
			max_length = curr_length;
		}

		result = expand(str, i, i+1);
		curr_string = str.substr(result.first + 1, result.second - result.first - 1);
		curr_length = curr_string.length();

		if(curr_length > max_length)
		{
			max_palindrome = curr_string;
			max_length = curr_length;
		}

	}

	return max_palindrome;
}

int main()
{

	string str = "abdcdbcdbdcbbc";

	cout << longestPalindromicSubString(str);

	

}
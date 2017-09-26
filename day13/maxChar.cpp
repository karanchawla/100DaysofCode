// Write an efficient C function to return maximum occurring character in the input string e.g., if input string is “test” then function should return ‘t’.

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

#define ASCII_SIZE 256

using namespace std;

char getMaxOccuringChar(string &str)
{
	vector<int> count(ASCII_SIZE, 0);

	size_t len = str.length();

	for(size_t i=0; i<len; ++i)
	{
		int val = str[i];
		count[val]++;
	}

	auto maximumElement = distance(count.begin(), max_element(count.begin(), count.end()));
	return char(maximumElement);
}

int main()
{
    string str("sample stringssss");
    cout << "Max occurring character is "
         << getMaxOccuringChar(str);
}
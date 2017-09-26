#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ASCII_NUMS 256

char secondMostFreqChar(string &str)
{
	vector<int> count(ASCII_NUMS, 0);

	size_t len = str.length();

	for(size_t i=0; i<len; ++i)
	{
		int val = str[i];
		count[val]++;
	}

	int first = 0, second = 0;

	for(int i=0; i< ASCII_NUMS; i++)
	{
		if(count[i] > count[first])
		{
			second = first;
			first = i;
		}
		else if (count[i] > count[second] && count[i]!=count[first])
			second = i;
	}

	return second; 
}

int main()
{
    string str("geeksforgeeks");
    cout << "Second most occurring character is "
         << secondMostFreqChar(str);
}
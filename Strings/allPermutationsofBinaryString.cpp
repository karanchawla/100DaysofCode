// Find all combinations of binary strings that can be formed by replacing the wildcard pattern in the given string 

#include <string> 
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std; 

void printAllCombinations(string pattern)
{
	stack<string> list; 
	list.push(pattern);

	while(!list.empty())
	{
		string curr = list.top();
		list.pop();

		size_t index;

		if((index = curr.find_first_of('?')) != string::npos )
		{
			for(size_t i = 0; i < 2; i++)
			{
				curr[index] = i + '0';
				list.push(curr);
			}
		}
		else
			cout << curr << endl;
	}
}

int main()
{
	string str = "1?001?01?0";

	printAllCombinations(str);
}
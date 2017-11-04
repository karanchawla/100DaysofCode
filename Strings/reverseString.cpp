#include <string> 
#include <iostream>
#include <stack>

using namespace std; 

bool isPalindrome(string const& str)
{
	int low = 0; 
	int high = str.length() - 1;

	while(low < high)
	{
		if(str[low]!=str[high])
			return false; 
	low++;
	high--;
	}

	return true;
}

//Reverse a string using recursion 
void reverseString(string &str, int k)
{
	static int i = 0;

	if(k==str.length())
		return;

	reverseString(str, k+1);

	if(i<=k)
		swap(str[i++], str[k]);
}

void reverseStringWithoutRecursion(string & str)
{
	stack<int> stk;
	for(int i = 0; i < str.length(); i++)
	{
		stk.push(str[i]);
	}

	int k = 0; 

	while(!stk.empty())
	{
		str[k++] = stk.top();
		stk.pop();
	}
}

void inPlaceReverse(string &str)
{
	int start = 0; 
	int end = str.length() - 1; 

	while(start < end)
	{
		swap(str[start++], str[end--]);
	}
}

int main()
{
	string str = "abdba";

	string a = "fearisthemindkiller";

	reverseStringWithoutRecursion(a);

	inPlaceReverse(a);

	cout << a;

	cout << isPalindrome(str);
}
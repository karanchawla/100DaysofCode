#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool arePermutation(string str1, string str2)
{
	int n1 = str1.length();
	int n2 = str2.length();

	if(n1!=n2)
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	for(int i =0; i<n1; ++i)
	{
		if(str1[i]!=str2[i])
			return false;
	}

	return true;
}


bool arePermutation_2(const string &str1, const string &str2)
{
	if(str1.length()!= str2.length())
	{
		return false;
	}
	int count[256] = {0};

	for(int i =0; i<str1.length(); ++i)
	{
		int val = str1[i];
		count[val]++;
	}

	for(int i =0; i<str1.length(); ++i)
	{
		int val = str2[i];
		count[val]--;
		if(count[val]<0)
			return false;
	}

	return true;
}

int main() 
{
// Test Method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
}
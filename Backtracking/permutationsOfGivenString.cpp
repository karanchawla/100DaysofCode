#include <iostream>
#include <string>

using namespace std; 

void permutations(string &str, int i)
{
	int n = str.length();

	if(i == n - 1)
	{
		cout << str << endl;
		return;
	}

	for(int j = i; j < n; j++)
	{
		swap(str[i], str[j]);

		permutations(str, i+1);

		swap(str[i], str[j]);
	}
}

int main()
{
	string str = "abcd";

	permutations(str, 0);
}
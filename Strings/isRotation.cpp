#include <string> 
#include <algorithm>
#include <iostream>

using namespace std; 

bool isRotation(string x, string& y)
{
	if(x.length() != y.length())
		return false;

	for(int i = 0; i < x.length(); i++)
	{
		rotate(x.begin(), x.begin()+1, x.end());

		if(!x.compare(y))
			return true;
	}

	return false; 
}
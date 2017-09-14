#include <iostream> 

int reverseInteger(int x)
{

	long long result = 0;
	while(x)
	{
		result = result*10 + x%10;
		x = x/10;
	}

	return result;
}
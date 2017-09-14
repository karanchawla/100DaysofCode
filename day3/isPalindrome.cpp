#include <iostream>

// Check if number is a Palindrome without using extra space

bool isPalindrome(int x)
{
	if (x<0 || (x!=0 && x%10==0)) return false;

	while(x > sum)
	{
		sum = sum*10 + x%10;

		x = x/10;
	}

	return (x==sum)||(x==sum/10);
}
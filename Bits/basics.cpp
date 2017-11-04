#include <iostream>

using namespace std;

// Check if int is even or odd
int main()
{
	int n = 5;

	if(n&1)
		cout << "odd";
	else 
		cout << "even";

	return (0);
}

//Check if numbers have opposite signs 
int main()
{
	int x = 1;
	int y = -2;

	if(x^y < 0)
		cout << "Yes";
	else
		cout << "No";
}

// Add one to a number
int main()
{
	int x = 1;
	cout << -~x;
}

// Swapping numbers without using third variable
void swap(int &x, int &y)
{
	if(x!=y)
	{
		x = x^y;
		y = x^y;
		x = x^y;
	}
}

// Turn off kth bit in a number 
int turnOffKthBit(int n, int k)
{
	return n & ~(1 << (k-1));
}

// Turn on kth bit in a number
int turnOnkthBit(int n, int k)
{
	return n | (1 << (k-1));
}

// Check if kth bit is one or not
int checkKthBit(int n, int k)
{
	return n & (1 << (k-1));
}

// Toggle kth bit
int toggle(int n, int k)
{
	return n ^ (1 << (k-1));
}


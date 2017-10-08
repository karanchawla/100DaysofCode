#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

bool isPerfectSquare(int num)
{
	int b = sqrt(num);
	return b*b == num ? true : false;	
}

int main()
{
	cout << isPerfectSquare(16);
}
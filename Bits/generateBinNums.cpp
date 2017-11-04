#include <iostream>
#include <vector> 
#include <bitset>

using namespace std;

void generate(int n)
{
	for(int i = 0; i < n; i++)
	{
		bitset<8> binary(i);

		cout << binary.to_string() << " ";	
	}

	return;
}

int main()
{

	int n = 8;
	generate(n);
}
#include <iostream> 
#include <vector> 

using namespace std; 

vector<int> getRow(int rowIndex)
{
	vector<int> vi(rowIndex + 1);
	vi[0] = 1;
	for(int i = 0; i <=rowIndex; ++i)
	{
		for(int j = i; j > 0; --j)
		{
			vi[j] = vi[j] + vi[j-1];
		}
		for(auto i : vi) cout << i << " ";
			cout << endl;
	}

	return vi;
}

int main()
{
	vector<int> nums = getRow(3);

	for(auto i : nums)
	{
		cout << i;
	}

	return 0;

}
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printVector(const vector<int> & nums)
{
	for(auto i : nums)
		cout << i << " ";
	cout << endl;
}

void printPowerSet(vector<int> &Set, vector<int> &out, int i)
{
	if(i < 0)
	{
		printVector(out);
		return;
	}

	out.push_back(Set[i]);
	printPowerSet(Set, out, i - 1);

	out.pop_back();
	while(Set[i] == Set[i-1])
		i--;

	printPowerSet(Set, out, i - 1);
}

void findPowerSet(const vector<int> &Set)
{
	int n = Set.size();
	int N = pow(2,n);

	unordered_set<string> set;
	for(int i = 0; i < N; i++)
	{
		string subset;
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
				subset += to_string(Set[j]) + " ";

		}

		set.insert(subset);
	}

	for(string subset: set)
		cout << subset << endl;

}

int main()
{
	vector<int> Set = {1, 3, 1};

	vector<int> out; 

	sort(Set.begin(), Set.end());
	findPowerSet(Set);
}
#include <map> 
#include <unordered_map>
#include <iostream> 
#include <vector> 
#include <string>

using namespace std; 

int knapsack(int v[], int w[], int n, int k)
{
	if(W < 0)
		throw runtime_error("Weight can't be negative");

	if(n < 0 || w == 0)
	{
		return 0;
	}

	
	string key = to_string(n) + "|" + to_string(w);

	if(lookup.find(key) == lookup.end())
	{
		int include = v[n] + knapsack(v, w, n-1, w - w[n]);

		int exclude = knapsack(v, w, n-1, w);

		lookup[key] = max(include, exclude);
	}

	return lookup[key];
}
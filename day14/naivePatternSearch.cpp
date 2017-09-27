// Find all the occurences of pattern p in string s

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int naiveFindPattern(string s, string p)
{
	size_t n = s.size();
	size_t m = p.size();

	if(m > n || m==0 || n==0) return -1;

	for (int i = 0; i <=n-m; ++i)
	{
		int j;
		for(j = 0; j < m; ++j)
		{
			if(s[i+j]!=p[j])
				break;
		}
		if(j==m)
			return i;
	}
}

/* Driver program to test above function */
int main()
{
   string s = "AABAACAADAABAAABAA";
   string p = "CAADA";
   cout << naiveFindPattern(s, p);
   return 0;
}
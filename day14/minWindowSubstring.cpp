#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t)
{
	vector<int> map(128,0);
	for(auto c: t) map[c]++;
	int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
	while(end < s.size())
	{
		if(map[s[end++]]-- > 0) counter--;
		while(counter==0)
		{
			if(end-begin<d) d = end - (head=begin);
			if(map[s[begin++]]++==0) counter++;
		}
		cout << s[end] << map[s[end]] << end << begin << head << " " << d << endl;
	}

	return d==INT_MAX ? "" : s.substr(head,d);
}

int main(int argc, char**argv)
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    if (argc>2){
        S = argv[1];
        T = argv[2];
    }
    cout << "S = \"" << S << "\"  T=\"" << T << "\"" <<endl;
    cout << minWindow(S, T) << endl;
    return 0;
}
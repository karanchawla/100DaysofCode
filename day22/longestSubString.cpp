#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring01(string s)
{
	map<char, int> m;
	int maxLen = 0;
	int lastRepeatedPos = -1;

	for(int i = 0; i <s.size(); i++)
	{
		if(m.find(s[i])!=m.end() && lastRepeatedPos < m[s[i]])
		{
			lastRepeatedPos = m[s[i]];
		}
		if(i - lastRepeatedPos > maxLen)
		{
			maxLen = i - lastRepeatedPos;
		}
		m[s[i]] = i;
	}

	return maxLen;
}

int lengthOfLongestSubstring(string s)
{
	const int MAX_CHARS = 256;
	int m[MAX_CHARS];
	int maxLen = 0;
	int lastRepeatedPos = -1;

	memset(m, -1, sizeof(m));
	for(int i =0; i < s.size(); ++i)
	{
		if(m[s[i]]!= -1 && lastRepeatedPos < m[s[i]])
		{
			lastRepeatedPos = m[s[i]];
		}
		if(i - lastRepeatedPos > maxLen)
		{
			
			maxLen = i - lastRepeatedPos;	
			cout << "max" << maxLen << endl;
		}
		
		cout << lastRepeatedPos << endl;
		m[s[i]] = i;
	}

	return maxLen;
}

int main(int argc, char** argv)
{
    string s = "abcabcbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbabcdb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    if (argc>1){
        s = argv[1];
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}

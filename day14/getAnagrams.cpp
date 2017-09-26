// Given a sequence of words, print all anagrams together | Set 1
// Given an array of words, print all anagrams together. For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”}, then output may be “cat tac act dog god”.

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string> >v;
    map<string,vector<string> >m;
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        cout << s << " " << strs[i] << endl;
        m[s].push_back(strs[i]);
    }
    for(map<string, vector<string> >::iterator it=m.begin();it!=m.end();it++)
    {
        v.push_back(it->second);
    }
    return v;
}

int main()
{
    const char* vinit[] = {"cat", "dog", "tac", "god", "act"};
    vector<string> wordVec(vinit, end(vinit));
    vector<vector<string> > v =  groupAnagrams(wordVec);
    for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        cout << v[i][j] << " ";
    }
}
    return 0;
}
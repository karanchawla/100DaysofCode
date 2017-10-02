#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string distinctChars(string &str)
{
  size_t len = str.length();

  vector<int> count(256,0);
  for(int i=0; i<len; ++i)
  {
    count[str[i]]++;
  }

  string result;

  for(int i=0; i<len; ++i)
  {
    if(count[str[i]] == 1)
      result.push_back(str[i]);
  }

  return result;
}

int main()
{
  string str("Geeks Quiz");

  cout << distinctChars(str) << endl;

}

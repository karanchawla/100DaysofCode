#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkLoveLetter(const string &L, const string &N)
{
  unordered_map<char, int> hash;

  for(auto i: N) hash[i]++;
  
  for(size_t i = 0; i < L.size(); i++)
  {
    char curr = L[i];
    if(hash.find(L[i]) != hash.end())
    {
      if(hash[L[i]]>0)
        hash[L[i]]--;
      else if(hash[L[i]]==0)
        return false;
    }
    else
      return false;
  }
  
  return true;
}
int main()
{
    //std::cout << "Hello Pramp!" << std::endl;
    string L = "aabcd";
    string N = "abcdefghijklmnoa";
    cout << checkLoveLetter(L,N);
    return 0;
}
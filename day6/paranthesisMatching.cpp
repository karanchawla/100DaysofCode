#include <iostream>
#include <vector> 
#include <string>

using namespace std;

bool areParanthesisMatched(char expr[])
{
	stack<char> s;
	char a,b,c;
	
	for (int i = 0; i < strlen(expr); ++i)
	{
		if(expr[i] == '(' || expr[i] ==  '[' || expr[i] == '{')
		{
			s.push(expr[i]);
		}
		else
		{
			switch(expr[i])
			{
				case ')':	
					a = s.top();
					s.pop();
					if(a == '{' || a == '[')
					{
						cout << "Not balanced";
					}
					break;

				case ']':	
					b = s.top();
					s.pop();
					if(b == '(' || b == '{')
					{
						cout << "Not balanced";
					}
					break;
				case '}':	
					c = s.top();
					s.pop();
					if(c == '(' || c == '{')
					{
						cout << "Not balanced";
					}
					break;
			}
		}	
	}

	if(s.empty())
		return True;
	else
		return False;
}

// Better Solution 
bool is_balanced(string expression) {
  stack<char> s;
  for (char c : expression) {
    if      (c == '{') s.push('}');
    else if (c == '[') s.push(']');
    else if (c == '(') s.push(')');
    else {
      if (s.empty() || c != s.top())
        return false;
      s.pop();
    }
  }
  return s.empty();
}
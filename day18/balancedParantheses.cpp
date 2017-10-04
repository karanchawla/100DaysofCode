// Check for balanced parantheses in an expression 

#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool areParathesesBalanced(string expr)
{
	stack<char> s;
	char a,b,c,d;

	// Traverse the expression 
	for(int i = 0; i < expr.size(); i++)
	{
		if(expr[i]=='{' || expr[i]=='<' || expr[i]=='(' || expr[i]=='[' )
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
					if(a == '{' || a == '[' || a == '<')
						cout << "Not balanced";
					break;
				case '}':
					b = s.top();
					s.pop();
					if(b == '(' || b == '[' || b == '<')
						cout << "Not balanced";
					break; 
				case ']':
					c = s.top();
					s.pop();
					if(c == '{' || c == '(' || c == '<')
						cout << "Not balanced";
					break;
				case '>':
					d = s.top();
					s.pop();
					if(d == '(' || d == '[' || d == '{')
						cout << "Not balanced";
					break;
			}
		}
	}

	if(s.empty())
		return true;
	else
		return false;
}

int main()
{
    string expr("{()}[]");
 
    if(areParathesesBalanced(expr))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}
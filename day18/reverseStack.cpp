// Write a program to reverse a stack using recursion 
/*
Mehtod 1 : brute force method to this is to just pop each element from the top of the stack and push it on a queue.
*/

#include <iostream>
#include <stack> 
#include <vector>

using namespace std;

// Uses O(n) space
stack<int> reverseStack(stack<int> &s)
{
	stack<int> result_stack;

	while(!s.empty())
	{
		result_stack.push(s.top());
		s.pop();
	}

	return result_stack;
}

// When not allowed to use extra space

int insert_at_bottom(stack<int> &s, int x)
{
	if(s.empty())
		s.push(x);
	else
	{
		int a = s.top();
		s.pop();
		insert_at_bottom(s, x);

		s.push(a);
		// cout << a << endl;
	}
}

void reverse(stack<int> &s)
{
	if(!s.empty())
	{
		int x = s.top();
		s.pop();
		reverse(s);

		insert_at_bottom(s, x);
	}
}



int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	reverse(s);
}

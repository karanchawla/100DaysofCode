// Stacks are a type of container adpators with LIFO type of working where a new element is added at one end and top element is removed from that end only. 

/*

Functions associated with stacks are: 
1. empty() - returns whether the stack is empty 
2. size() - returns the size of the stack 
3. top() - returns a reference to the top most element of the stack 
4. push(g) - pushes an element to the top of the stack 
5. pop() - removes the top most element from the stack 
*/ 

#include <iostream>
#include <stack>

using namespace std;
 
void showstack(stack <int> list_stack)
{
	stack <int> g = list_stack; 

	while(!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main ()
{
    stack <int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
 
    cout << "The stack gquiz is : ";
    showstack(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showstack(gquiz);
 
    return 0;
}
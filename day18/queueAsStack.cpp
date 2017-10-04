// Implement a queue as a stack - given a stack data structure with push and pop operations, the task is to implement a queue using instance of stack ds and operations on them 

#include <iostream>
#include <cstdio>

using namespace std; 

// Stack is LIFO
// Queue is FIFO 

// Method 1 is to make enqueue operation costly 
// eqQueue(q, x)
// 1. while stack1 is not empty, push everything from stack1 to stack2
// 2. Push x to stack1 
// 3. Push everything back to stack 1

// deQueue(q)
// 1. if stack 1 is empty then error 
// 2. pop an item from stack1 and return it 

// Method 2 is to make the deQueue operation costly 
// enQueue(q, x)
// 1. push x to stack1 

// deQueue(q)
// 1. If both stacks are empty then error 
// 2. If stack2 is empty 
// 		whiel stack1 is not empty, push everything from stack1 to stack2 
// 3. return the top element from stack2 and return it 

// Q implementaion using single stack and functional stack
 
#include<iostream>
#include<stack>
 
using namespace std;
 
stack<int> s;
 
bool isQEmpty(){
	return s.empty();
}
 
int sizeQ(){
	return s.size();
}
 
void enQ(int item){
	s.push(item);
}
 
int deQ(){
	int item;
	if(s.empty()) {
		cout << "Q is empty !" << endl;
		return -1;
	}
 
	item = s.top();
	if(s.size() == 1){
		s.pop();
		return item;
	}
	s.pop();
	int res = deQ();
	s.push(item);
	cout << "I'm in deQ" << endl;
	return res;
}
 
int main(){
	int item;
	enQ(10);
	enQ(32);
	enQ(11);
	enQ(22);
	enQ(30);
	enQ(42);
	enQ(50);
	enQ(62);
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	item = deQ();
	cout << "Dequeued item is " << item << endl;
	return 0;
}
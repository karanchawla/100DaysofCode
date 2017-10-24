#include <iostream>
#include <vector> 

using namespace std; 

struct Node
{
	int data; 
	struct Node* next; 
};

void push(Node* &head, int data)
{
	Node* newNode = new Node; 
	newNode->data = data;
	newNode->next = head;

	head = newNode;
}

void printList(Node* head)
{
	Node* ptr = head;
	while(ptr)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// Remove duplicates from the linked list
void removeDuplicates(Node* head)
{
	if(!head || !head->next)
		return;

	Node* ptr = head->next;
	Node* prev = head;

	while(ptr)
	{
		if(ptr->next == nullptr && prev->data == ptr->data)
		{
			prev->next = nullptr;
			delete ptr;
			break;
		}

		else if (prev->data == ptr->data)
		{
			prev->next = ptr->next;
			delete ptr;
			ptr = prev->next;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}

		

		cout << prev->data << ptr->data << endl;
	}
}

// reverse k nodes of the linked list
Node* reversK(Node* &curr, int k)
{
	Node* result = nullptr;
	Node* prev = nullptr;

	int count = 0;
	while(curr && count++ < k)
	{
		Node* next = curr->next;
		curr->next = result;
		result = curr;
		prev = curr;
		curr = next;
	}

	return prev;
}

// Reverse in groups of k ***
Node* reverseInGroups(Node* head, int k)
{
	if(head == nullptr)
		return nullptr;

	Node* curr = head;

	Node* prev = reversK(curr, k);

	head->next = reverseInGroups(curr, k);

	return prev;
}

// reverse a linked list
void reverLinkedList(Node* head, Node* &headref)
{
	Node* first;
	Node* second;

	if(head==nullptr)
		return;

	first = head;
	second = head->next;

	if(second == nullptr)
	{
		headref = first;
		return;
	}

	reverLinkedList(second, headref);

	second->next = first;
	first->next = nullptr;
}

//kth node from the end of the linked list 
int getKthNode(Node* head, int k)
{
	Node* slow = head;
	Node* fast = head;

	for(int i = 0; fast && i < k; i++,fast = fast->next){}

	while(fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow->data;
}


// Move end node to the start of the linked list
void rearrange(Node* &headref)
{
	if(!headref || !headref->next)
		return;

	Node* ptr = headref;

	while(ptr->next->next)
	{
		ptr = ptr->next;
	}

	ptr->next->next = headref;

	headref = ptr->next;

	ptr->next = nullptr;
}

int main()
{
	int keys[] = {1,2,3,4,5,6};
	int n = sizeof(keys)/sizeof(keys[0]);

	Node* head = nullptr;
	for(int i = n - 1; i >=0 ; i--)
	{
		push(head, keys[i]);
	}

	// rearrange(head);

	// removeDuplicates(head);

	// cout << getKthNode(head, 5);

	// reverLinkedList(head, head);

	head = reverseInGroups(head, 2);

	printList(head);

	return(0);
}
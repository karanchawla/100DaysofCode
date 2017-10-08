#include <iostream>
#include <vector> 

using namespace std;

ListNode* reverseLinkedList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* curr = head; 
	ListNode* next;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	head = prev;
	return head;
}
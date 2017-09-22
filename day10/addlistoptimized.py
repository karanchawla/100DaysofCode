from linkedLists import *

def addLinkedLists(lla, llb):
	result_list = LinkedList()
	result = 0
	carry = 0
	curr1, curr2 = lla.head, llb.head
	while curr1 or curr2:
		result = carry
		if curr1:
			result+= curr1.data
			curr1 = curr1.next

		if curr2:
			result+= curr2.data
			curr2 = curr2.next

		result_list.push(result%10)
		carry = result//10

	if carry:
		result_list.push(carry)

	return result_list

llist1 = LinkedList()
llist1.head = Node(1)
second1 = Node(2)
third1 = Node(3)
llist1.head.next = second1
second1.next = third1

llist2 = LinkedList()
llist2.head = Node(2)
second2 = Node(3)
third2 = Node(4)
llist2.head.next = second2
second2.next = third2

result = addLinkedLists(llist1,llist2)
result.print_linkedlist()
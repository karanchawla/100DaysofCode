from linkedLists import *

def remove_duplicates(ll):
	if ll.head is None:
		return 

	current = ll.head
	seen = set([current.data])

	while(current.next):
		if current.next.data in seen:
			current.next = current.next.next
		else:
			seen.add(current.next.data)
			current = current.next

	return ll 

def remove_duplicates_followup(ll):
	if ll.head is None:
		return

	current = ll.head
	while current:
		runner = current
		while runner.next:
			if runner.next.data == current.data:
				runner.next = runner.next.next
			else:
				runner = runner.next
		current = current.next

	return ll.head


ll = LinkedList()

ll.head = Node(1)
second = Node(2)
third = Node(2)
ll.head.next = second
second.next = third

ll.print_linkedlist()
remove_duplicates_followup(ll)
ll.print_linkedlist()


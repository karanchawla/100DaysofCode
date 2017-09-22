from linkedLists import *


def kth_to_last(ll, k):

	size = ll.getCount()
	if not size:
		return

	m = size - k
	current = ll.head
	i = 1
	while(current.next and i < m):
		current = current.next
		i+=1

	return current.data


ll = LinkedList()

ll.head = Node(1)
second = Node(2)
third = Node(3)
ll.head.next = second
second.next = third

print(kth_to_last(ll, 2))
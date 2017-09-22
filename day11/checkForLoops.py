class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	def __init__(self):
		self.head = None

	def push(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node

	def printList(self):
		curr = self.head
		while(curr):
			print(curr.data)
			curr = curr.next


def checkForLoops(ll):
	hashmap = set([])
	curr = ll.head
	while (curr):
		if curr in hashmap:
			return False
		hashmap.add(curr)
		curr = curr.next

	return True 



llist = LinkedList()
llist.head = Node(1)
second = Node(2)
third = Node(3)
fourth = Node(4)
llist.head.next = second
second.next = third
third.next = fourth
fourth.next = None

print(checkForLoops(llist))
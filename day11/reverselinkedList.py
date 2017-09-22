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

def isPalindrome(ll):
	if(ll.head is None):
		return True
	
	reversedLinkedList = reverse(ll)
	curr = ll.head
	rcurr = reversedLinkedList.head
	while(curr):
		if curr.data != rcurr.data:
			return False
		curr = curr.next
		rcurr = rcurr.next


	return True

def reverse(ll):
	prev = None
	curr = ll.head
	while(curr):
		next = curr.next
		curr.next = prev
		prev = curr 
		curr = next 
	ll.head = prev
	
	result = LinkedList()
	temp = ll.head
	while(temp):
		result.push(temp.data)
		temp = temp.next

	return result

llist = LinkedList()
llist.push(20)
llist.push(4)
llist.push(4)
llist.push(20)

print(isPalindrome(llist))
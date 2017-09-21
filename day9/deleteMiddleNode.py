from linkedLists import *

def delete_middle_node(node):
    node.data = node.next.data
    node.next = node.next.next

llist = LinkedList()

llist.head = Node(1)
second = Node(2)
third = Node(3)
llist.head.next = second
second.next = third

delete_middle_node(second)
llist.print_linkedlist()

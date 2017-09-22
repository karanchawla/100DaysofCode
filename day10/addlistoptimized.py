from day9.linkedLists import *


ll = LinkedList()

ll.head = Node(1)
second = Node(2)
third = Node(2)
ll.head.next = second
second.next = third

ll.print_linkedlist()
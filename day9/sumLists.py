from linkedLists import *

def sum_lists(list1, list2):
    first = []
    second = []
    current1 = list1.head
    current2 = list2.head
    while(current1):
        first.append(str(current1.data))
        current1 = current1.next

    while(current2):
        second.append(str(current2.data))
        current2 = current2.next

    first = int(''.join(first))
    second = int(''.join(second))
    return first + second

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

print(sum_lists(llist1, llist2))

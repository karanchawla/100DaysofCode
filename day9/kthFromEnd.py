from linkedLists import *

def kth_from_end(ll,k):
    runner = ll.head
    follower = ll.head
    for i in range(k):
        if runner is None:
            return None
        runner = runner.next

    while(runner.next):
        follower = follower.next
        runner = runner.next

    return follower.data

llist = LinkedList()

llist.head = Node(1)
second = Node(2)
third = Node(3)
llist.head.next = second
second.next = third

print(kth_from_end(llist, 2))

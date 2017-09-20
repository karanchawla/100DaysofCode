class Node:

    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:

    def __init__(self):
        self.head = None

    def print_linkedlist(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

    # Add a new node at the beginning of the linked list
    def push(self,new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Add a new node after a particular node
    def insert_after(self, prev_node, new_data):
        if prev_node is Node:
            return

        new_node = Node(new_data)
        new_node.next = prev_node.next
        prev_node.next = new_node

    # Add a node at the end of the linked list
    def append(self, new_data):
        new_node = Node(new_data)
        temp = self.head

        while(temp.next):
            temp = temp.next

        temp.next = new_node

    # Find length of linked list
    def getCount(self):
        temp = self.head 
        count = 0
        while(temp):
            count +=1
            temp = temp.next

        return count 

    #Search an element in linked list
    def search(self, key):
        temp = self.head
        while(temp):
            if(temp.data == key):
                return True
            temp = temp.next

        return False



if __name__ == "__main__":

    llist = LinkedList()

    llist.head = Node(1)
    second = Node(2)
    third = Node(3)
    llist.head.next = second
    second.next = third

    print(llist.search(2))

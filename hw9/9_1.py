#------a------
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self, size = -1):
        self.head = None
        self.size = size
        self.current_size = 0
        
    def push(self, data):
        if self.current_size >= self.size:
            print('Stack is full')
        else:
            self.current_size += 1
            if self.head is None:
                self.head = Node(data)
            else:
                new_node = Node(data)
                new_node.next = self.head
                self.head = new_node
    
    def pop(self):
        if self.head is None:
            print('Stak is empty')
            return None
        else:
            self.current_size -= 1
            popped = self.head.data
            self.head = self.head.next
            return popped
        
    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False
        
stack = Stack(3)
stack.push(1.5)

#------b------
class Queue:
    def __init__(self):
        self.in_stack = Stack(50)
        self.out_stack = Stack(50)
        
    def enqueue(self, item):
        self.in_stack.push(item)
    
    def dequeue(self, item):
        if self.out_stack.isEmpty:
            while self.in_stack.current_size()>0:
                self.out_stack.push(self.in_stack.pop())
        return self.out_stack.pop()
    

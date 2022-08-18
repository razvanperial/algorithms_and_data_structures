
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
 
# Linked List class contains a Node object
class LinkedList:   
    def __init__(self):
        self.head = None
    def push(self, data):
        if self.head is None:
                self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
    
    def pop(self):
        if self.head is None:
            print('List is empty')
            return None
        else:
            popped = self.head.data
            self.head = self.head.next
            return popped
        
class TreeNode:
    def __init__(self, key, right = None, left = None):
        self.key = key
        self.right = right
        self.left = left
    
class Tree:
    def __init__(self):
        self.root = None
    def insert(self, z):
        y = None
        x = self.root
        while x != None:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.p = y
        if y == None:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else: 
            y.right = z

class Solution:
    def listtobst(self, list):
        n = 0
        cur = list.head
        while cur:
            cur = cur.next
            n += 1
        self.head = list.head
        def rec(st, end):
            if st > end:
                return None
            
            mid = (st+end)//2
            #left
            left = rec(st, mid-1)
            #root
            root = TreeNode(self.head.data)
            self.head = self.head.next
            root.left = left
            #right
            root.right = rec(mid+1, end)
            
            return root
        
        return rec(0, n-1)

    
    

list = LinkedList()
for i in range(1,15):
    list.push(i)
    print(i)
    
ans = Solution()

        
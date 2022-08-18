from math import floor
from re import L


def maxHeapify(arr, n,  i):
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[i]:
        largest = l
    else:
        largest = i
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        maxHeapify(arr, n, largest)
        
def buildMaxHeap(arr):
    for i in range (len(arr), -1, -1):
        maxHeapify(arr,len(arr), i)

def heapSort(arr):
    buildMaxHeap(arr)
    for i in range (len(arr) - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        maxHeapify(arr, i,  0)
        

a = [9,8,7,6,5,4,3,2,1]

heapSort(a)
print(a) 
    
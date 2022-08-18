from array import array
from random import randint
import time
import numpy as np
from numpy.random import seed
import matplotlib.pyplot as plt


def lomotoPartition(arr, p, q):
    x = arr[p]
    i = p
    for j in range(p + 1, q):
        if arr[j] <= x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[p], arr[i] = arr[i], arr[p]
    return i 

def hoarePartition(arr, p, q):
    pivot = arr[p]
    i = p - 1
    j = q + 1
    
    while True:
        while True:
            i+=1
            if arr[i] >= pivot:
                break
            
        while True:
            j-=1
            if arr[j] <= pivot:
                break
            
        if i >= j:
            return j
        
        arr[i], arr[j] = arr[j], arr[i]
        
def motPartition(arr, p, q):
    #choose the medin of the first, middle and last element as pivot
    mid = (p+q)//2
    if arr[mid] < arr[p]:
        arr[mid], arr[p] = arr[p], arr[mid]
    if arr[q] < arr[p]:
        arr[q], arr[p] = arr[p], arr[q]
    if arr[mid] < arr[q]:
        arr[mid], arr[q] = arr[q], arr[mid]
    
    pivot = arr[q]   
    #perform hoare partition
    i = p - 1
    j = q + 1
    
    while True:
        while True:
            i+=1
            if arr[i] >= pivot:
                break
            
        while True:
            j-=1
            if arr[j] <= pivot:
                break
            
        if i >= j:
            return j
        
        arr[i], arr[j] = arr[j], arr[i]
        
def quicksort(arr, p, r, part):
    if p < r:
        q = part(arr, p, r)
        quicksort(arr, p, q, part)
        quicksort(arr, q+1, r, part)

c = 1
t1, t2, t3 = 0, 0, 0

while c <= 2000:
    print(c)
    c += 1
    
    a1 = np.random.randint(1, 10000, size = 10000)
    start = time.process_time()
    quicksort(a1, 0, len(a1), lomotoPartition)
    end = time.process_time()
    t1 += end-start
    
    a2 = np.random.randint(1, 1000, size = 1000)
    start = time.process_time()
    quicksort(a2, 0, len(a2) - 1, hoarePartition)
    end = time.process_time()
    t2 += end-start
    
    a3 = np.random.randint(1, 1000, size = 1000)
    start = time.process_time()
    quicksort(a3, 0, len(a3) - 1, motPartition)
    end = time.process_time()
    t3 += end-start
    
print("Average time for lomoto: " ,t1/2000)
print("Average time for hoare: " ,t2/2000)
print("Average time for mot: " ,t3/2000)

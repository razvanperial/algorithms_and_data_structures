from array import array
from random import randint
import time
import numpy as np
from numpy.random import seed
import matplotlib.pyplot as plt

def lomotoPartition(arr, p, q):
    #choosing two random numbers from the array and setting them to be the first elements
    n1 = randint(p,q)
    n2 = randint(p,q)
    if(p < q):
        while(n2 == n1):
            n2 = randint(p,q)
    arr[p], arr[n1] = arr[n1], arr[p]
    arr[p+1], arr[n2] = arr[n2], arr[p+1]
    if arr[p] > arr[p+1]:
        arr[p], arr[p+1] = arr[p+1], arr[p]
    
    x1 = arr[p]
    x2 = arr[p+1]
    i = p + 1
    j = p + 1
    k = 0
    for k in range(p + 2, q +1):
        if arr[k] <= x1:
            i += 1
            j += 1
            arr[i], arr[j] = arr[j], arr[i]
            if j < k:
                arr[i], arr[k] = arr[k], arr[i]
        else: 
            if arr[k] <= x2:
                j += 1
                arr[j], arr[k] = arr[k], arr[j]
        

    arr[p+1], arr[j] = arr[j], arr[p+1]
    if i != j:
        arr[p+1], arr[i] = arr[i], arr[p+1]
    arr[p], arr[i-1] = arr[i-1], arr[p]
    return i-1, j

def quicksort(arr, p, r):
    if p < r:
        lp,rp = lomotoPartition(arr, p, r)
        quicksort(arr, p, lp-1)
        quicksort(arr, lp, rp-1)
        quicksort(arr, rp, r)

randArrayTimes = list()
sortedArrayTimes = list()
descendingArrayTimes = list()
val = list()


a = np.random.randint(1,20, size = 20)
print(a)
quicksort(a, 0, len(a) - 1)
print(a)
    
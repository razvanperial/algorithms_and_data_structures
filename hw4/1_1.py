from array import array
from random import randint
import time
import numpy as np
from numpy.random import seed
import matplotlib.pyplot as plt


def insertionSort(a):
  
    for i in range(1, len(a)):
  
        x = a[i]

        j = i-1
        while j >=0 and x < a[j] :
                a[j+1] = a[j]
                j -= 1
        a[j+1] = x

def merge(a, left, right):
    i = 0 #left array index
    j = 0 #right array index
    h = 0 #big array index
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            a[h] = left[i]
            i += 1
        else:  
            a[h] = right[j]
            j+=1

        h += 1

    while i < len(left):
        a[h] = left[i]
        i += 1
        h += 1

    while j < len(right):
        a[h] = right[j]
        j += 1
        h += 1

def combinedSort(a, k):
    if len(a) > k:
        left = a[:len(a)//2]
        right = a[len(a)//2:]
        
        #recursion step
        combinedSort(left, k)
        combinedSort(right, k)

        #merge step
        merge(a, left, right)
    else:
        insertionSort(a)
        

elements = list()
times = list()            

k = 10000
while k >= 1:
    
    a = np.random.randint(1, 10000, size = 10000) #random case
    combinedSort(a,1) # best case (array already sorted)
    a = np.flipud(a) # worst case - inversely sorted array
        
        
    start = time.process_time()
    combinedSort(a,k) #selection sort starts when arrays are bigger
    end = time.process_time()

    print(len(a), "elements Sorted with k = ", k, "in ", end-start, "seconds")
    elements.append(k)
    times.append(end-start)
    
    k //= 2
    
plt.xlabel('k value')
plt.ylabel('Time Complexity')
plt.plot(elements, times, label = '//Worst Case//')
plt.grid()
plt.legend()
plt.show()
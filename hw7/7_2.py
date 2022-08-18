from array import array
from random import randint
import time
import numpy as np
from numpy.random import seed
import matplotlib.pyplot as plt

def lomotoPartition(arr, p, q):
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

c = 1
while c < 1000:
    c += 1
    print(c)
    a = np.random.randint(1,1000, size = 1000)
    start = time.process_time()
    quicksort(a, 0, len(a) - 1)
    end = time.process_time()
    randArrayTimes.append(end - start)
    
    start = time.process_time()
    quicksort(a, 0, len(a) - 1)
    end = time.process_time()
    sortedArrayTimes.append(end-start)
    
    a = np.flipud(a)
    start = time.process_time()
    quicksort(a, 0, len(a) - 1)
    end = time.process_time()
    descendingArrayTimes.append(end-start)
    
    val.append(c)
    
plt.plot(val, randArrayTimes, label = 'Random Array')
plt.plot(val, sortedArrayTimes, label = 'Sorted Array')
plt.plot(val, descendingArrayTimes, label = 'Descending Array')
plt.grid()
plt.legend()
plt.show()
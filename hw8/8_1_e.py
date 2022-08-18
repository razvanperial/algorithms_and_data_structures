from random import Random, randint
import numpy as np
import matplotlib.pyplot as plt
import time


def insertionSort(arr):
    for i in range(1, len(arr)):
        x = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > x:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = x       

def bucket_sort(arr):
    n = len(arr)
    b = []
    
    for i in range(n):
        b.append([])
        
    for i in arr:
        b[int(i*n)].append(i)
        
    for i in b:
        insertionSort(i)
        
    k = 0
    for i in range(len(b)):
        for j in range(len(b[i])):
            arr[k] = b[i][j]
            k += 1
    return arr

randomT = 0
samebucketT = 0
sortedT = 0

#random array
for i in range(1,1000):
    a = np.random.uniform(0.0, 1.0, size=3000)
    start = time.process_time()
    a = bucket_sort(a)
    stop = time.process_time()
    randomT += stop - start
    
#all elements fall in the same bucket
for i in range(1,1000):
    a = np.random.uniform(0.20, 0.29, size=3000)
    start = time.process_time()
    a = bucket_sort(a)
    stop = time.process_time()
    samebucketT += stop - start
    
#random sorted array
for i in range(1,1000):
    a = np.random.uniform(0.0, 1.0, size=3000)
    a = sorted(a)
    start = time.process_time()
    a = bucket_sort(a)
    stop = time.process_time()
    sortedT += stop - start
    
print("Average time complexity for sorted array: ", sortedT/i)
print("Average time complexity for random array: ", randomT/i)
print("Average time complexity for special array: ", samebucketT/i)

#as we can observe, the worst case scenario for bucket sort is when all the elements
#of the array will fall in the same bucket which will have to be sorted. The average
#time complexities calculated above reflect this theory
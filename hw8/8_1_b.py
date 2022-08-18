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


a = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
print('Unsorted array: ',a)
a = bucket_sort(a)
print('Sorted array: ',a)
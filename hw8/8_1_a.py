def count_sort(arr):
    c = [0 for i in range(1024)]
    ans = [0 for i in range(len(arr))]
    
    for i in arr:
        c[i] += 1
        
    for i in range(1024):
        c[i] += c[i - 1]
        
    for i in range (len(arr)):
        ans[c[arr[i]]-1] = arr[i]
        c[arr[i]] -= 1
    return ans

      
a = [9, 1, 6, 7, 6, 2, 1]
print('Unsorted array: ',a)
a = count_sort(a)
print('Sorted array: ',a)
        
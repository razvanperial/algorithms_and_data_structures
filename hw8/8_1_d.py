def count_sort(arr, exp):
    index = [0 for _ in range(124)]
    ans = ['' for _ in range(len(arr))]
    
    for str in arr:
        if(exp < len(str)):
            index[ord(str[exp])] += 1
        else:
            index[0] += 1
    
    for i in range(1, 124):
        index[i] += index[i-1]
        
    i = len(arr) - 1
    while i >= 0:
        str = arr[i]
        if(exp < len(str)):
            ans[index[ord(str[exp])] - 1] = str
            index[ord(str[exp])] -= 1
        else:
            ans[index[0] - 1] = str
            index[0] -= 1
        i -= 1
    
    return ans

def radix_sort(arr, d):
    i = d - 1
    while(i >= 0):
        arr = count_sort(arr,i)
        i -= 1
    return arr

a = ['word', 'category', 'cat', 'new', 'news', 'world', 'bear', 'at', 'work', 'time']
print('Unsorted array: ',a)
a = radix_sort(a,7)
print('Sorted array: ',a)
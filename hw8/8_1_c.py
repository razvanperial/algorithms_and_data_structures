#commented parts are pseudocode for the lines below them

#COUNT(A, k, a, b)
def count_a_b(arr, k, a, b):
    
#   for i := 0 to k do
#       C [ i ] := 0
    index = [0 for _ in range(k + 1)]
    
#   for i := 1 to n do 
    for i in arr:
#       C [ A [ i ] ] = C [ A [ i ] ] + 1
        index[i] += 1
    
#   fpr i := 2 to n do
    for i in range(1, k):
#       C [ i ] = C [ i ] + C [ i - 1 ]
        index[i] += index[i-1]
    
#   if a > 0 do  
    if a > 0:
#       return C [ b ] - C [ a - 1 ] 
        return index[b] - index[a-1]
#   return C [ b ]
    return index[b]

#example
a = [9, 1, 6, 7, 6, 2, 1, 3, 4, 5, 8]
print('Numbers in interval:', count_a_b(a, 9, 2, 6))
#we will perform msd radix_sort, but the numbers will be treated as hexadecimal values

#assume we work on 32 bit numbers => we transform the numbers in 32bit decimal
#and we porform msd radix sort on those numbers by looking at the hex representation
#(we know that each four bits represent a hexadecimal digit/letter)

from random import randint
import numpy as np

def insertion_sort(arr, exp):
    for i in range(1, len(arr)):       
        aux = arr[i]
         
        #get the 32-bits representation of the number
        key = '{:032b}'.format(arr[i])
        
        #perform basic insertion sort and sort after the 4 bites representing the digit we are currently on
        #also perform the switch only if the digits before the sorting digit are the same for the numbers we are comparing
        #example: 2976 and 2958 -> assume we sort after the second digit ( 7 and 5 ) - we would only perform the switch if 
        # the digits before 7 for the first number(2 and 9) and before 5 for the second number(still 2 and 9) are the same
        j = i - 1
        while (j >= 0) and (key[exp-4:exp] < '{:032b}'.format(arr[j])[exp-4:exp]) and (key[:exp-4] == '{:032b}'.format(arr[j])[:exp - 4]):
            arr[j + 1] = arr[j]
            j -= 1       
        arr[j + 1] = aux
    
def radix_sort(arr):
    #start by looking at the first set of 4 bites (first digit/letter) and move to the next
    #set of 4 until we reach the lest significant digit/letter (last 4 bites)
    i = 4
    while(i <= 32):
        insertion_sort(arr,i)
        i += 4
    return arr
    
    
    
a = np.random.randint(1, 5000, size = 14)
print('Unsorted array: ',a)
a = radix_sort(a)
print('Sorted array: ',a)

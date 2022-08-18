import time
from matplotlib import pyplot as plt
import numpy as np
import implementations as alg
from prettytable import PrettyTable


n = 13;             
i = 1
t1, t2, t3, t4 = 0, 0, 0, 0
naiveEl = list()
naiveT = list()
botupEl = list()
botupT = list()
clsfEl = list()
clsfT = list()
matrixEl = list()
matrixT = list()

myTable = PrettyTable(["Values of N", "Time Complexity for Naive Search","Time Complexity for BottomUp Search", 
                       "Time Complexity for ClosedForm Search", "Time Complexity for Matrix Search"])

while t2<0.1 and t4<0.1:
    if(n > 24):
        i += 1
        
    n += i
    
    botupEl.append(n)
    matrixEl.append(n)
    
    if(n < 35):
        naiveEl.append(n)
        start = time.process_time()
        alg.naiveFib(n)
        end = time.process_time()
        t1 = end - start 
        naiveT.append(t1)
        
    start = time.process_time()
    alg.bottomupFib(n)
    end = time.process_time()   
    t2 = end - start 
    botupT.append(t2)
    
    if(n < 1000):
        clsfEl.append(n)
        start = time.process_time()
        alg.closedformFib(n)
        end = time.process_time()   
        t3 = end - start 
        clsfT.append(t3)
    
    start = time.process_time()
    alg.matrixFib(n)
    end = time.process_time()   
    t4 = end - start 
    matrixT.append(t4)
    
    if(n < 35):
        myTable.add_row([str(n), str(t1), str(t2), str(t3), str(t4)])
    else: 
        if (n < 1000):
            myTable.add_row([str(n), 'Too Long', str(t2), str(t3), str(t4)])
        else:
            myTable.add_row([str(n), 'Too Long', str(t2), "Will throw math range error", str(t4)])
            
    
print(myTable)

with open('table.txt', 'w') as outputfile:
    outputfile.write(str(myTable))
    
    
plt.xlabel('n value')
plt.ylabel('Time Complexity')
plt.plot(naiveEl, naiveT, label = 'Naive Search')
plt.plot(botupEl, botupT, label = 'BottomUp Search')
plt.plot(clsfEl, clsfT, label = 'Closed Form Search')
plt.plot(matrixEl, matrixT, label = 'Matrix Search')
plt.grid()
plt.legend()
plt.show()
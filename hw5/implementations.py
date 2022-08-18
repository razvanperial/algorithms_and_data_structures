import math

def naiveFib(n):
    if n < 2:
        return n
    else: 
        return naiveFib(n-1) + naiveFib(n-2)
    
def bottomupFib(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a+b
    return a


def closedformFib(n):
    z = (1 + math.sqrt(5))/2  # Golden ratio.
    return math.ceil(math.pow(z,n)/math.sqrt(5))

def matrixMult(M1, M2):
    x = (M1[0][0] * M2[0][0] +
         M1[0][1] * M2[1][0])
    y = (M1[0][0] * M2[0][1] +
         M1[0][1] * M2[1][1])
    z = (M1[1][0] * M2[0][0] +
         M1[1][1] * M2[1][0])
    w = (M1[1][0] * M2[0][1] +
         M1[1][1] * M2[1][1])
    M1[0][0] = x
    M1[0][1] = y
    M1[1][0] = z
    M1[1][1] = w

def matrixPower(M, p):
    Maux = [[1,1],
            [1,0]]
    for i in range (1,p):
        matrixMult(M,Maux)
         
         
def matrixFib(n):
    M = [[1,1],
        [1,0]]
    if (n == 0):
        return 0
    else:
        matrixPower(M,n)
    return M[1][0]

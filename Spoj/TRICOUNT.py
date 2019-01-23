import math


def getFact(a):
    return math.factorial(a)


def getRes(n):
    if n == 1:
        return 1
    # preOp = (N+2)*(N+1)*N
    # preOp = preOp/6

    # count = 0
    # if N % 2 != 0:
    #     count = (math.pow(N, 2)-1)*(2*N+3)
    # else:
    #     count = N*(N+2)*((2*N)-1)
    #     # print count

    return (n*(n+2)*((2*n)+1))/8


T = input()
for i in range(0, T):
    print getRes(input())

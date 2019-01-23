A = []


def getRes(M):
    low, high = 0, len(A)-1
    ub, sum = -1, 0
    while(low <= high):
        mid = (low+high) >> 1
        if A[mid] <= M:
            ub = mid
            low = mid+1
        elif A[mid] > M:
            high = mid-1

    for i in range(0, ub+1):
        sum = sum+A[i]

    print str(ub+1)+" "+str(sum)


N = input()
for i in range(0, N):
    A.append(input())
A.sort()
for __ in range(input()):
    M = input()
    getRes(M)

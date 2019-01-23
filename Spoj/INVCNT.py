
def getRes(A):
    count = 0
    for i in range(0, len(A)):
        p = A[i]
        for j in range(i, len(A)):
            if p > A[j]:
                count += 1
    print count


T = input()
for i in range(0, T):
    raw_input()
    N = input()
    A=[]
    for j in range(0, N):
        A.append(input())
    getRes(A)

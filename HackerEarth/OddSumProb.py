

def getRes(A, L, R):
    dict = {}
    sum = 0
    for i in range(L, R):
        if A[i] not in dict:
            dict[A[i]] = 1
            sum += A[i]
        else:
            dict[A[i]] = dict[A[i]]+1
            val = dict[A[i]]
            if val % 2 == 0:
                sum -= ((val-1) * A[i])
            else:
                sum += (val*A[i])
        #print A[i], sum
    print sum

N = input()
A = map(int, raw_input().split())
Q = input()
for i in range(0, Q):
    L, R = map(int, raw_input().split())
    getRes(A, L-1, R)

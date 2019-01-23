

def getRes(A):

    tc = [0 for x in range(len(A)+1)]
    i = 1
    while(i < len(A)):
        tc[i] = min(A[i], A[i-1])+tc[i]
        i = i+2
    print tc


T = input()
for i in range(0, T):
    N = input()
    A = map(int, raw_input().split())
    getRes(A)

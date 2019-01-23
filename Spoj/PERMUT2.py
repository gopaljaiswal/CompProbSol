A = []
B = []


def getRes():
    for i in range(0, len(A)):
        if A[A[i]-1] != (i+1):
            return "not ambiguous"
    return "ambiguous"


while True:
    N = input()
    if N == 0:
        break
    else:
        A = map(int, raw_input().split())
        #print A
        print getRes()

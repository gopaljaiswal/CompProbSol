A=[]
def getBstitr(B, P):
    ans = -1
    low, high = 0, len(B)-1

    while(low <= high):
        mid = (low+high) >> 1
        # print str(low)+"    "+str(mid) + "   "+str(high)
        if mid == (P-1):
            ans = B[mid]
            break
        elif mid < P:
            low = mid+1
        else:
            high = mid-1
    return ans


def getRes(N, P):
    res = -1
    B = []
    for i in range(1, N+1):
        if i not in A:
            B.append(i)
    if P < len(B):
        res = getBstitr(B, P)
    print(res)


for __ in range(input()):
    N, K, P = map(int, raw_input().split())
    A = map(int, raw_input().split())
    getRes(A, N, P)

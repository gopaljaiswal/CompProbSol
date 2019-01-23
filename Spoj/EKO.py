def getRes(A, K):
    ans = 0
    low, high = A[0], A[len(A)-1]
    while low <= high:
        mid = (low+high) >> 1
        if getStable(A, mid) < K:
            high = mid-1
        else:
            low = mid+1
            if  mid > high :
                ans = mid
        # print str(low)+'   '+str(high)
    return ans


def getStable(A, mid):
    sum = 0
    i = len(A)-1
    while(i >= 0):
        if A[i] <= mid:
            break

        sum = sum+(A[i]-mid)
        i = i-1
    return sum


N, K = map(int, raw_input().split())
A = map(int, raw_input().split())
A.sort()
print getRes(A, K)

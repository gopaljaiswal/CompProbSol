def getRes(N):

    if N == 0:
        return 0
    res = 1
    low, high = 0, N
    while low <= high:
        mid = (low+high) >> 1
        if mid*mid > N:
            high = mid-1
        elif mid*mid <= N:
            low = mid+1
            res = mid
    return res


N =8
print getRes(N)
